param(
    [ValidateSet('Acquire', 'Status', 'Release')]
    [string] $Mode = 'Status',

    [guid] $LeaseId = [guid]::Empty,

    [int] $EditorPid,

    [string] $Map,

    [string[]] $Packages = @()
)

$ErrorActionPreference = 'Stop'
$projectRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot '../..')).Path
$project = (Resolve-Path -LiteralPath (Join-Path $projectRoot 'Lightning.uproject')).Path
$leaseRoot = Join-Path $projectRoot 'Saved/YIXI_Archive/InteractionMultiAgent/Locks'
$lockPath = Join-Path $leaseRoot 'unreal-editor.lock'
$ownerPath = Join-Path $leaseRoot 'unreal-editor-owner.json'

function Get-LiveLease {
    if (-not (Test-Path -LiteralPath $lockPath -PathType Leaf)) {
        return $null
    }

    try {
        $probe = [IO.File]::Open($lockPath, 'Open', 'ReadWrite', 'None')
        $probe.Dispose()
        return $null
    }
    catch [IO.IOException] {
        if (($_.Exception.HResult -band 0xffff) -ne 32) {
            throw
        }

        $owner = Get-Content -LiteralPath $ownerPath -Raw | ConvertFrom-Json
        if ($owner.Status -ne 'Held' -or $owner.Project -ne $project) {
            throw 'The lock exists but the current owner cannot be verified.'
        }
        return $owner
    }
}

if ($Mode -eq 'Status') {
    $lease = Get-LiveLease
    if ($lease) {
        $lease | ConvertTo-Json -Depth 3
    }
    else {
        [ordered]@{ Status = 'Free'; Project = $project } | ConvertTo-Json
    }
    return
}

if ($LeaseId -eq [guid]::Empty) {
    throw 'Acquire and Release require the same explicitly assigned LeaseId.'
}
$releasePath = Join-Path $leaseRoot "release-$($LeaseId.ToString('D')).signal"

if ($Mode -eq 'Release') {
    $lease = Get-LiveLease
    if (-not $lease -or $lease.LeaseId -ne $LeaseId.ToString('D')) {
        throw 'The requested lease is no longer held or belongs to another owner.'
    }
    [IO.File]::WriteAllText($releasePath, $LeaseId.ToString('D'))
    return
}

if ($EditorPid -le 0 -or $Map -notmatch '^/(Game|Engine)/' -or $Packages.Count -eq 0) {
    throw 'Acquire requires the verified Editor PID, current map and explicit package scope.'
}
$editor = Get-CimInstance Win32_Process -Filter "ProcessId=$EditorPid"
if (-not $editor -or $editor.Name -ne 'UnrealEditor.exe' -or
    -not $editor.CommandLine.Contains($project)) {
    throw 'The Editor process does not belong to this project.'
}

New-Item -ItemType Directory -Path $leaseRoot -Force | Out-Null
if (Test-Path -LiteralPath $releasePath) {
    throw 'This lease ID has already been used.'
}
$leaseLock = [IO.File]::Open($lockPath, 'OpenOrCreate', 'ReadWrite', 'None')
try {
    $owner = [ordered]@{
        Status   = 'Held'
        LeaseId  = $LeaseId.ToString('D')
        LeasePid = $PID
        Project  = $project
        EditorPid = $EditorPid
        Map      = $Map
        Packages = $Packages
        Started  = [DateTime]::UtcNow.ToString('o')
    }
    $owner | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath $ownerPath -Encoding utf8
    $owner | ConvertTo-Json -Depth 3
    while (-not (Test-Path -LiteralPath $releasePath -PathType Leaf)) {
        Start-Sleep -Milliseconds 350
    }
}
finally {
    if ($owner) {
        $owner.Status = 'Released'
        $owner['Released'] = [DateTime]::UtcNow.ToString('o')
        $owner | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath $ownerPath -Encoding utf8
    }
    $leaseLock.Dispose()
}

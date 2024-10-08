[CmdletBinding()]
param ([switch]$Build = $false)

process 
{
    # ======================================================================================================================================= #
    # Script Constants
    # ======================================================================================================================================= #
    $invokeLocation = $($pwd.Path)
    $buildRoot = $PSScriptRoot
    $buildOutput = [IO.Path]::Combine($buildRoot, "out", "sources")
    $exeLocation = [IO.Path]::Combine($buildOutput, "Sample.exe")

    try 
    {
        if ($Build)
        {
            powershell $([IO.Path]::Combine($buildRoot, "Invoke-CMakeBuild.ps1"))
        }

        Start-Process -FilePath $exeLocation -NoNewWindow -Wait
    }
    finally
    {
        cd $invokeLocation
    }
}

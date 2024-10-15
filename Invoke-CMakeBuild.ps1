[CmdletBinding()]
param ([switch]$Clean = $true)

process 
{
    # ======================================================================================================================================= #
    # Script Constants
    # ======================================================================================================================================= #
    $invokeLocation = $($pwd.Path)
    $buildRoot = $PSScriptRoot
    $buildOutput = [IO.Path]::Combine($buildRoot, "out")
    $buildOutputAlt = [IO.Path]::Combine($buildRoot, "build")

    try 
    {
        if (Test-Path $buildOutput)
        {
            Remove-Item -Recurse -Force $buildOutput | Out-Null
        }

        if (Test-Path $buildOutputAlt)
        {
            Remove-Item -Recurse -Force $buildOutputAlt | Out-Null
        }

        New-Item $buildOutput -Type Directory | Out-Null
        while (-not $(Test-Path $buildOutput)) { }
        cd $buildOutput
        
        cmake -G "MinGW Makefiles" $buildRoot
        make all
    }
    finally
    {
        cd $invokeLocation
    }
}

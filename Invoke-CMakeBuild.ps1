param ()

process 
{
    # ======================================================================================================================================= #
    # Script Constants
    # ======================================================================================================================================= #
    $invokeLocation = $($pwd.Path)
    $buildRoot = $PSScriptRoot
    $buildOutput = [IO.Path]::Combine($buildRoot, "out")

    try 
    {
        if (Test-Path $buildOutput)
        {
            Remove-Item -Recurse -Force $buildOutput | Out-Null
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

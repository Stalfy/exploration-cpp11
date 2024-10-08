# exploration-cpp11

## Setup

Install chocolatey
Install the latest Microsoft VC Redistributable

Run choco install cmake
Run choco install make
Run choco install mingw

## Using the .ps1 file for compiling

If the powershell environment restricts the execution: Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process
Build with the following command: .\Invoke-CMakeBuild.ps1
Run with the following command: .\Invoke-Main.ps1 [-Build]
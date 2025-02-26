@echo off

Start "usb device" /MIN ".\connect_usb.bat"

echo Setting up WSLENV...
setx WSLENV "MNTWSL:pu"

echo Running startup.sh in WSL...
wsl bash "%MNTWSL%/startup_docker.sh"

exit /b

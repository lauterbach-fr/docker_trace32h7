@echo off
setlocal

rem Define the USB VID:PID to look for
set "VIDPID1=0897:0005"
set "VIDPID2=0897:0004"
set "VIDPID3=2341:025b"
set "VIDPID4=2341:035b"

:loop

rem Try to find the first device with VID:PID1 or VID:PID2
set "FOUND1=0"
for /f "tokens=2 delims=:" %%i in ('usbipd list ^| findstr /i "%VIDPID1%"') do (
    rem Bind the device using VID:PID
    echo Device with VID:PID %VIDPID1% found. Binding it...
    usbipd bind -i %VIDPID1%

    rem Attach the device to WSL
    echo Attaching device with VID:PID %VIDPID1% to WSL...
    usbipd attach --wsl -i %VIDPID1%
    set "FOUND1=1"
)

for /f "tokens=2 delims=:" %%i in ('usbipd list ^| findstr /i "%VIDPID2%"') do (
    rem Bind the device using VID:PID
    echo Device with VID:PID %VIDPID2% found. Binding it...
    usbipd bind -i %VIDPID2%

    rem Attach the device to WSL
    echo Attaching device with VID:PID %VIDPID2% to WSL...
    usbipd attach --wsl -i %VIDPID2%
    set "FOUND1=1"
)

if %FOUND1%==0 echo No matching USB device found with VID:PID %VIDPID1% or %VIDPID2%.

rem Try to find the third device with VID:PID3 or VID:PID4
set "FOUND2=0"
for /f "tokens=2 delims=:" %%i in ('usbipd list ^| findstr /i "%VIDPID3%"') do (
    rem Bind the device using VID:PID
    echo Device with VID:PID %VIDPID3% found. Binding it...
    usbipd bind -i %VIDPID3%

    rem Attach the device to WSL
    echo Attaching device with VID:PID %VIDPID3% to WSL...
    usbipd attach --wsl -i %VIDPID3%
    set "FOUND2=1"
)

for /f "tokens=2 delims=:" %%i in ('usbipd list ^| findstr /i "%VIDPID4%"') do (
    rem Bind the device using VID:PID
    echo Device with VID:PID %VIDPID4% found. Binding it...
    usbipd bind -i %VIDPID4%

    rem Attach the device to WSL
    echo Attaching device with VID:PID %VIDPID4% to WSL...
    usbipd attach --wsl -i %VIDPID4%
    set "FOUND2=1"
)

if %FOUND2%==0 echo No matching USB device found with VID:PID %VIDPID3% or %VIDPID4%.

rem Wait for 2 seconds before retrying
timeout /t 2 /nobreak >nul
goto :loop

endlocal

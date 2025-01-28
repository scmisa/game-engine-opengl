@echo off
REM filepath: /C:/Users/your-username/opengl-mini/build.bat

REM Set the path to vcpkg
set VCPKG_ROOT=C:\Users\kuba-\vcpkg

REM Check if vcpkg is installed
if not exist "%VCPKG_ROOT%\vcpkg.exe" (
    echo Cloning vcpkg repository...
    git clone https://github.com/microsoft/vcpkg.git %VCPKG_ROOT%
    echo Bootstrapping vcpkg...
    cd %VCPKG_ROOT%
    .\bootstrap-vcpkg.bat
    cd %~dp0
)

REM Install necessary libraries
echo Installing necessary libraries...
%VCPKG_ROOT%\vcpkg.exe install glfw3:x64-windows
%VCPKG_ROOT%\vcpkg.exe install glad:x64-windows
%VCPKG_ROOT%\vcpkg.exe install glm:x64-windows

echo Dependencies installation complete.
pause
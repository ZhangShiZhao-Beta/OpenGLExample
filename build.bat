@echo off
setlocal enabledelayedexpansion

REM Define supported presets here
set SUPPORTED_PRESETS=vs2022-debug vs2022-release

REM Default preset
set PRESET=vs2022-debug
set CLEAN=0

REM Check arguments
if "%1"=="" goto run
if /I "%1"=="help" goto help

REM Check if first argument is in supported presets
set FOUND=0
for %%p in (%SUPPORTED_PRESETS%) do (
    if /I "%%p"=="%1" set FOUND=1
)
if "%FOUND%"=="0" (
    echo Error: unknown preset "%1"
    echo Supported presets are: %SUPPORTED_PRESETS%
    goto end
)
set PRESET=%1

REM Check second argument
if /I "%2"=="clean" set CLEAN=1
if /I "%2"=="help" goto help

:run
if %CLEAN%==1 (
    echo Deleting build directory build\%PRESET% ...
    rmdir /s /q build\%PRESET%
)

echo Configuring with preset %PRESET% ...
cmake --preset %PRESET%
if errorlevel 1 (
    echo CMake configure failed.
    goto end
)

echo Building with preset %PRESET% ...
cmake --build --preset build-%PRESET%
if errorlevel 1 (
    echo CMake build failed.
    goto end
)

echo Build completed successfully.
goto end

:help
echo Usage: build.bat [preset] [clean]
echo.
echo Supported presets:
for %%p in (%SUPPORTED_PRESETS%) do echo   %%p
echo.
echo Arguments:
echo   preset    Specify the configuration preset (default: vs2022-debug)
echo   clean     Optional: delete the build directory before building
echo   help      Show this help message
goto end

:end
endlocal

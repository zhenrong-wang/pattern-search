@echo off
setlocal

REM Define optimization levels
SET "OPTIMIZATION_LEVELS=O0 O1 O2 O3 Os Ofast"

REM Project Root
SET "ROOT="
FOR %%A IN ("..\..\") DO SET "ROOT=%%~dpA"

echo Proceeding in %ROOT%

REM Output directory
SET "OUTPUT_DIR=%ROOT%output"

REM Set C++ standard version
set "CPP_STANDARD=c++17"

REM Create output directory if it doesn't exist
mkdir "%OUTPUT_DIR%" 2>nul

REM Loop through optimization levels and compile
for %%i in (%OPTIMIZATION_LEVELS%) do (
    REM Compile with optimization level and C++ standard
    if "%%i"=="Ofast" (
        g++ %ROOT%*.cpp -o "%OUTPUT_DIR%\executable_%%i.exe" -I "%ROOT%" -%%i -ffast-math -std=%CPP_STANDARD%
    ) else (
        g++ %ROOT%*.cpp -o "%OUTPUT_DIR%\executable_%%i.exe" -I "%ROOT%" -%%i -std=%CPP_STANDARD%
    )

    REM Check if compilation was successful
    if errorlevel 1 (
        echo Compilation with optimization level %%i failed.
    ) else (
        echo Compilation with optimization level %%i successful. 
        echo Executable saved as %OUTPUT_DIR%\executable_%%i.exe
    )
)

REM Loop through optimization levels and compile [ Not Portable Version ]
for %%i in (%OPTIMIZATION_LEVELS%) do (
    REM Compile with optimization level and C++ standard
    if "%%i"=="Ofast" (
        g++ %ROOT%*.cpp -o "%OUTPUT_DIR%\executable_%%i_not_portable_version.exe" -%%i -march=native -ffast-math -std=%CPP_STANDARD%
    ) else (
        g++ %ROOT%*.cpp -o "%OUTPUT_DIR%\executable_%%i_not_portable_version.exe" -%%i -march=native -std=%CPP_STANDARD%
    )

    REM Check if compilation was successful
    if errorlevel 1 (
        echo Compilation with optimization level %%i and optimized for the current architecture failed.
    ) else (
        echo Compilation with optimization level %%i and optimized for the current architecture successful. 
        echo Executable saved as %OUTPUT_DIR%\executable_%%i_not_portable_version.exe
    )
)

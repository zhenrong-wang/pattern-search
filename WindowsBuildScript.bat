@echo off

REM Define optimization levels
set OPTIMIZATION_LEVELS=O0 O1 O2 O3 Os Ofast

REM Main.cpp file
set MAIN_FILE=main.cpp

REM Output directory
set OUTPUT_DIR=output

REM Set C++ standard version
set CPP_STANDARD=c++17

setlocal EnableDelayedExpansion

REM Create output directory if it doesn't exist
mkdir "%OUTPUT_DIR%" 2>nul

REM Loop through optimization levels and compile
for %%i in (%OPTIMIZATION_LEVELS%) do (
    REM Compile with optimization level and C++ standard
    if "%%i"=="Ofast" (
        g++ -o "%OUTPUT_DIR%\executable_%%i.exe" -%%i -ffast-math -std=%CPP_STANDARD% "%MAIN_FILE%"
    ) else (
        g++ -o "%OUTPUT_DIR%\executable_%%i.exe" -%%i -std=%CPP_STANDARD% "%MAIN_FILE%"
    )

    REM Check if compilation was successful
    if errorlevel 1 (
        echo Compilation with optimization level %%i failed.
    ) else (
        echo Compilation with optimization level %%i successful. Executable saved as %OUTPUT_DIR%\executable_%%i.exe
    )
)

REM Loop through optimization levels and compile [ Not Portable Version ]
for %%i in (%OPTIMIZATION_LEVELS%) do (
    REM Compile with optimization level and C++ standard
    if "%%i"=="Ofast" (
        g++ -o "%OUTPUT_DIR%\executable_%%i_not_portable_version.exe" -%%i -march=native  -ffast-math -std=%CPP_STANDARD% "%MAIN_FILE%"
    ) else (
        g++ -o "%OUTPUT_DIR%\executable_%%i_not_portable_version.exe" -%%i -march=native -std=%CPP_STANDARD% "%MAIN_FILE%"
    )

    REM Check if compilation was successful
    if errorlevel 1 (
        echo Compilation with optimization level %%i and optimized for the current architecture failed .
    ) else (
        echo Compilation with optimization level %%i and optimized for the current architecture successful. Executable saved as %OUTPUT_DIR%\executable_%%i_not_portable_version.exe
    )
)

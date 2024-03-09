@echo off

REM Main.cpp file
set MAIN_FILE=main.cpp

REM Output directory
set OUTPUT_DIR=output

REM C++ standard version
set CPP_STANDARD=c++17

REM Create output directory if it doesn't exist
mkdir "%OUTPUT_DIR%" 2>nul

REM Generate all warnings
echo Generating all warnings:
g++ -Wall -Wextra -Wformat-security -Wformat-signedness -Wredundant-decls -Wfloat-equal -Wduplicated-cond -Wshadow -pedantic -Werror -std=%CPP_STANDARD% -o "%OUTPUT_DIR%\%MAIN_FILE%_warnings.exe" "%MAIN_FILE%"

REM Check if compilation and analysis were successful
if %ERRORLEVEL% equ 0 (
    echo Compilation completed successfully.
) else (
    echo Compilation failed.
)
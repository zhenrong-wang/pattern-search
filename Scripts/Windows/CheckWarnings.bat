@echo off
setlocal

REM Project Root
SET "ROOT="
FOR %%A IN ("..\..\") DO SET "ROOT=%%~dpA"

echo Proceeding in %ROOT%

REM Output directory
SET "OUTPUT_DIR=%ROOT%output"

REM C++ standard version
set CPP_STANDARD=c++17

REM Create output directory if it doesn't exist
mkdir "%OUTPUT_DIR%" 2>nul

REM Generate all warnings
echo Generating all warnings:
g++ %ROOT%*.cpp -Wall -Wextra -Wformat-security -Wformat-signedness -Wredundant-decls -Wfloat-equal -Wduplicated-cond -Wshadow -pedantic -Werror -std=%CPP_STANDARD% -o "%OUTPUT_DIR%\main_warnings.exe"

REM Check if compilation and analysis were successful
if %ERRORLEVEL% equ 0 (
    echo Compilation completed successfully.
) else (
    echo Compilation failed.
)
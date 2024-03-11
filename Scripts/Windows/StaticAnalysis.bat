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

REM Compiling
echo Compiling:
clang++ %ROOT%*.cpp -std=%CPP_STANDARD% -o "%OUTPUT_DIR%\main.exe" 

echo Done Compiling!

REM Run static analysis
echo Running static analysis:
clang-tidy %ROOT%*.cpp --checks='clang-diagnostic-*,clang-analyzer-*,read*' -- -std=%CPP_STANDARD%

REM Check if compilation and analysis were successful
if %ERRORLEVEL% equ 0 (
    echo Static Analysis completed successfully.
) else (
    echo Static Analysis failed.
)
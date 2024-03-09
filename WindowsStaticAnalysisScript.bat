@echo off

REM Main.cpp file
set MAIN_FILE=main.cpp

REM Output directory
set OUTPUT_DIR=output

REM C++ standard version
set CPP_STANDARD=c++17

REM Create output directory if it doesn't exist
mkdir "%OUTPUT_DIR%" 2>nul

REM Compiling
echo Compiling:
clang++ -std=%CPP_STANDARD% -o "%OUTPUT_DIR%\%MAIN_FILE%.exe" "%MAIN_FILE%"
echo Done Compiling!
REM Run static analysis
echo Running static analysis:
clang-tidy "%MAIN_FILE%" --checks='clang-diagnostic-*,clang-analyzer-*,read*' -- -std=%CPP_STANDARD%

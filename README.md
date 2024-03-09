This is a non-strict benchmark to compare the performance of pattern search.

Purpose: Find a pattern in a string and return the first position.

Example: the pattern "aba" can be found in "kkaba" and return 2.

Methods:

  1. C-naive (brute)
  2. C-KMP (good)
  3. CPP - string.find() method.
     
Results Format: POSITION_FOUND:TIME_CONSUMED

Command Format: EXE_PATH FILE_PATH  E.g. `./a.out test.txt`

How-to:

1. clone or fork this repo.
2. g++ main.cpp -O3 -Wall (Options are optional)
3. ./a.out test.txt

On Windows:

1. Run the WindowsBuildScript.bat for building executables for different optimisations levels
2. The build file is customizable so choose your own standard version and the output folder


Static Analysis using Clang

1. Run WindowsStaticAnalysisScript.bat


**TODO:**

1. Read two files one containing the string to search for and the other contains the tests
2. Improve Tests to showcase the performance of each algorithm
3. Make Two Modes: Line-By-Line Mode && Whole Text Mode
4. add other algorithms
5. follow the static analysis guidelines and fix code accordingly
6. implement a new version of each algorithm where it uses arena allocation instead of malloc/calloc

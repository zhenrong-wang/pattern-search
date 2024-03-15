This is a non-strict benchmark to compare the performance of pattern search.

Purpose: Find a pattern in a string and return the first position.

Example: the pattern "aba" can be found in "kkaba" and return 2.

Methods:

  1. C-naive (brute)
  2. C-KMP (good)
  3. CPP - string.find() method.

**How-to:**

**Prerequisites:**

This code is cross-platform. However, you need [mingw-w64](https://sourceforge.net/projects/mingw-w64/) on Windows platform because some POSIX APIs are included. See the code for details.

**Main steps:**

1. clone or fork this repo.
2. g++ *.cpp -O3 -Wall (Options are optional)
3. ./a.out test.txt

*NOTE:*

  - I would rather try different optimisations flags to check which has the best performance: **-Os, -Ofast, -O2, -O3**.
  - The Static Analysis Script uses Clang

On Windows:

1. Run the Scripts/Windows/Build.bat for building executables for different optimisations levels
2. The build file is customizable so choose your own standard version and the output folder


Static Analysis using Clang

1. Run Scripts/Windows/StaticAnalysis.bat


**TODO:**

1. Read two files one containing the string to search for and the other contains the tests
2. Improve Tests to showcase the performance of each algorithm
3. Make Two Modes: Line-By-Line Mode && Whole Text Mode
4. add other algorithms
5. follow the static analysis guidelines and fix code accordingly
6. implement a new version of each algorithm where it uses arena allocation instead of malloc/calloc

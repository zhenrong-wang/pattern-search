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

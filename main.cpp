/*
 * Originally written by Zhenrong WANG zhenrongwang@live.com
 * This is a non-strict benchmark to compare the performance of pattern search.
 * Purpose: Find a pattern in a string and return the first position.
 * Example: the pattern "aba" can be found in "kkaba" and return 2.
 * Methods:
 *  1. C-naive (brute)
 *  2. C-KMP (good)
 *  3. CPP - string.find() method.
 * Results Format: POSITION_FOUND:TIME_CONSUMED
 */

#include <cstdio>
#include <ctime>
#include <fstream>

#include"algorithms.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide a file to read.\n");
        return 1;
    }
    FILE* file_p = fopen(argv[1], "r");
    if (file_p == nullptr) {
        printf("Failed to open %s.\n", argv[1]);
        return 3;
    }
    char buffer[65536] = "";
    string line_str;
    clock_t start, end;
    int result_c;
    size_t result_cpp;
    printf("\nThis is an non-strict benchmark to compare the performance of pattern search.\n");
    printf("Purpose: Find a pattern in a string and return the first position.\n");
    printf("Example: the pattern \"aba\" can be found in \"kkaba\" and return 2.\n");
    printf("Methods:\n");
    printf("\t1. C-naive (brute)\n\t2. C-KMP (good)\n\t3. CPP - string.find() method.\n");
    printf("Results: POSITION_FOUND:TIME_CONSUMED\n");
    printf("C - naive (brute):\t");
    while (!feof(file_p)) {
        memset(buffer, '\0', 65536);
        if (fgets(buffer, 65535, file_p) == nullptr) {
            break;
        }
        start = clock();
        result_c = contain_or_not(buffer, (char*)"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa world");
        end = clock();
        if (strlen(buffer) != 0) {
            printf("%d:%ld\t", result_c, end - start);
        }
    }
    putchar('\n');
    rewind(file_p);
    printf("C - KMP algorithm:\t");
    while (!feof(file_p)) {
        memset(buffer, '\0', 65536);
        if (fgets(buffer, 65535, file_p) == nullptr) {
            break;
        }
        start = clock();
        result_c = contain_or_not_kmp(buffer, (char*)"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa world");
        end = clock();
        if (strlen(buffer) != 0) {
            printf("%d:%ld\t", result_c, end - start);
        }
    }
    fclose(file_p);
    putchar('\n');

    printf("CPP - string.find():\t");
    ifstream file(argv[1]);
    if (!file.is_open()) {
        printf("Failed to open %s.\n", argv[1]);
        return 3;
    }
    while (getline(file, line_str)) {
        start = clock();
        result_cpp = line_str.find("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa world");
        end = clock();
        printf("%u:%ld\t", result_cpp, end - start);
    }
    putchar('\n');
    return 0;
}

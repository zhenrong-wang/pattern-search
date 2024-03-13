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

/* 
 * MACROS to adjust the benchmark rounds and steps.
 *      BM_LENGTH_START: the starting length of random strings
 *      BM_ROUNDS      : how many random_strings & random_substrings
 *      BM_INTERVAL    : subgroup with same length
 *      BM_LENGTH_STEP : random string length increment step
 * 
 * E.g. BM_ROUNDS = 8, BM_INTERVAL = 2, BM_LENGTH_STEP = 1
 *      The random strings would be like:
 *      1. xxxx
 *      2. xxxx // BM_INTERVAL = 2 means each subgroup includes 2 strings
 *      3. xxxxxxxx // BM_LENGTH_STEP = 1 means the length << 1 (X2)
 *      4. xxxxxxxx
 *      5. xxxxxxxxxxxxxxxx
 *      6. xxxxxxxxxxxxxxxx
 *      7. xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 *      8. xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx // Total strings = BM_ROUNDS
 */

#define BM_LENGTH_START 4
#define BM_ROUNDS       256
#define BM_INTERVAL     8
#define BM_LENGTH_STEP  1  

using namespace std;

int main(int argc, char** argv) { 

    benchmark_string bm_string[BM_ROUNDS];
    size_t i = 0, j;
    size_t length = BM_LENGTH_START;
    int result_c = 0;
    size_t result_cpp = -1;
    string cpp_randstr[BM_ROUNDS];
    string cpp_rand_substr[BM_ROUNDS];
    clock_t start, end;

    while(i < BM_ROUNDS) {
        if(create_benchmark_string(bm_string + i, length)!=0){
            printf(" Failed to create a benchmark string %ld .\n", i);
            for (j=0; j<i; j++) {
                empty_benchmark_string(bm_string + j);
            }
            return 3;
        }
        //display_benchmark_string(bm_string + i);
        construct_cpp_strings(bm_string + i, cpp_randstr + i, cpp_rand_substr + i);
        printf("GENERATED: ROUND: %ld\t RANDOM_STRING_LENGTH: %ld\n",i,length);
        i++;
        if(i % BM_INTERVAL == 0) {
            length = length << BM_LENGTH_STEP;
        }
    }
    printf(" START BENCHMARK ...\n");
    start = clock();
    for(i=0; i<BM_ROUNDS; i++) {
        result_c = contain_or_not(bm_string[i].random_string, bm_string[i].random_substring);
        //printf("::: %ld\t%ld\t: %ld\n", bm_string[i].random_string_length, bm_string[i].random_substring_position,result_c);
    }
    end = clock();
    printf("TIME CONSUMED: %ld\n", end - start);

    start = clock();
    for(i=0; i<BM_ROUNDS; i++) {
        result_c = contain_or_not_kmp(bm_string[i].random_string, bm_string[i].random_substring);
        //printf("::: %ld\t%ld\t: %ld\n", bm_string[i].random_string_length, bm_string[i].random_substring_position,result_c);
    }
    end = clock();
    printf("TIME CONSUMED: %ld\n", end - start);

    start = clock();
    for(i=0; i<BM_ROUNDS; i++) {
        result_cpp = cpp_randstr[i].find(cpp_rand_substr[i]);
        //printf("::: %ld\t: %ld\n", cpp_randstr[i].length(), result_cpp);
    }
    end = clock();
    printf("TIME CONSUMED: %ld\n", end - start);
    return 0;    

    /* Below is the original file_I/O based main function.

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
    return 0;*/
}
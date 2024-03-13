#ifndef ALGORITHMS_GUARD
#define ALGORITHMS_GUARD

#include <cstring>
#include <string>
#include <time.h>

typedef struct {
    char* random_string;
    size_t random_string_length;
    char* random_substring;
    size_t random_substring_length;
    size_t random_substring_position;
} benchmark_string;

/* Generate a random string. the length is the array length, actual string length = length-1 */
int generate_random_string(char random_string[], unsigned int length, int start_flag);

/* Generate a random substring from a given random string
 * Memory allocated. Any reciever must manage the allocated memory. */
char* generate_random_substring(const char* random_string, size_t* position, size_t* substring_length);

/* Empty a benchmark string */
void empty_benchmark_string (benchmark_string* bm_string);

/* create a benchmark string struct */
int create_benchmark_string (benchmark_string* bm_string, size_t random_string_length);

/* Display a benchmark string. */
void display_benchmark_string (benchmark_string* bm_string);

/* Construct cpp strings. */
int construct_cpp_strings(benchmark_string* bm_string, std::string* cpp_randstr, std::string* cpp_rand_substr);

/* function for KMP Algorithm */
size_t* create_next_array(char* string);

/* The KMP Algorithm */
int contain_or_not_kmp(char line[], char findkey[]);

/* The naive way (brute comparison) */
int contain_or_not(char line[], char findkey[]);

#endif

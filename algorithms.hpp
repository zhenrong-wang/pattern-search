#ifndef ALGORITHMS_GUARD
#define ALGORITHMS_GUARD

#include <cstring>
#include <string>
#include <time.h>

/* Generate a random string. the length is the array length, actual string length = length-1 */
int generate_random_string(char random_string[], unsigned int length, int start_flag);

/* Generate a random substring from a given random string
 * Memory allocated. Any reciever must manage the allocated memory. */
char* generate_random_substring(const char* random_string, size_t* position, size_t* substring_length);

/* function for KMP Algorithm */
size_t* create_next_array(char* string);

/* The KMP Algorithm */
int contain_or_not_kmp(char line[], char findkey[]);

/* The naive way (brute comparison) */
int contain_or_not(char line[], char findkey[]);

#endif

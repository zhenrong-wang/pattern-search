#ifndef ALGORITHMS_GUARD
#define ALGORITHMS_GUARD

#include <cstring>
#include <string>

/* The KMP Algorithm */
int contain_or_not_kmp(char line[], char findkey[]);

/* The naive way (brute comparison) */
int contain_or_not(char line[], char findkey[]);

#endif

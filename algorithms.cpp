#include"algorithms.hpp"

size_t* create_next_array(char* string) {
    size_t i = 0, j = 1, length = 0;
    if (string == nullptr || (length = strlen(string)) < 1) {
        return nullptr;
    }
    size_t* next_array = (size_t*)calloc(length, sizeof(size_t));
    if (next_array == nullptr) {
        return nullptr;
    }
    while (j < length) {
        if (string[j] == string[i]) {
            next_array[j] = next_array[j - 1] + 1;
            i++;
            j++;
        }
        else {
            if (!i) {
                next_array[j] = 0;
                j++;
            }
            else {
                i = next_array[i - 1];
            }
        }
    }
    return next_array;
}

int contain_or_not_kmp(char line[], char findkey[]) {
    size_t line_len = 0;
    size_t key_len = 0;
    size_t i = 0, j = 0;
    if (line == nullptr || findkey == nullptr) {
        return -1;
    }
    line_len = strlen(line);
    key_len = strlen(findkey);
    if (line_len < key_len || key_len == 0) {
        return -1;
    }
    size_t* next_array = create_next_array(findkey);
    if (next_array == nullptr) {
        return -1;
    }
    while (i < line_len) {
        if (line[i] == findkey[j]) {
            i++;
            j++;
            if (j == key_len) {
                free(next_array);
                return i - j;
            }
        }
        else {
            if (j != 0) {
                j = next_array[j - 1];
            }
            else {
                i++;
            }
        }
    }
    free(next_array);
    return -1;
}

/* The naive way (brute comparison) */
int contain_or_not(char line[], char findkey[]) {
    size_t line_len = 0;
    size_t key_len = 0;
    if (line == nullptr || findkey == nullptr) {
        return -5;
    }
    line_len = strlen(line);
    key_len = strlen(findkey);
    if (line_len < key_len) {
        return -1;
    }
    if (key_len == 0) {
        return -3;
    }
    size_t i = 0;
    while (i < line_len - key_len + 1) {
        if (memcmp(findkey, line + i, key_len) == 0) {
            return i;
        }
        else {
            i++;
        }
    }
    return -1;
}

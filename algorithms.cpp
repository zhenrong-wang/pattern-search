#include"algorithms.hpp"

int generate_random_string(char random_string[], unsigned int length, int start_flag){
    int i, rand_num;
    struct timespec current_time;
    unsigned int seed_num = 0;
    const char ch_table[96] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,<.>/?;:'\"[{}]|\\`~!@#$%^&*()-_=+ ";
    if( random_string == NULL ){
        return -1;
    }
    if( length < 2) {
        *(random_string + 0) = '\0';
        return -1;
    }
    memset(random_string,'\0',length);
    clock_gettime(CLOCK_MONOTONIC, &current_time);
    /* create a random seed num using the time */
    seed_num = (unsigned int) (current_time.tv_sec * 1000000000 + current_time.tv_nsec);
    srand(seed_num);
    if(start_flag == 0){
        rand_num = rand() % 52; /* Start with a letter, not 0~9 */
    }
    else{
        rand_num = rand() % 95; /* Start with any char */
    }
    *(random_string + 0) = *(ch_table + rand_num);
    i=1;
    while( i < length - 1 ){
        rand_num = rand() % 95;
        *(random_string + i) = *(ch_table + rand_num);
        i++;
    }
    return 0;
}

char* generate_random_substring(const char* random_string, size_t* position, size_t* substring_length){
    size_t full_length = strlen(random_string);
    struct timespec current_time;
    unsigned int seed_num = 0;
    char* substring = nullptr;

    clock_gettime(CLOCK_MONOTONIC, &current_time);
    /* create a random seed num using the time */
    seed_num = (unsigned int) (current_time.tv_sec*1000000000 + current_time.tv_nsec);
    srand(seed_num);
    *position = rand() % full_length;
    *substring_length = rand() % full_length;
    if((*position + *substring_length) > full_length) {
        *substring_length = full_length - *position;
    } 
    substring = (char*) calloc (*substring_length + 1, sizeof(char));
    if(substring == nullptr) {
        *position = -1;
        *substring_length = -1;
        return nullptr;
    }
    memcpy(substring, random_string + *position, *substring_length);
    return substring;
}

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

/* This is a driver to test random string and random substring generator. */
int main(){
    char randstr[512]="";
    char* substr = nullptr;
    size_t pos, sublen;
    generate_random_string(randstr, 512, 1);
    substr = generate_random_substring(randstr, &pos, &sublen);
    if(substr != nullptr) {
        printf("%s\t%ld\n%s\n%s\n%ld\n%ld\n",randstr, strlen(randstr), substr, randstr+pos, pos, sublen);
        free(substr);
        return 0;
    }
    return 1;
}

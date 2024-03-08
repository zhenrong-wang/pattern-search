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

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

size_t* create_next_array(char* string){
    size_t i=0,j=1,length=0;
    if(string==NULL||(length=strlen(string))<1){
        return NULL;
    }
    size_t* next_array=(size_t*)calloc(length,sizeof(size_t));
    if(next_array==NULL){
        return NULL;
    }
    while(j<length){
        if(string[j]==string[i]){
            next_array[j]=next_array[j-1]+1;
            i++;
            j++;
        }
        else{
            if(!i){
                next_array[j]=0;
                j++;
            }
            else{
                i=next_array[i-1];
            }
        }
    }
    return next_array;
}

int contain_or_not_kmp(char line[], char findkey[]){
    size_t line_len=0;
    size_t key_len=0;
    size_t i=0,j=0;
    if(line==NULL||findkey==NULL){
        return -1;
    }
    line_len=strlen(line);
    key_len=strlen(findkey);
    if(line_len<key_len||key_len==0){
        return -1;
    }
    size_t* next_array=create_next_array(findkey);
    if(next_array==NULL){
        return -1;
    }
    while(i<line_len){
        if(line[i]==findkey[j]){
            i++;
            j++;
            if(j==key_len){
                free(next_array);
                return i-j;
            }
        }
        else{
            if(j!=0){
                j=next_array[j-1];
            }
            else{
                i++;
            }
        }
    }
    free(next_array);
    return -1;
}

/* The naive way (brute comparison) */
int contain_or_not(char line[], char findkey[]){
    size_t line_len=0;
    size_t key_len=0;
    if(line==NULL||findkey==NULL){
        return -5;
    }
    line_len=strlen(line);
    key_len=strlen(findkey);
    if(line_len<key_len){
        return -1;
    }
    if(key_len==0){
        return -3;
    }
    size_t i=0;
    while(i<line_len-key_len+1){
        if(memcmp(findkey,line+i,key_len)==0){
            return i;
        }
        else{
            i++;
        }
    }
    return -1;
}

int main(int argc, char** argv){
    if(argc<2){
        printf("Please provide a file to read.\n");
        return 1;
    }
    FILE* file_p=fopen(argv[1],"r");
    if(file_p==NULL){
        printf("Failed to open %s.\n",argv[1]);
        return 3;
    }
    char buffer[65536]="";
    string line_str;
    clock_t start,end;
    int result_c;
    size_t result_cpp;
    printf("\nThis is an non-strict benchmark to compare the performance of pattern search.\n");
    printf("Purpose: Find a pattern in a string and return the first position.\n");
    printf("Example: the pattern \"aba\" can be found in \"kkaba\" and return 2.\n");
    printf("Methods:\n");
    printf("\t1. C-naive (brute)\n\t2. C-KMP (good)\n\t3. CPP - string.find() method.\n");
    printf("Results: POSITION_FOUND:TIME_CONSUMED\n");
    printf("C - naive (brute):\t");
    while(!feof(file_p)){
        memset(buffer,'\0',65536);
        if(fgets(buffer,65535,file_p)==NULL){
            break;
        }
        start=clock();
        result_c=contain_or_not(buffer,(char*)"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa world");
        end=clock();
        if(strlen(buffer)!=0){
            printf("%d:%ld\t",result_c,end-start);
        }
    }
    putchar('\n');
    rewind(file_p);
    printf("C - KMP algorithm:\t");
    while(!feof(file_p)){
        memset(buffer,'\0',65536);
        if(fgets(buffer,65535,file_p)==NULL){
            break;
        }
        start=clock();
        result_c=contain_or_not_kmp(buffer,(char*)"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa world");
        end=clock();
        if(strlen(buffer)!=0){
            printf("%d:%ld\t",result_c,end-start);
        }
    }
    fclose(file_p);
    putchar('\n');

    printf("CPP - string.find():\t");
    ifstream file(argv[1]);
    if(!file.is_open()){
        printf("Failed to open %s.\n",argv[1]);
        return 3;
    }
    while(getline(file,line_str)){
        start=clock();
        result_cpp=line_str.find("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa world");
        end=clock();
        printf("%ld:%ld\t",result_cpp,end-start);
    }
    putchar('\n');
    return 0;
}

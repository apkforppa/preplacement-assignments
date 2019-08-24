#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str1 = (char*) malloc(sizeof(char)*1024);
    char *str2 = (char*) malloc(sizeof(char)*1024);

    printf("Enter string 1: ");
    fgets(str1, 1024, stdin);
    printf("Enter string 2: ");
    fgets(str2, 1024, stdin);

    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';

    for(int i=0; i<1024; i++) {
        str1[i] = tolower(str1[i]);
        str2[i] = tolower(str2[i]);
    }

    int char_counts_str1[128];
    int char_counts_str2[128];

    for(int i=0; i<128; i++) {
        char_counts_str1[i] = 0;
        char_counts_str2[i] = 0;
    }

    /*
    for(int i=65; i<=90; i++) {
        for(int j=0; j<strlen(str1); j++) {
            if((int) str1[j] == i) {
                char_counts_str1[i] ++;
            }
        }
    }
    */

    for(int i=97; i<=122; i++) {
        for(int j=0; j<strlen(str1); j++) {
            if((int) str1[j] == i) {
                char_counts_str1[i] ++;
            }
        }
    }

    /*
    for(int i=65; i<=90; i++) {
        for(int j=0; j<strlen(str2); j++) {
            if((int) str2[j] == i) {
                char_counts_str2[i] ++;
            }
        }
    }
    */

    for(int i=97; i<=122; i++) {
        for(int j=0; j<strlen(str2); j++) {
            if((int) str2[j] == i) {
                char_counts_str2[i] ++;
            }
        }
    }

    int strings_match = 1;

    /*
    for(int i=65; i<=90; i++) {
        if(char_counts_str1[i] != char_counts_str2[i])
            strings_match = 0;
    }
    */

    for(int i=97; i<=122; i++) {
        if(char_counts_str1[i] != char_counts_str2[i])
            strings_match = 0;
    }

    if(strings_match)
        printf("The strings are anagrams of each other\n");
    else
        printf("The strings are not anagrams of each other\n");
    

    return 0;
}

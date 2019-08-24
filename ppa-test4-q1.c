#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char c;
    int first_line = 1;
    char buffer[1024];
    char input_buffer[256][1024];
    int i = 0, j = 0, repeat = 0;

    while((c = getchar()) != EOF) {
        buffer[i] = c;
        i++;
        if(c == '\n') {
            if(first_line) {
                // save number
                repeat = atoi(buffer);
                first_line = 0;
            } else {
                strcpy(input_buffer[j], buffer);
                j++;
            }
            i = 0;
        }
    }
    
    for(int m=0; m<repeat; m++) {
        for(int k=(j-1); k>=0; k--) {
            for(int l=(strlen(input_buffer[k])-1); l>=0; l--) {
                    printf("%c", input_buffer[k][l]);
            }
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}

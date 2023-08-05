#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Sample input: Learning C is fun
//Sample output:Learning
//              C
//              is
//              fun
int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //start splitting
    //first split: pointer is at the beginning of s
    //strtok places \0 at the end of each split
    //after splitting: string looks like 'Learning\0C is fun'
    //next split will be at the POSITION of \0 (position of NULL)
    char* token = strtok(s, " ");
    while(token){   //keep splitting while token is not NULL
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}
//good read: https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
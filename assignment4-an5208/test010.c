#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[1024];
    int i, j;
    char str[sizeof(int)];
    char char2[sizeof(char)];
    scanf("%[^\n]", s);

    int freq[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char int_char;
    for (i = 0; i < strlen(s); i++ ){
        //printf("%c ", s[i]);
        for(j = 0; j < 10; j++){
            int_char = j + '0';
            if(int_char == s[i]){
                freq[j] ++;
            }
        }
    }
    for(i = 0; i < 10; i++){
        printf("%d ", freq[i]);
    }
    
    return 0;
}

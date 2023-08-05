#include "stdio.h"
#define LENGTH 5
#include "string.h"

int main(){
    char array[LENGTH+1];
    while (1){
        printf("Enter some characters: ");
        
        fgets(array, LENGTH+1, stdin);
        if(strcmp(array,"\n")==0){
            printf("Nothing is entered. This will now stop.");
            break;
        }
        if(array[strlen(array)-1]=='\n'){
            array[strlen(array)-1] = '\0';
        }
        printf("Entered: %s , length: %u\n", array, strlen(array));
        fflush(stdin); // get rid of the rest of the input, if any
    }
}
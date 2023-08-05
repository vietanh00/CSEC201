#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define LENGTH 16
// The program would read the user's word and stop after 16 character 
// or when the word is over 
// if the word is too short, it will be padded

// This method doesn't do anything unless the string's length is shorter than 16
char* padding(char* dst, char* str){
    int len = strlen(str);
    char temp[LENGTH];
    dst = (char*) malloc(30);
    for (int i = 0; i < len; i++){
        temp[i] = str[i];
    }
    for (int i = 0; i < LENGTH - len; i++){
        temp[len+i] = '_';
    }
    strcpy(dst, temp);
    return dst;
}
char* decrypt(char* dst, char* str){
    // This array stores the order of the decrypted string
    int de_order[LENGTH] = {6, 11, 9, 5, 2, 8, 15, 12, 1, 13, 3, 0, 14, 10, 4, 7};
    char temp[LENGTH];
    dst = (char*) malloc(17);
    for (int i = 0; i < LENGTH; i++){
        temp[i] = str[de_order[i]];
    }
    strcpy(dst, temp);
    return dst;
}
char* encrypt(char* dst, char* str){
    // This array stores the order of the encrypted string
    int en_order[LENGTH] = {11, 8, 4, 10, 14, 3, 0, 15, 5, 2, 13, 1, 7, 9, 12, 6};
    char temp[LENGTH];
    dst = (char*) malloc(17);
    for (int i = 0; i < LENGTH; i++){
        temp[i] = str[en_order[i]];
    }
    strcpy(dst, temp);
    return dst;
}

int main(){
    bool going = true;
    while (going == true){
        char str0[LENGTH];
        printf("Enter a string, or none to stop:");
        fgets(str0, LENGTH + 1, stdin);
        if(strcmp(str0, "\n") == 0){
            printf("The program will now stop.");
            going = false;
            break;
        }
        if(str0[strlen(str0)-1]=='\n'){
            str0[strlen(str0)-1] = '\0';
        }

        char *padded = padding(padded, str0); //doesnt do anything if length is >= 16
        //strcpy(padded, usermsg);
        padded[LENGTH] = '\0';
        printf("Padded text: %s \n", padded);
        
        char *encrypted= encrypt(encrypted, padded);
        encrypted[LENGTH] = '\0';
        printf("Encrypted text: %s \n", encrypted);

        char temp[LENGTH];
        strcpy(temp, encrypted);
        temp[LENGTH] = '\0';
        
        char *decrypted= decrypt(decrypted, temp);
        decrypted[LENGTH] = '\0';
        printf("Decrypted text: %s \n", decrypted);
        int compare = strcmp(decrypted, padded);
        if(compare == 0){
            printf("Decrypted text == padded text? false \n");
        }
        else{
            printf("Decrypted text == padded text? true\n");
        }
        fflush(stdin);
    }
}
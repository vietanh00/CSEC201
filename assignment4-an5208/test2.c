#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char vec[] = {"ls", "ls", "-al", NULL};
    if(execvp(vec[0], vec) < 0){
        printf("Exec Fails.\n");
    }
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int child_num = 3;
    //no data corruption
    for(int i = 0; i<child_num; i++){

        pid_t result = fork();
        if (result < 0){
            printf("Fork failed.\n");
            exit(1);
        }
        else if (result == 0){
            //child process 
            printf("im child %d\n", getpid());
            printf("parent is %d\n", getppid());

            //if we have exit then no need for else
            exit(0);
        }

        //parent code
        printf("my child is %d\n", result);
        //wait here will allow all children to finish running
        wait(NULL);
        //wait(result, NULL, 0); //this also works
    }
        printf("im parent %d\n", getpid());
        //if wait here, wait(NULL) will only wait for one child
}
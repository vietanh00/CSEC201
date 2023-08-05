#include <stdio.h>
#include <unistd.h>
//#include <sys/unistd.h>
#include <stdlib.h>
int main(){
    //child n parent do not share i
    //no data corruption
    int i = 0;

    pid_t result = fork();
    if (result < 0){
        printf("Fork failed.\n");
        exit(1);
    }
    else if (result == 0){
        //child process 
        printf("im child %d\n", getpid());
        
        //sometimes this gets 1 -- init pid
        //this happens when the parent finishes too quickly
        printf("parent is %d\n", getppid());

        while(i < 10000){
            i+=1;
        }
        printf("child: i = %d\n", i);
        //if we have exit then no need for else
        exit(0);
    }
    
    //parent process
    //as soon as parent finishes, the shell prompts
    //child would appear after, if any
    printf("im parent %d\n", getpid());
    printf("child is %d\n", result);
    while (i>-100){
        i--;
    }
    printf("parent: i = %d", i);
    //wait for a child to finish before terminating
    wait(NULL);    
    
    
}
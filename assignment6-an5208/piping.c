#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    //pipe for child to send to parent
    int fd[2];
    pipe(fd);

    //pipe for parent to send to child
    int fd2[2];
    pipe(fd2);

    pid_t result = fork();
    if (result < 0){
        printf("Fork failed.\n");
        exit(1);
    }
    if (result == 0){   
        printf("im child %d\n", getpid());
        printf("parent is %d\n", getppid());

        //child will use fd[1] to write
        close(fd[0]); //close unused end
        int num1 = 15;
        int num2 = 20;
        write(fd[1], &num1, sizeof(int));
        write(fd[1], &num2, sizeof(int));
        
        //child uses fd2[0] to read
        close(fd2[1]); //close unused end
        int sum;
        read(fd2[0], &sum, sizeof(int));
        print("child got sum = %d\n", sum);
        exit(0);
    }

    printf("im parent %d\n", getpid());
    printf("child is %d\n", result);
    
    //use fd[0] to read
    close(fd[1]); //close unused end
    int num1, num2;
    //read num1 from child and put it at this num1
    read(fd[0], &num1, sizeof(int));
    read(fd[0], &num2, sizeof(int));
    print("parent says num1 = %d , num2 = %d\n", num1, num2);

    //parent starts sending sum using fd2[1]
    int sum = num1 + num2;
    close(fd2[0]);
    write(fd2[1], &sum, sizeof(int));
    //wait for a child to finish before terminating
    wait(NULL);    
    
    
}
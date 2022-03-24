//Ques-1.Test whether the process(exec() system call) that replaces old program data , will inherit the fds or not.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    printf("PID of L1a.c = %d\n", getpid());
    char *args[] = {"Hello", "C" , "programming", NULL};
    execv("./L1b",args);
    printf("Back to L1a.c");
    
    return 0;
}    

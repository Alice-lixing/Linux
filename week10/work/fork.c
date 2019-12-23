#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
    pid_t pid;
    if((pid = fork()) < 0)
    {
        printf("fork error!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("in the child process!\n");
    }
    else
    {
        printf("in the parrent process!\n");
    }
    exit(0);
}

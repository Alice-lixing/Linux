#include<sys/types.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 

int gvar = 2; 
int main(void) {     
	pid_t pid;
    int var = 5;
    printf("process id:%ld\n",(long)getpid());
    printf("gvar = %d var = %d\n",gvar,var);
    if((pid = vfork()) < 0)
	{
        printf("error!\n");
        return 1;
    }
    else if(pid == 0)
    {
        gvar--;
        var++;
        printf("the child process id:%ld\ngvar = %d var = %d\n",(long)getpid(),gvar,var);
        _exit(0);
    }
    else
    {
        printf("the parrent process id:%ld\ngvar = %d var = %d\n",(long)getpid(),gvar,var);
        return 0;
    }
}

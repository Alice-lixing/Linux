#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	int fd;
	int i=1;
	int status;
	char *ch1="advanced";
	char *ch2=" programming";
	char *ch3=" int the unix Environment";

	fd=open("test.txt",O_RDWR|O_CREAT,0644);
	if(fd==-1)
	{
		printf("open or creat file error:%m\n");
		exit(-1);
	}
	write(fd,ch1,strlen(ch1));
	pid=fork();
	if(pid==-1)
	{
		printf("error fork\n");
		exit(-1);
	}
	else if(pid==0)
	{
		i=2;
		printf("in child process\n");
		printf("i=%d\n",i);
		if(write(fd,ch2,strlen(ch2))==-1)
		{
			printf("child write error:%m\n");
			exit(-1);
		}
	}
	else
	{
		sleep(1);
		printf("in parent process\n");
		printf("i=%d\n",i);
		if(write(fd,ch3,strlen(ch3))==-1)
		{
			printf("parent write error:%m\n");
			exit(-1);
		}
		wait(&status);
	}
	return 0;
}

#include "my.h"

int g=10;
int main()
{
	pid_t pid;
	int i;
	static int k=20;
	printf("test:pid=%d,&g=%16p,&g=%16p\n",getpid(),&k,&g);
	for(i=0;i<10;i++)
	{
		printf("test:g=%d,k=%d\n",g++,k++);
	}
	return 0;
}

#include "my.h"

void fun()
{
	printf("call sig callback function\n");
	printf("mask block.\n");
	signal(2,SIG_DFL);
}

int main()
{
	int i;
	sigset_t set,pendeset;
	struct sigaction act;
	(void)signal(2,fun);
	if(sigemptyset(&set)<0)
		perror("init set failed!\n");
	if(sigaddset(&set,2)<0)
		perror("add set failed!\n");
	if(sigprocmask(SIG_BLOCK,&set,NULL)<0)
		perror("pro set failed!\n");
	else
	{
		for(i=0;i<10;i++)
		{
			printf("%d:message send!\n",i);
			//kill(getpid(),2);
			raise(2);
			sleep(1);
		}
	}
	if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
		perror("proc unset failed!\n");
}

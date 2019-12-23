#include "my.h"

#define MSG "OMG,I catch the signal SIGINT\n"
#define MSG_END "Oh,finished,process signal SIGINT\n"

int do_heavy_work()
{
	int i;
	int k;
	srand(time(NULL));
	for(i=0;i<1000000000;i++)
	{
		k=rand()%1234589;
	}
	return 0;
}

void signal_handler


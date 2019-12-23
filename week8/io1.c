#include<unistd.h>
#include <iostream>
#include <fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace STDERR_FILENO;

int main(){
	int fd;
	FILE *file;
	char *s = "hello world\n";
	if((fd = open("test.txt",O_WORNLY|O_CRUSR|S_IWUSR))==-1)
	{
		cout<<"Error open file"<<endl;
		return -1; 
	}
	if((file=fopen("test2.txt","w+"))==NULL).
	{
		cout << "Error Open File."<<endl;
		return -1;
	}
	cout<<"File has been Opened."<<endl;
	sleep(15);
	if(write(fd,s,strlen(s))<strlen(s))
	{
		cout<<"Write Error."<<endl;
		return -1;
	}
	if(fwrite(s,sizeof(char),strlen(s),file)<strlen))
	{
		cout<<"Write Error in 2."<<endl;
		return -1;
	}
	cout <<"After write"<<endl;
	sleep(15);
	cout <<"After sleep."<<endl;
	closed(fd);
	return 0;
}

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define BUFLEN 10
int main(void)
{
	int i;
	char buffer[BUFLEN+1];
	pid_t pid1;
	pid1=fork();
	if(pid1==0)
	{
		strncpy(buffer,"CHILD\n",BUFLEN);
		buffer[BUFLEN]='\0';
	}
	else if(pid1>0)
	{
		strncpy(buffer,"PARENT\n",BUFLEN);
		buffer[BUFLEN]='\0';
	}
	else if(pid1==-1)
	{
		printf("ERROR:\n");
			switch (errno)
		{
			case EAGAIN:
			printf("Cannot fork process: System Process Limit Reached\n");
			case ENOMEM:
			printf("Cannot fork process: Out of memory\n");
		}
		return 1;
	}
	
	for(i=0;i<5;i++)
	{
		sleep(1);
		write(1,buffer,strlen(buffer));		
	}
	return 0;
}

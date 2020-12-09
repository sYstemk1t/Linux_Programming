#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(int argc,char* args[])
{
	pid_t pid = fork();
	if(pid<0)		//检查fork失败
	{
		perror("fork error");
		return -1;
	}
	else if(pid>0)
	{
		sleep(5);
		printf("parent pid = %d fpid = %d\n",getpid(),getppid());
		
	}
	else if(pid==0)
	{
		return 0;
		printf("child pid = %d fpid = %d\n",getpid(),getppid());	
		sleep(20);
		printf("child pid = %d fpid = %d\n",getpid(),getppid());
	}
}

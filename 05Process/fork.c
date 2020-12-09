#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(int argc,char* args[])
{
	printf("begin fork for pid = %d\n",getpid());	
	//pid_t fork(void);
	pid_t pid = fork();
	if(pid<0)		//检查fork失败
	{
		perror("fork error");
		return -1;
	}
	else if(pid>0)
	{
		
		printf("parent pid = %d fpid = %d\n",getpid(),getppid());
		sleep(5);
		return 1;
	}
	else if(pid==0)
	{
		
		printf("child pid = %d fpid = %d\n",getpid(),getppid());
		
	}
	printf("fork ends for pid = %d\n",getpid());
	return 0;
}

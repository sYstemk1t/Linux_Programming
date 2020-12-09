#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int g_var = 99;
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
		g_var = 100;
		printf("parent pid = %d fpid = %d\n",getpid(),getppid());
		
		
	}
	else if(pid==0)
	{
		sleep(10);	
		printf("child pid = %d fpid = %d\n",getpid(),getppid());
		printf("child %d\n",g_var);
	}
	return 0;
}

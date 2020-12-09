#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sighandler(int signo)
{
	printf("signo = %d",signo);
}

int main(int argc,char* args[])
{
	pid_t pid;
	int i = 0;
	pid = fork();
	signal(SIGCHLD,sighandler);
	if(pid<0)
	{
		perror("fork error");
		return -1;
	}
	else if(pid>0)
	{
		printf("father porcess pid = %d,child pid = %d",getpid(),pid);
		while(1)
		{
			sleep(1);
		}
	
	}
	else
	{
		printf("father porcess pid = %d,child pid = %d",getppid(),getpid());
        while(1)
        {   
            sleep(1);
        }
	}
	return 0;
}

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
		
		printf("parent pid = %d fpid = %d\n",getpid(),getppid());
		
	}
	else if(pid==0)
	{
		
		printf("child pid = %d fpid = %d\n",getpid(),getppid());
		//execl("./hello","hello","hello","hello","hello",NULL);
		//execlp("./hello","hello","-l",NULL);
		execlp("ls","ls","-l",NULL);
		//execl("/bin/ls","ls","-l",NULL);
		perror("execl error");
	}
	return 0;
}

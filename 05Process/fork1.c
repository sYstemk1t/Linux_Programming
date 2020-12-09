#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(int argc,char* args[])
{
	int i = 0;
	//pid_t fork(void);
	for(;i<3;i++)
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
			//sleep(5);
			
		}
		else if(pid==0)
		{
		
			printf("child pid = %d fpid = %d\n",getpid(),getppid());
		
		}
	if(i==0)
	{
		printf("i = %d pid = %d\n",i,getpid());
		
	}
	if(i==1)
    {
        printf("i = %d pid = %d\n",i,getpid());
		
    }
	if(i==2)
    {
        printf("i = %d pid = %d\n",i,getpid());
		
    }
	if(i==3)
    {
        printf("i = %d pid = %d\n",i,getpid());
		
    }
	}
		
	return 0;
}

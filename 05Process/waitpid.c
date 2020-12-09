#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>
int main(int argc,char* args[])
{
	pid_t pid = fork();
	pid_t w;
	int status;
	if(pid<0)		//检查fork失败
	{
		perror("fork error");
		return -1;
	}
	else if(pid>0)
	{
		printf("parent pid = %d fpid = %d\n",getpid(),getppid());
		w = waitpid(-1,&status,WNOHANG);	//-1标识等待任意子进程
		printf("wpid = %d\n",w);
		if(w>0)
		{
				if(WIFEXITED(status))//WIFEXITED宏的释义： wait if exit ed
                {
                    printf("子进程返回信息码:%d\n",WEXITSTATUS(status));
                }
                else if(WIFSIGNALED(status))
                {
                    printf("子进程信号中断返回信息码:%d\n",WTERMSIG(status));
                }
                else if(WIFSTOPPED(status))
                {
                    printf("子进程暂停返回信息码:%d\n",WSTOPSIG(status));
                }
                else
                {
                    printf("其他退出信息！\n");
                }
		}
		else if(w==0)
		{
			printf("child is living,wpid = %d\n",w);
		}
		else if(w==-1)
		{
			printf("no child is living,wpid = %d\n",w);
			
		}
		sleep(100);
	}
	else if(pid==0)
	{
		
		printf("child pid = %d fpid = %d\n",getpid(),getppid());
		//abort();
		//return 9;
		//exit(0);
		sleep(5);
	}
	return 0;
}

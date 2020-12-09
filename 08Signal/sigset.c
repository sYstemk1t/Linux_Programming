#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
void sighandler(int signo)
{
	printf("signo = %d\n",signo);
}

int main()
{
	signal(SIGINT,sighandler);
	//定义信号集
	sigset_t set;
	//初始化信号集
	sigemptyset(&set);

	//将SIGINT SIGQUIT加入到set合集中
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGQUIT);
	

	//将set集合中的SIGINT SIGQUIT
	sigprocmask(SIG_BLOCK,&set,NULL);
	int i = 0;
	int j = 1;
	sigset_t pending;
	while(1)
	{
		//获得未决信号集
		
		sigemptyset(&pending);
		sigpending(&pending);

		for(i=1;i<32;i++)
		{
			if(sigismember(&pending,i) == 1)
			{
				printf("1");		
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
		//循环十次，解除阻塞
		if(j++%10==0)
		{
			sigprocmask(SIG_UNBLOCK,&set,NULL);
		}
		else
		{
			sigprocmask(SIG_BLOCK,&set,NULL);
		}
		sleep(1);
	}
	return 0;
}

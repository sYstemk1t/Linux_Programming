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
	sleep(3);
}

int main(int argc,char* args[])
{
	//int sigaction(int signum, const struct sigaction *act,
    //                 struct sigaction *oldact);
	struct sigaction act;
	act.sa_handler = sighandler;	//信号处理函数
	sigemptyset(&act.sa_mask);		//阻塞信号
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags = 0;
	sigaction(SIGINT,&act,NULL);
	signal(SIGQUIT,sighandler);
	while(1)
	{
		sleep(1);
	}
	return 0;
}

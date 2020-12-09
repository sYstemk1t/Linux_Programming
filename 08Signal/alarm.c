//alarm函数
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
	signal(SIGALRM,sighandler);
	//unsigned int alarm(unsigned int seconds);
	int ret = alarm(5);
	printf("ret = %d\n",ret);
	sleep(2);
	signal(SIGALRM,sighandler);
	ret = alarm(2);
	alarm(0);
	printf("ret = %d\n",ret);
	sleep(10);
	return 0;
}

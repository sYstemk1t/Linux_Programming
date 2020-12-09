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
	alarm(1);
	int i = 0;
	while(1)
	{
		printf("i = %d",i++);
	}
	return 0;
}

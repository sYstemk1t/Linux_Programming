//kill函数
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
int main()
{
	//int kill(pid_t pid, int sig);
	abort();
	printf("hello world\n");
	return 0;
}

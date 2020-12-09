#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

void myfunc(int signo)
{
	//打开文件
	int fd = open("time.txt",O_RDWR | O_CREAT |O_APPEND, 0755);
	time_t t;
	if(fd<0)
	{
		return ;
	}
	//获取时间
	time(&t);
	//转换
	char *p = ctime(&t);
	//写入
	write(fd,p,strlen(p));
	
	close(fd);
	return ;
}
int main()
{
	//创建父进程
	pid_t pid = fork();
	if(pid<0 || pid>0)
	{
		exit(1);
	}
	
	//子进程调用setsid函数
	//pid_t setsid(void);
	setsid();
	//改变工作目录
	//int chdir(const char *path);
	chdir("/home/systemk1t/linux");

	//改变文件掩码
	//mode_t umask(mode_t mask);
	umask(0000);
	
	//关闭文件描述符
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	//核心操作
	struct sigaction act;
	act.sa_handler = myfunc;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM,&act,NULL);
	//设置时钟
	struct itimerval tm;
	tm.it_interval.tv_sec = 2;
	tm.it_interval.tv_usec = 0;
	tm.it_value.tv_sec = 3;
	tm.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL,&tm,NULL);
	while(1)
	{
		sleep(1);
	}
	return 0;
}

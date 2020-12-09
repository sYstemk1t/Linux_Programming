#include <pthread.h>
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
void *mythread(void *arg)
{
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
}

int main()
{
	//定义pthread_attr_t类型的变量
	pthread_attr_t attr;
	//初始化
	pthread_attr_init(&attr);
	//设置attr为分离属性
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	//创建线程
	pthread_t thread;
	int ret = pthread_create(&thread,&attr,mythread,NULL);
	if(ret!=0)
	{
		printf("pthread_create error %s\n",strerror(errno));
		return -1;
	}
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
	//释放线程属性
	pthread_attr_destroy(&attr);
	ret = pthread_join(thread,NULL);
	if(ret!=0)
	{
		printf("pthread_join thread error = %s\n",strerror(ret));
	}
	sleep(1);
	return 0;
}


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
	while(1)
	{
		int a;
		int b;
	
		pthread_testcancel();		//设置取消点
	}
}

int main()
{
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);
	//创建线程
	pthread_t thread;
	int ret = pthread_create(&thread,NULL,mythread,NULL);
	if(ret!=0)
	{
		printf("pthread_create error %s\n",strerror(errno));
		return -1;
	}
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
	//取消子线程
	pthread_cancel(thread);
	pthread_join(thread,NULL);

	sleep(1);
	return 0;
}


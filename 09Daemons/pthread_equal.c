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

void *mythread1(void *arg)
{
    printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
}

int main()
{
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);
	//创建线程
	pthread_t thread;
	pthread_t thread1;
	int ret = pthread_create(&thread,NULL,mythread,NULL);
	int ret1 = pthread_create(&thread1,NULL,mythread1,NULL);
	if(ret!=0)
	{
		printf("pthread_create error %s\n",strerror(errno));
		return -1;
	}
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
	if((pthread_equal(thread,thread1))!=0)
	{
		printf("two thread is same\n");
	}
	else
	{
		printf("two thread is no same\n");
	}
	
	sleep(1);
	return 0;
}


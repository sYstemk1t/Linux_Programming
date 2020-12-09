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
#define NUM 20000
int number = 0;
pthread_mutex_t mutex;		//定义互斥锁
void *mythread1(void *arg)
{
	int i = 0;
	int n;
	for(;i<NUM;i++)
	{
		pthread_mutex_lock(&mutex);
		n = number;
		n++;
		number = n;
		printf("thread1 number = %d\n",number);
		pthread_mutex_unlock(&mutex);
	}
}


void *mythread2(void *arg)
{   
    int i = 0;
    int n;
    for(;i<NUM;i++)
    {
		pthread_mutex_lock(&mutex);
        n = number;
        n++;
        number = n;
		printf("thread2 number = %d\n",number);
		pthread_mutex_unlock(&mutex);
    }
}

int main(int argc,char* args[])
{
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);
	//创建线程
	pthread_mutex_init(&mutex,NULL);		//默认为互斥锁
	pthread_t thread1;
	int ret = pthread_create(&thread1,NULL,mythread1,NULL);
	if(ret!=0)
	{
		printf("pthread_create error %s\n",strerror(errno));
		return -1;
	}

	pthread_t thread2;
    ret = pthread_create(&thread2,NULL,mythread2,NULL);
    if(ret!=0)
    {
        printf("pthread_create error %s\n",strerror(errno));
        return -1;
    }
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&mutex);
	printf("number = %d\n",number);
	return 0;
}


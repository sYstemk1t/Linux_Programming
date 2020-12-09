//循环创建子线程，并且打印自己是第几个子线程
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
	int i = *(int *)arg;
    printf("%d:child thread,pid = %d id = %ld\n",i,getpid(),pthread_self());
}

int main()
{
    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);
    //创建线程
	int ret;
	int arr[5];
	int i = 0;
    int n = 5;
	pthread_t thread[5];
	for(;i<n;i++)
	{
		arr[i] =i;
		int ret = pthread_create(&thread[i],NULL,mythread,&arr[i]);   //简单参数
		if(ret!=0)
		{
			printf("pthread_create error %s\n",strerror(errno));
			return -1;
		}
		
	}
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
    sleep(1);
    return 0;
}

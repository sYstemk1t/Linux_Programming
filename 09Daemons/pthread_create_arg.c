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

struct Test
{
	int data;
	char name[64];
};
void *mythread(void *arg)
{
	//int *p = *(int *)arg;
	struct Test *p = (struct Test *)arg;
	printf("data = %d, name = %s\n",p->data,p->name);
	//printf("p = %d\n",p);
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
}

int main()
{
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);
	//创建线程
	int n = 99;
	struct Test t;
	memset(&t,0,sizeof(struct Test));
	t.data = 88;
	strcpy(t.name,"zhang");
	pthread_t thread;
	//int ret = pthread_create(&thread,NULL,mythread,&n);	//简单参数
	int ret = pthread_create(&thread,NULL,mythread,&t);
	if(ret!=0)
	{
		printf("pthread_create error %s\n",strerror(errno));
		return -1;
	}
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
	sleep(1);
	return 0;
}


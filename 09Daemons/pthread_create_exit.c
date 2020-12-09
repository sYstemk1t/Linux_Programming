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

int g_var = 10;
struct Test t;
void *mythread(void *arg)
{
	printf("child thread,pid = %d id = %ld\n",getpid(),pthread_self());
	
	//printf("a = %p\n",&g_var);
	//pthread_exit(&g_var);
	memset(&t,0,sizeof(t));
	t.data = 100;
	strcpy(t.name,"systemk1t");
	printf("t = %p\n",&t);
	pthread_exit(&t);
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
	//回收子线程
	void *p = NULL;
	pthread_join(thread,&p);
	//int n = *(int *)p;
	struct Test *pp = (struct Test *)p;
	printf("chid exit status:%d %s %p\n",pp->data,pp->name,p);
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
int main(int argc,char* args[])
{
	//void *mmap(void *addr, size_t length, int prot, int flags,
    //              int fd, off_t offset);
	int fd = open("./a.txt",O_RDWR);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}
	int len = lseek(fd,0,SEEK_END);
	void *addr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(addr==MAP_FAILED)
	{
		perror("mmap error");
		return -1;
	}
	

	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork error");
		return -1;
	}
	else if(pid>0)
	{
		memcpy(addr,"hello,world",strlen("hello,world"));	
		wait(NULL);
	}
	else
	{
		sleep(5);	//保证父进程先完成
		char *p = (char *)addr;
		printf("%s\n",p);
	}
}

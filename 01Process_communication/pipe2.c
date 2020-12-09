#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/wait.h>
int main(int argc,char* args[])
{
	int status;
	//创建管道
	int fd[2];
	int ret = pipe(fd);
	if(ret<0)
	{
		perror("pipe error");
		return -1;
	}	
	//write(fd[1],"hello,world",strlen("hello,world"));
	close(fd[1]);
	char buf[64];
	memset(buf,0,sizeof(buf));
	int n = read(fd[0],buf,sizeof(buf));
	printf("%s\n",buf);
	printf("%d\n",n);
}



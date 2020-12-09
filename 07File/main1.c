#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
int main(int argc,char* args[])
{
	int fd = open(args[1],O_RDWR);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}
	int newfd = dup(fd);
	printf("fd = %d newfd = %d\n",fd,newfd);

	char buf[1024];
	memset(buf,0,sizeof(buf));
	write(fd,"hello,world\n",sizeof("hello,world\n"));
	//SEEK_SET
	lseek(fd,0,SEEK_SET);
	int n = read(newfd,buf,sizeof(buf));
	printf("read over:%d %s\n",n,buf);
	close(fd);
	close(newfd);
    return 0;
}

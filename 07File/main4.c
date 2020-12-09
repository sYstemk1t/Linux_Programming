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
	int fd = open(args[1],O_RDWR | O_CREAT, 0777);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}
	int newfd = fcntl(fd,F_DUPFD,0);
	printf("fd = %d newfd = %d",fd,newfd);
	write(fd,"hello,world",sizeof("hello,world"));
	lseek(fd,0,SEEK_SET);
	char buf[64];
	memset(buf,0,sizeof(buf));
	int n = read(newfd,buf,sizeof(buf));
	printf("newfd = %d read = %s\n",n,buf);
	close(fd);
	close(newfd);
    return 0;
}

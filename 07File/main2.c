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
	int fd1 = open(args[2],O_RDWR);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}

	    
    if(fd1<0)
    {
        perror("open error");
        return -1;
    }
	dup2(fd,fd1);
	printf("fd = %d fd1 = %d\n",fd,fd1);

	char buf[1024];
	memset(buf,0,sizeof(buf));
	write(fd,"hello,world\n",sizeof("hello,world\n"));
	//SEEK_SET
	lseek(fd1,0,SEEK_SET);
	int n = read(fd1,buf,sizeof(buf));
	printf("read over:%d %s\n",n,buf);
	close(fd);
	close(fd1);
    return 0;
}

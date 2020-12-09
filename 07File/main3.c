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

	dup2(fd,STDOUT_FILENO);
	printf("ni hao hello world");
	close(fd);
	close(STDOUT_FILENO);
    return 0;
}

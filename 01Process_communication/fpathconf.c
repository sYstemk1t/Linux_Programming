#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/wait.h>
int main(void)
{
	int fd[2];
	int ret = pipe(fd);
	int pipeSize = fpathconf(fd[0],_PC_PIPE_BUF);	
	printf("pipesize = %d\n",pipeSize);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys.wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
void sighandler(int sigin)
{
	printf("sigin = %d\n",sigin);
}

int main()
{
	int fd[2];
	int ret = pipe(fd);
	if(ret<0)
	{
		perror("pipe error");
		return -1;
	}
	signal(SIGPIPE,sighandler);
	close(fd[1]);
	write(fd[0],"hello",strlen("hello"));
	return 0;
	
}

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
int main()
{	
	//int mkfifo(const char *pathname, mode_t mode);
	//创建fifo文件
	int ret = mkfifo("./myfifo",0777);
	if(ret<0)
	{
		perror("fifo error");
		return -1;
	}
	//打开文件
	int fd = open("./myfifo",O_RDWR);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}

	//写文件
	write(fd,"hello,world",strlen("hello,world"));
	//关闭文件
	close(fd);
	getchar();
	return 0;
}

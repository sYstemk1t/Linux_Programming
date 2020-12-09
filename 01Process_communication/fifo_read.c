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
	/*int ret = mkfifo("./myfifo",0777);
	if(ret<0)
	{
		perror("fifo error");
		return -1;
	}*/
	//打开文件
	int fd = open("./myfifo",O_RDWR);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}

	char buf[64];
	memset(buf,0,sizeof(buf));
	int n = read(fd,buf,sizeof(buf));
	printf("%s\n",buf);
	//关闭文件
	close(fd);
	getchar();
	return 0;
}

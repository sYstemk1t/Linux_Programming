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
    //DIR *opendir(const char *name);
    DIR *pDir = opendir(args[1]);
    if(pDir==NULL)
    {
	perror("opendir error");
	return -1;
    }
    
    //struct dirent *readdir(DIR *dirp);

    //int readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result);
    
    struct dirent *pDent = NULL;
    while((pDent=readdir(pDir))!=NULL)
    {
	if(strcmp(pDent->d_name,".")==0 || strcmp(pDent->d_name,"..")==0)
	{
		continue;
	}
	printf("%s->",pDent->d_name);
	switch(pDent->d_type)
	{
	    case DT_REG:
		printf("普通文件\n");
		break;
	    case DT_DIR:
		printf("目录文件\n");
		break;
	    case DT_LNK:
		printf("链接文件\n");
		break;
	}
    }
    
    return 0;
}

#include <stdio.h>
int main(int argc,char* args[])
{
	int i = 0;
	for(;i<argc;i++)
	{
		printf("%d:%s\n",i,args[i]);
	}	
	return 0;
}

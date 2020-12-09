#include <stdio.h>
#include <stdlib.h>

void func()
{
	int i = 0;
	for(;i < 10;i++)
	{
		printf("%d\n",i);
	}
}

int main()
{
	printf("Hello\n");
	func();
	return 0;
}

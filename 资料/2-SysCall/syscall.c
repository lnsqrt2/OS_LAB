#include<linux/unistd.h>
#include<stdio.h>
#include<asm/unistd.h>
#include<stdlib.h>
int main(int argc,char ** argv)
{

	if(argc != 3)
	{
		printf("arguments wrong!\n");
		exit(0);
	}

	int i=syscall(353,argv[1],argv[2]);
	if(i == -1)
	{
		printf("wrong!\n");
		return 0;
	}	
	printf("%d",i);
	return 1;
}


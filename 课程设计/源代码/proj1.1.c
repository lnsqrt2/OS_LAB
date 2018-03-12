//编写一个C程序，用fread、fwrite等库函数实现文件拷贝功能
#include <stdio.h>

#define N 1024

int main(void)
{
	int n = 0;
	char buffer[N]={0};
	FILE *fpRead;
	FILE *fpWrite;
	if((fpRead=fopen("/home/lumos/FileRead.txt","r"))==NULL)
	{
		printf("Fail!Can't open file\n");
		return 0;
	}
	if((fpWrite=fopen("/home/lumos/FileWrite.txt","w"))==NULL)
	{
		printf("Fail!Can't open file\n");
		fclose(fpRead);
		return 0;
	}
	while((n=fread(buffer,sizeof(char),N,fpRead)))
	{
		fwrite(buffer,sizeof(char),n,fpWrite);
	}
	fclose(fpRead);
	fclose(fpWrite);
	printf("Success!\n");
	return 0;
}

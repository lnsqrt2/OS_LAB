//编写一个C程序，用fread、fwrite等库函数实现文件拷贝功能
#include <stdio.h>
#define N 1024
int main(int argc, char const *argv[])
{
	char buffer[N]={0};
	int n;
	FILE *fpRead;
	FILE *fpWrite;
	if((fpRead=fopen("FileRead.txt","r"))==NULL)
	{
		printf("Fail!Can't open file\n");
		return 0;
	}
	if((fpWrite=fopen("FileWrite.txt","w"))==NULL)
	{
		printf("Fail!Can't open file\n");
		fclose(fpRead);
		return 0;
	}
	while((n=fread(buffer,1,N,fpRead)))
	{
		fwrite(buffer,1,n,fpRead);
	}
	fclose(fpRead);
	fclose(fpWrite);
	return 0;
}
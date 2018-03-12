//编写一个C程序，用fread、fwrite等库函数实现文件拷贝功能
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *s;
	FILE *fpRead;
	FILE *fpWrite;
	if((fpRead=fopen("text3.txt","r"))==NULL)
	{
		printf("Fail!Can't open file\n");
		return 0;
	}
	if((fpWrite=fopen("test.txt","w"))==NULL)
	{
		printf("Fail!Can't open file\n");
		fclose(fpRead);
		return 0;
	}
	
	while(1)
	{
		if (feof(fpRead))//read over
		{
			break;
		}
		fread(s,fpRead);
		fwrite(s,fpWrite);
	}
	fclose(fpRead);
	fclose(fwrite);
	return 0;
}
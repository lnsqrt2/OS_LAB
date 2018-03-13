#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	int n = 0;
	int r_fp, w_fp, r_re, w_re;
	char buffer;

	r_fp = open("/home/lumos/FileRead.txt",O_RDONLY);
	if(r_fp == -1)
	{
		printf("Fail!Can't open file\n");
		return 0;
	}

	w_fp = open("/home/lumos/FileWrite.txt",O_WRONLY);
	if(w_fp == -1)
	{
		printf("Fail!Can't open file\n");
		return 0;
	}

	while(1)
	{
		r_re=read(r_fp,&buffer,sizeof(char));
		if(r_re == -1)
		{
			printf("Fail!Can't read file\n");
			return 0;
		}
		if(r_re == 0)//over
		{
			break;
		}
		if(r_re == 1)
		{
			w_re = write(w_fp,&buffer,sizeof(char));
			if(r_re == -1)
			{
				printf("Fail!Can't write file\n");
				return 0;
			}
		}
	}
	close(r_fp);
	close(w_fp);
	printf("Success!\n");
	return 0;
}

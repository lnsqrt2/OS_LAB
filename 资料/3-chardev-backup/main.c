//main.c
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

///////////////////////////////////////////////////////////

int main(void)
{
	char ch = 0;
	int testdev;
	int i,rf=0;
	char buf[15];

	memset(buf, 0, sizeof(buf));
	testdev = open("/dev/chardev",O_RDWR);
	if ( testdev == -1 )
	{
		perror("open error!\n");
		exit(0);
	}

	while ('q' != ch)
	{
		rf=read(testdev,buf,11);
		if(rf<0)
		{
			printf("read error[%d]!\n",rf);
		}
		else
		{
			printf("R:%s\n",buf);
		}
		scanf("%c",&ch);
	}
	close(testdev);

	return 0;
}

///////////////////////////////////////////////////////////

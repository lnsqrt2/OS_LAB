#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	char buf1[128] = {0};
	char buf2[128] = {0};
	int fd,ret;
	//打开设备驱动
	fd = open("/dev/proj3_Device",O_RDWR, S_IRUSR|S_IWUSR);
	if(fd == -1)
	{
		printf("Open Fail\n");
		return -1;
	}
	else
		printf("Open Success!\n");
	printf("Please input something to device: ");
	scanf("%s",buf1);

	ioctl(fd,1,NULL);

	ret = write(fd,buf1,strlen(buf1));
	if(ret == -1)
	{
		printf("Write Fail\n");
		return -1;
	}
	else
		printf("Write Success!\n");
	// printf("Press ENTER to read device:\n");
	// getchar();

	lseek(fd ,0, SEEK_SET);


	ret = read(fd,buf2,strlen(buf2));
	if(ret == -1)
	{
		printf("Read Fail\n");
		return -1;
	}
	else
		printf("Read from device:%s\n",buf2);
	close(fd);
	return 0;
}

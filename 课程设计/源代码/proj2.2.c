#include <stdio.h>
#include <stdlib.h>
#include <linux/unistd.h>
#include <asm/unistd.h>

#define MYCOPY 334

int main(void)
{
	int i;
	i = syscall(MYCOPY);
	if(i == 0)
		printf("Success!\n");
	return 0;
}

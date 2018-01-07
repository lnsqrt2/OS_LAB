#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;//目录项
    struct stat statbuf;//文件信息
    if((dp=opendir(dir))==NULL)
    {
        printf("Open Failed!\n");//打印出错信息;
        return;//返回;
	}
    chdir(dir);//将dir设置为当前目录;
	while((entry=readdir(dp))!=NULL)//读到一个目录项
	{
    	lstat(entry->d_name,&statbuf);//以该目录项的名字为参数,调用lstat得到该目录项的相关信息;

        if(S_ISDIR(statbuf.st_mode))//是目录(文件权限和文件类型)
        {
            if(strcmp(entry->d_name,"..")==0||strcmp(entry->d_name,".")==0)//目录项的名字是”..”或”.”
               	continue;//跳过该目录项;
            printf("dir depth:\t%d\t",depth);//打印目录项的深度、目录名等信息
            printf("dir name:\t%s\n",entry->d_name);
            printdir(entry->d_name,depth+1);//递归调用printdir,打印子目录的信息,其中的depth+4;
        }
		else//打印文件的深度、文件名等信息
		{
			printf("file depth:\t%d\t",depth);
			printf("file size:\t%ld\t",statbuf.st_size);
			printf("file name:\t%s\n",entry->d_name);
		}
    }
    chdir("..");//返回父目录;
    closedir(dp);//关闭目录项;
}

int main(void)
{
	char dir_m[50];
	printf("Please input dir name:\n");
	scanf("%s",dir_m);
	printdir(dir_m,0);//depth = 0
	return 0;
}

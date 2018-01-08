#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>



void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;//目录项
    struct stat statbuf;//文件信息
    struct passwd *psd;     //从该结构体获取文件所有者的用户名
    struct group *grp;      //从该结构体获取文件所有者所属组的组名
    char time[50];
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
            //获取并打印文件类型
            if (S_ISLNK(statbuf.st_mode))
            {
                printf("l");
            }
            else if (S_ISREG(statbuf.st_mode))
            {
                printf("-");
            }
            else if (S_ISDIR(statbuf.st_mode))
            {
                printf("d");
            }
            else if(S_ISCHR(statbuf.st_mode))
            {
                printf("c");
            }
            else if (S_ISBLK(statbuf.st_mode))
            {
                printf("b");
            }
            else if (S_ISFIFO(statbuf.st_mode))
            {
                printf("f");
            }
            else if(S_ISSOCK(statbuf.st_mode))
            {
                printf("s");
            }

            //获取并打印文件所有者的权限
            if(statbuf.st_mode & S_IRUSR)
            {
                printf("r");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IWUSR)
            {
                printf("w");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IXUSR)
            {
                printf("x");
            }
            else
            {
                printf("-");
            }

            //获取并打印与文件所有者同组的用户对该文件的操作权限
            if(statbuf.st_mode & S_IRGRP)
            {
                printf("r");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IWGRP)
            {
                printf("w");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IXGRP)
            {
                printf("x");
            }
            else
            {
                printf("-");
            }

            //获取并打印其他用户对该文件的操作权限
            if (statbuf.st_mode & S_IROTH)
            {
                printf("r");
            }
            else
            {
                printf("-");
            }
            if (statbuf.st_mode & S_IWOTH)
            {
                printf("w");
            }
            else
            {
                printf("-");
            }
            if (statbuf.st_mode & S_IXOTH)
            {
                printf("x");
            }
            else
            {
                printf("-");
            }

            psd = getpwuid(statbuf.st_uid);
            grp = getgrgid(statbuf.st_gid);
            printf("\t%s\t", psd->pw_name);
            printf("%s\t", grp->gr_name);
            printf("%ld\t",statbuf.st_size);
            strcpy(time, ctime(&statbuf.st_mtime));
            time[strlen(time) - 1] = '\0';  //取掉换行符
            printf("%s",time);
            printf("\t%s\t",entry->d_name);
            printf("\t%d\n",depth);
            printdir(entry->d_name,depth+1);//递归调用printdir,打印子目录的信息,其中的depth+4;
        }
		else//打印文件的深度、文件名等信息
		{
            //获取并打印文件类型
            if (S_ISLNK(statbuf.st_mode))
            {
                printf("l");
            }
            else if (S_ISREG(statbuf.st_mode))
            {
                printf("-");
            }
            else if (S_ISDIR(statbuf.st_mode))
            {
                printf("d");
            }
            else if(S_ISCHR(statbuf.st_mode))
            {
                printf("c");
            }
            else if (S_ISBLK(statbuf.st_mode))
            {
                printf("b");
            }
            else if (S_ISFIFO(statbuf.st_mode))
            {
                printf("f");
            }
            else if(S_ISSOCK(statbuf.st_mode))
            {
                printf("s");
            }

            //获取并打印文件所有者的权限
            if(statbuf.st_mode & S_IRUSR)
            {
                printf("r");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IWUSR)
            {
                printf("w");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IXUSR)
            {
                printf("x");
            }
            else
            {
                printf("-");
            }

            //获取并打印与文件所有者同组的用户对该文件的操作权限
            if(statbuf.st_mode & S_IRGRP)
            {
                printf("r");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IWGRP)
            {
                printf("w");
            }
            else
            {
                printf("-");
            }
            if(statbuf.st_mode & S_IXGRP)
            {
                printf("x");
            }
            else
            {
                printf("-");
            }
            //获取并打印其他用户对该文件的操作权限
            if (statbuf.st_mode & S_IROTH)
            {
                printf("r");
            }
            else
            {
                printf("-");
            }
            if (statbuf.st_mode & S_IWOTH)
            {
                printf("w");
            }
            else
            {
                printf("-");
            }
            if (statbuf.st_mode & S_IXOTH)
            {
                printf("x");
            }
            else
            {
                printf("-");
            }
            psd = getpwuid(statbuf.st_uid);
            grp = getgrgid(statbuf.st_gid);
            printf("\t%s\t", psd->pw_name);
            printf("%s\t", grp->gr_name);
		    printf("%ld\t",statbuf.st_size);
            strcpy(time, ctime(&statbuf.st_atime));
            time[strlen(time) - 1] = '\0';  //取掉换行符
            printf("%s",time);
            printf("\t%s\t",entry->d_name);
            printf("\t%d\n",depth);
           // printf("\n");
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

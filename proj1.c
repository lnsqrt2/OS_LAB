#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int child1,child2;
int pipefd[2];

void int1(int sig_no)
{
    if(sig_no == SIGINT)
    {
        kill(child1,SIGUSR1);
        kill(child2,SIGUSR1);
    }
}
void int2(int sig_no)
{
    close(pipefd[0]);
    close(pipefd[1]);
    if(child1 == 0 && sig_no == SIGUSR1)
    {
        printf("Child Process 1 is killed by Parent!\n");
        exit(0);
    }
    if(child2 == 0 && sig_no == SIGUSR1)
    {
        printf("Child Process 2 is killed by Parent!\n");
        exit(0);
    }
}

int main(void)
{
    char buf[40];
    char info[40];
    int status;
    int counter = 1;
    //创建无名管道
    pipe(pipefd);//pipefd[0]只能用于读;pipefd[1]只能用于写
    //设置软中断信号SIGINT
    signal(SIGINT,int1);
    //创建进程1，2
    child1 = fork();
    if(child1 == 0)//子进程1
    {
        signal(SIGINT,SIG_IGN);// 设置忽略信号SIGINT；
        signal(SIGUSR1,int2);// 设置信号SIGUSR1；
        while(1){
            close(pipefd[0]);
            sprintf(info,"I send you %d times",counter);// 发送数据至管道数据；
            write(pipefd[1],info,30);
            counter++;// 计数器++；
            sleep(1);// 睡眠1秒；
        }
    }
    else if(child1 >0)              //返回到主进程
    {
        child2 = fork();
        if(child2 == 0)             //子进程2
        {
            signal(SIGINT,SIG_IGN);
            signal(SIGUSR1,int2);
            while(1){
                close(pipefd[1]);
                read(pipefd[0],buf,40);//接收管道数据；
                printf("%s\n",buf);//显示数据；
            }
        }
        //等待子进程1、2退出；
        waitpid(child1,NULL,0);
        waitpid(child2,NULL,0);
        //关闭管道
        close(pipefd[0]);
        close(pipefd[1]);
        printf("Parent Process is killed!\n");
    }
    return 0;
}

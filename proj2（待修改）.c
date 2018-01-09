#include  <stdio.h>
#include  <stdlib.h>
#include  <pthread.h>
#include  <sys/types.h>
#include  <linux/sem.h>
#include <semaphore.h> 

int semid;
int a=1;
pthread_t p1,p2;

void P(int semid,int index)
{	   
	struct sembuf sem;	
	sem.sem_num = index;
	sem.sem_op = -1;	
	sem.sem_flg = 0; //操作标记：0或IPC_NOWAIT等
	semop(semid,&sem,1);//1:表示执行命令的个数
	return;
}

void V(int semid,int index)
{	
	struct sembuf sem;	
	sem.sem_num = index;
	sem.sem_op =  1;
	sem.sem_flg = 0;	
	semop(semid,&sem,1);	
	return;
}

void *subp1()
{
	for(i=0;i<100;i++)
	{
		P(semid,0);
		printf("%d\n",a);//打印;
		V(semid,1);
	}
	return;
}

void *subp2()
{
	for(int i=0;i<100;i++)
	{
		P(semid,1);
		a=a+i;
		V(semid,0);
	}
	return;
}

int main(void)
{
	int ret1,ret2,ret3,ret4;
	
	union semun arg;
	//创建信号灯；
	semid=semget(IPC_PRIVATE,2,IPC_CREAT|0666);
	//信号灯赋初值；
	arg.val=0;
	semctl(semid,0,SETVAL,arg);
	arg.val=1;
	semctl(semid,1,SETVAL,arg);
	//创建两个线程subp1、subp2;
	ret1 = pthread_create(&p1,NULL,subp1,NULL);
	ret2 = pthread_create(&p2,NULL,subp2,NULL);
	//等待两个线程运行结束；
	ret3 = pthread_join(p1,NULL);
	ret4 = pthread_join(p1,NULL);
	//删除信号灯；
	return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/wait.h>

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

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array; 
}arg;

int main(void)
{
	int i;
	int flag = 0;
	int semid;
	int shmid[6];
	int readbuf,writebuf;
	char *s;
	char ch;
	FILE *fp1;
	FILE *fp2;
	if((fp1=fopen("text3.txt","r"))==NULL)
	{
		printf("fail\n");
	}
	if((fp2=fopen("test.txt","w"))==NULL)
	{
		printf("fail\n");
	}
	//创建共享内存组；
	for(i=0;i<6;i++)
	{
		shmid[i] = shmget(IPC_PRIVATE,sizeof(char),IPC_CREAT|0666);
	}
	//创建信号灯；
	semid=semget(IPC_PRIVATE,2,IPC_CREAT|0666);
	//信号灯赋初值；
	arg.val=0;
	semctl(semid,0,SETVAL,arg);
	arg.val=6;
	semctl(semid,1,SETVAL,arg);
	//创建两个进程readbuf、writebuf;
	if ((readbuf=fork()) == 0)
	{
		//while (flag == 0)
		for(i=0;i<47;i++)
		{
			P(semid,0);
			s=(char *)shmat(shmid[i%6],NULL,0);
			fputc(*s,fp2);

			printf("readbuf %c\n",*s);
			shmdt(s);
			V(semid,1);
		}	
		
	}
	else if ((writebuf=fork()) == 0)
	{
		while ((ch=fgetc(fp1))!=EOF)
		{
			//sleep(1);
			P(semid,1);
			s=(char *)shmat(shmid[i%6],NULL,0);
			*s=ch;
			
			printf("writebuf %c\n",ch);
			shmdt(s);
			V(semid,0);
			i++;
		}
	}
	//等待两个进程运行结束；
	readbuf = wait(NULL);
	writebuf = wait(NULL);
	//删除信号灯；
	semctl(semid,0,IPC_RMID,arg);
	semctl(semid,1,IPC_RMID,arg);
	//删除共享内存组；
	for(i=0;i<6;i++)
	{
		shmctl(shmid[i],IPC_RMID,0);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}


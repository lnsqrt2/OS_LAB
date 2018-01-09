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
	sem.sem_flg = 0; //������ǣ�0��IPC_NOWAIT��
	semop(semid,&sem,1);//1:��ʾִ������ĸ���
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
		printf("%d\n",a);//��ӡ;
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
	//�����źŵƣ�
	semid=semget(IPC_PRIVATE,2,IPC_CREAT|0666);
	//�źŵƸ���ֵ��
	arg.val=0;
	semctl(semid,0,SETVAL,arg);
	arg.val=1;
	semctl(semid,1,SETVAL,arg);
	//���������߳�subp1��subp2;
	ret1 = pthread_create(&p1,NULL,subp1,NULL);
	ret2 = pthread_create(&p2,NULL,subp2,NULL);
	//�ȴ������߳����н�����
	ret3 = pthread_join(p1,NULL);
	ret4 = pthread_join(p1,NULL);
	//ɾ���źŵƣ�
	return 0;
}
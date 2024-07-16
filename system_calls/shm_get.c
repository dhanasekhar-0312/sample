#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
	void *shared_memory;
	char b[100];
	int shmid;
	shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
	printf("key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("process attached at %p\n",shared_memory);
	printf("enter some data in shared memory\n");
	read(0,b,100);
	strcpy(shared_memory,b);
	printf("written data is : %s\n",(char*)shared_memory);

	return 0;

}

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t q;

	q=fork();
	
	if(q==2)
	{
		printf("error in fork system call");

	}
	else if (q==0)
	{
		printf("I am child my pid is %d\n",getpid());
		printf("My parent pid is %d\n",getppid());
	}
	else
	{
		sleep(2);
		printf("I am parent my pid is %d\n",getpid());
		printf("My child pid is %d\n",q);
	}

	printf("common\n");

	return 0;

}

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int fd[2],n;
	pid_t p;
	char b[100];
	pipe(fd);
	p=fork();
	if(p>0)
	{
		printf("passing value to child\n");
		write(fd[1],"hello\n",7);
	}
	else
	{
		n=read(fd[0],b,100);
		write(1,b,n);
		printf("the data was recived");

	}

	return 0;

}


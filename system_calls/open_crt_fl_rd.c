#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int n,fd,fd1;
	char b[50];
	fd=open("text.f1",O_RDONLY);
	n=read(fd,b,50);
	write(1,b,n);
	fd1=open("text.f2",O_CREAT|O_WRONLY,0642);
	write(fd1,b,n);
	return 0;
}


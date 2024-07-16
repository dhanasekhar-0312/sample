#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int n, fd;
	char b[500];
	n=read(0,b,500);
	fd=open("text.f2\n",O_WRONLY|O_APPEND);
	write(fd,b,n);
	return 0;
}


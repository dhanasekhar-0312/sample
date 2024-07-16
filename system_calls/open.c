#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int n,fd;
	char b[55];
	fd=open("text.f1",O_RDONLY);
	n=read(fd,b,55);
	write(1,b,n);
	return 0;
}


#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int n,fd,fd1;
	char b[50];
	fd=open("seek",O_RDWR);
	read(fd,b,10);
	write(1,b,10);
	lseek(fd,10,SEEK_CUR); 
	read(fd,b,10);
	write(1,b,10);
	return 0;
}

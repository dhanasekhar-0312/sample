#include<unistd.h>
int main()
{
    int n;
    char b[30];
    n=read(0,b,30);
    write(1,b,n);
    return 0;
}

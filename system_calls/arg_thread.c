#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

struct ThreadArgs
{
    int arg1;
    int arg2;
    int arg3;
};

void* threadfunction(void* arg)
{
    struct ThreadArgs* args=(struct ThreadArgs*)arg;
    int result=args->arg1+args->arg2+args->arg3;
    printf("result is %d \n",result);
    return NULL;
}

int main()
{
    pthread_t thread;
    struct ThreadArgs args;
    args.arg1 = 10;
    args.arg2 = 20;
    args.arg3 = 30;

    pthread_create(&thread,NULL,threadfunction,(void*)&args);
    pthread_join(thread,NULL);

    return 0;
}


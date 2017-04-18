#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thr_escreve(void *n)
{
    char *num = (char *) n;
    while(1)
    {
        sleep(1);
        printf("%d\n",*num);
        pthread_
    }
}

int main(int argc, const char * argv[])
{
    pthread_t thread;
    char num;

    pthread_create(&thread, NULL, &thr_escreve,&num);

    for(num=0; num<=10; num++)
    {
        sleep(1);
    }
    pthread_cancel(thread);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;

void *functionCount1();
void *functionCount2();

int  x = 0;

void main()
{
   pthread_t thread1, thread2;

   pthread_create( &thread1, NULL, &functionCount1, NULL);
   pthread_create( &thread2, NULL, &functionCount2, NULL);
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   exit(0);
}

void *functionCount1()
{
    for(;;)
    {
        pthread_mutex_lock( &count_mutex );
        x = 0;
        pthread_mutex_unlock( &count_mutex );
        // usleep(10);
        x = 1;
    }
}

void *functionCount2()
{
    for(;;)
    {
        pthread_mutex_lock( &count_mutex );
        printf("%d", x);
        // usleep(10);
        printf("%d", x);
        pthread_mutex_unlock( &count_mutex );
    }
}

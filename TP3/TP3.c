#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

void thread(long unsigned intcpt);

int main()
{
    long unsigned int cpt;
    cpt = 0;
    pthread_t id1, id2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&id1, &attr, (void*)thread, (long unsigned int*)&cpt);
    pthread_create(&id1, &attr, (void*)thread, (long unsigned int*)&cpt);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    return 0;
}


void thread(long unsigned int cpt)
{
    long unsigned int tmp;
    for (long unsigned int i = 0 ; i < 10000000 ; i++)
    {
        tmp = cpt;
        tmp ++;
        cpt = tmp;
    } 
    printf("%lu\n", cpt);
}

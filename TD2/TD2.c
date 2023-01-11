#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <pthread.h>

#define TAILLE 100000
int tab[TAILLE];
int max;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void thread(int *debut);


int main()
{
    int debthread1, debthread2;
    pthread_attr_t attr;
    pthread_t id1, id2;

    max=0;

    return 0;
}

void thread(int *debut)
{
    int i, depart, fin;
    depart = *debut;
    fin = depart+TAILLE/2;
    for (i=depart ; i<fin ; i++)
    {
        pthread_mutex_lock(&mutex);
        if (max < tab[i])
        {
            max = tab[i];
            pthread_mutex_unlock(&mutex);
        }
    }
    pthread_exit(NULL);
}
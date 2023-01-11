#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>

/*Questionnements :
- Pourquoi doit-on metre des void en parametre du thread ?
- C'est quoi les attributs ?
- a quoi servent les parentheses (voiid *) ?
- improtant de déclarer en dehors du main ?

*/

void threads(void *param);

pid_t th1, th2;                 //id des threads
pthread_attr_t attr1, attr2;    //attributs de création

int main()
{
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr1);
    pthread_attr_setdetachstate(&attr1, PTHREAD_CREATE_DETACHED);
    pthread_attr_setdetachstate(&attr2, PTHREAD_CREATE_DETACHED);
    int param1 = 1;
    int param2 = 2;
    th1 = pthread_create(&th1, (void *)threads, (void*)&param1);
    th2 = pthread_create(&th2, (void *)threads, (void*)&param2);
    printf("Thread 1 : %d, thread 2 : %d\n", th1, th2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);


    exit(EXIT_SUCCESS);
}


void threads(void *param)
{
    int numero = *((int*)param);
    printf("Moi, le thread numero %d, viens d etre lance", numero);
    pthread_exit(NULL); //Ne renvoie rien
}
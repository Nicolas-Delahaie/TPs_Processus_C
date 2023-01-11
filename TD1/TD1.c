#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

void relance(int sig)
{
    printf("Alors ca vient ?\n");
    sig_abandon.saflags = SA_RESTART | SA_RESETHAND;
    sigemptyset(&sig_abandon.sa_mask);
    sigaction(SIGALRM, &sig_abandon, NULL);
    alarm(DELAI2);
}
void abandon()
{
    printf("Bon j'abandonne !\n");
    exit(EXIT_FAILURE);
}

int main()
{
    pid_t thRelance;
    pthread_attr_t attr;
    char valeur[100];
    pthread_attr_init(&attr);
    thRelance = pthread_create(&thRelance, (void *)relance);
    scanf("%d", valeur);
    kill(thRelance); // Ferme le thread de relance des qu une valeur a ete saisie

    char c;
    struct sigaction sig_relance, ancien;

    sig_relance.sa_handler = relance;
    sig_relance.sa_flags = SA_RESTART; // Sinon la fonction getchar se termine après traitement
    sigemptyset(&sig_relance.sa_mask);
    sigaction(SIGALARM, &sig_relance, &ancien); // Traitement du signal et récup de l ancien traitement
    alarm(DELAI);                               // Signal SIGALARM dans 15 secondes si on n'a pas arreté d'ici là
    printf("Taper un caractère \n");
    c = getchar();

    exit(EXIT_SUCCESS);
}

void relance()
{
    // Relance l utilisateur pour qu il saisisse une valeur
    while (true)
    {
        printf("Alors ca vient ?");
        sleep(15);
    }
    pthread_exit(NULL);
}
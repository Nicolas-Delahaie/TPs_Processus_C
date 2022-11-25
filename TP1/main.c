#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
    /*------------------- 1 -------------------*/
    // printf("Je suis le numero %d\n", getpid());
    pid_t pid = fork();                      // A partir de là on 2 processus : le père et son clone de fils, sauf si id = -1
    // printf("Fork m a renvoyé la valeur %d\n", pid);
    
    // switch (pid)
    // {
    // case -1 :           // La création du processus a échoué
    //     printf("Impossible de créer un processus fils\n");
    //     exit(EXIT_FAILURE);
    //     break;
    // case 0:             // fork renvoie 0 au processus fils
    //     printf("Je suis le processus n°%d\n", pid);
    //     exit(EXIT_SUCCESS); // si le fils doit se terminer là
    //     break;
    // default:
    //     printf("et mon père est n°%d\n", pid);
    //     break;
    // }

    /*------------------- 2 -------------------*/   
    // unsigned short int nb;                
    
    // switch (pid)
    // {
    // case -1 :           // La création du processus a échoué
    //     printf("Impossible de créer un processus fils\n");
    //     exit(EXIT_FAILURE);
    //     break;
    // case 0:             // 0 : processus fils
    //     sleep(1);       //Fait sortir du main ce fork
    //     printf("Nombres impairs : ");
    //     nb = 0;
    //     for (unsigned int i = 0; i < 10 ; i++)
    //     {
    //         printf("%d - ", nb);
    //         nb += 2;
    //     }
    //     printf("\n");
    //     exit(EXIT_SUCCESS); // si le fils doit se terminer là
    //     break;
    // default:            // autre : processus pere
    //     // sleep(1);       //Permet d'afficher les nombres pairs en deuxieme
    //     printf("Nombres pairs : ");
    //     nb = 1;
    //     for (unsigned int i = 0; i < 10 ; i++)
    //     {
    //         printf("%d - ", nb);
    //         nb += 2;
    //     }
    //     printf("\n");
        
    //     break;
    // }

    /*----------------- 3/4/5 -----------------*/
    switch (pid)
    {
    case 0:     //Fils
        // execlp("cmde", "cmde", "param" , "-p", NULL);           //Ex 3
        execl("cmde", "cmde", "param" , "-p", NULL);            //Ex 4
        exit(EXIT_SUCCESS); // ne sert que si execlp échoue
        break;
    
    default:    //Pere

        break;
    }

    int etat ; // valeur de retour du processus fils
    wait(&etat) ; // attente de terminaison du processus fils
    if (WEXITSTATUS(etat) == EXIT_SUCCESS) printf("%d\n",etat);
    exit(EXIT_SUCCESS); // terminaison du père



    return  911;
}
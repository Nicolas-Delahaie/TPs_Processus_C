#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    SIG_BLOCK(SIGINT);
    while(1)
    {
        printf(".");
    } 
    return 0;
}

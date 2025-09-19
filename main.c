#include <stdio.h>
#include <unistd.h>
#include "game.h"

int main()
{

    printf("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn\n"); 
    printf("loading\n"); 
    fflush(stdout);
    printf("\033[2A");
    sleep(1);
    printf("\rdone loading\n"); 
    fflush(stdout);

    GAME *x;
    createGame(4, &x);
    destoryGame(x);

    return 0;
}

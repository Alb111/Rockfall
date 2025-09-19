#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include "art.h"
#include "display.h"
#include "movement.h"

int main()
{

    // printf("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn\n"); 
    // printf("loading\n"); 
    // fflush(stdout);
    // printf("\033[2A");
    // sleep(1);
    // printf("\rdone loading\n"); 
    // fflush(stdout);

    GAME *x;
    createGame(4, &x);
    listener();
    printGame(x);
    destoryGame(x);
    return 0;
}

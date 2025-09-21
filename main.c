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

    for (int i = 0; i < 44; i++)
    {
        printf("%s\n", title[i]);
    }
    
    sleep(1);
    GAME *x;
    createGame(4, &x);
    printGame(x);
    listener(x);
    destoryGame(x);

    return 0;
}

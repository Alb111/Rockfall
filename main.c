#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include "art.h"
#include "display.h"


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
    printGame(x);
    destoryGame(x);

    for(int i = 0; i < SPRITE_HEIGHT; i++) {
        if( strlen(rock[i]) != SPRITE_WIDTH){
        printf("Length of string %d: %zu\n", i+1, strlen(player[i]));
    }
    }

    return 0;
}

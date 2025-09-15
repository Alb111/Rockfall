#include "art.h"
#include "game.h"

#define SPRITE_WIDTH 38
#define SPRITE_HEIGHT 11

// translates the gameState stored in the 2D cell arr to
// ascii art that gets printed 
void printGame(GAME *rockfall)
{
    // make an array of empty strs
    int to_print_height = SPRITE_HEIGHT * rockfall->n;
    int to_print_width = SPRITE_WIDTH * rockfall->n;
    char **to_print = calloc(to_print_height, sizeof(char*));
    if (to_print == NULL)
    {
        fprintf(stderr, "to_print rows didnt calloc");
        return;
    }
    for (int i = 0; i < to_print_height; i++)
    {
        to_print[i] = calloc()
    }
    
    
    

    for (int i = 0; i < 44; i++)
    {
        to_print[i][0] = '\0';
    }

    //fill that arr with data from gameArr
    for (int i = 0; i < 44; i++)
    {

    }
    

    
}
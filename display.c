#include "art.h"
#include "game.h"

#define SPRITE_WIDTH 38
#define SPRITE_HEIGHT 11

char **createPrintBuffer(GAME *rockfall)
{
    // make an array of empty strs based on game size
    int to_print_height = SPRITE_HEIGHT * rockfall->n;
    int to_print_width = SPRITE_WIDTH * rockfall->n + 1; // extra for null termin
    char **to_print = calloc(to_print_height, sizeof(char*));

    if (to_print == NULL)
    {
        fprintf(stderr, "to_print rows didnt calloc");
        return NULL;
    }

    for (int i = 0; i < to_print_height; i++)
    {
        to_print[i] = calloc(to_print_width, sizeof(char));
        if(to_print[i] == NULL)
        {
            fprintf(stderr, "to_print col %d didnt calloc", i);
            for (int k = 0; k < i; k++)
            {
                free(to_print[k]);
            }
            free(to_print);
            return NULL;
        }
    }
    return to_print;
}

void destroyPrintBuffer(char **to_print, GAME *rockfall)
{
    if(to_print == NULL)
    {
        fprintf(stderr, "to_print is null");
        return;
        
    }

    int to_print_height = SPRITE_HEIGHT * rockfall->n;
    for (int i = 0; i < to_print_height; i++)
    {
        if(to_print[i] == NULL)
        {
            fprintf(stderr, "to_print col %d is null", i);
        }
        free(to_print[i]);
    }
    free(to_print);
}


// translates the gameState stored in the 2D cell arr to
// ascii art that gets printed 
// void printGame(GAME *rockfall)
// {
//     // fill in the memory with empty strs
//     for (int i = 0; i < 44; i++)
//     {
//         to_print[i][0] = '\0';
//     }

//     //fill the empty strs with data from ascii sprites
//     for (int i = 0; i < to_print_height; i++)
//     {
//         for (int k = 0; i < to_print_width-1; i++)
//         {
//         }
        
//     }
    

    
// }
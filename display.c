#include "display.h"

// translates the gameState stored in the 2D cell arr to
// ascii art that gets printed 
void printGame(GAME *rockfall)
{
    int to_print_height = SPRITE_HEIGHT * rockfall->n;
    int to_print_width = SPRITE_WIDTH * rockfall->n + 1; // extra for null termin

    // fill in print buffer with empty strs
    for (int i = 0; i < to_print_height; i++)
    {
        rockfall->print_buffer[i][0] = '\0';
    }

    //fill the empty strs with data from ascii sprites
    for (int i = 0; i < to_print_height; i++)
    {
        for (int k = 0; k < to_print_width-1; k = k + SPRITE_WIDTH)
        {
            // translate from printbuff cords to gameArr cords
            int row = i / SPRITE_HEIGHT;
            int col = k / SPRITE_WIDTH;
            
            char to_add[SPRITE_WIDTH];
        
            switch (rockfall->game_array[row][col])
            {
            case CELL_EMPTY:
                strcpy(to_add, air[i%SPRITE_HEIGHT]);
                break;
            case CELL_PLAYER:
                strcpy(to_add, player[i%SPRITE_HEIGHT]);
                break;
            case CELL_PLAYER_HIT:
                strcpy(to_add, player[i%SPRITE_HEIGHT]);
                break;
            case CELL_ROCK:
                strcpy(to_add, rock[i%SPRITE_HEIGHT]);
                break;
            default:
                break;
            }
            strcat(rockfall->print_buffer[i], to_add);
        }
    }

    fflush(stdout);
    printf("\033[%dA", SPRITE_HEIGHT);
    for (int i = 0; i < to_print_height; i++)
    {
        printf("%s\n", rockfall->print_buffer[i]);
    }
}


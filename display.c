#include "art.h"
#include "game.h"
#include <string.h>

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
                strc
                to_add = to 
                break;
            case CELL_EMPTY:
                /* code */
                break;
            case CELL_EMPTY:
                /* code */
                break;
            case CELL_EMPTY:
                /* code */
                break;
            default:
                break;
            }

        }
        
    }
}
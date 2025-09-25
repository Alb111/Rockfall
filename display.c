#include "display.h"

#define TITLE_HEIGHT 44
#define BLINK_LOC 16
#define BLINK_TEXT_HEIGHT 34

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
    printf("\033[%dA", to_print_height);
    for (int i = 0; i < to_print_height; i++)
    {
        printf("%s\n", rockfall->print_buffer[i]);
    }
}


void printTitle(GAME* rockfall)
{
    fflush(stdout);
    for (int i = 0; i < TITLE_HEIGHT; i++)
    {
        printf("%s\n", title[i]);
    }


    while (1)
    {
        pthread_mutex_lock(&(rockfall->mutex));
        if(rockfall->gameState != STARTING) break;
        pthread_mutex_unlock(&(rockfall->mutex));
        fflush(stdout);
        printf("\033[%dA", BLINK_LOC);
        for (int i = 0; i < 4; i++)
        {
            printf("%s\n", blinking_start[i]);
        }
        for (int i = TITLE_HEIGHT - BLINK_LOC + 4; i < TITLE_HEIGHT; i++)
        {
            printf("%s\n", title[i]);
        }
        usleep(500000); // 0.5 seconds delay
        fflush(stdout);
        printf("\033[%dA", BLINK_LOC);
        for (int i = TITLE_HEIGHT - BLINK_LOC; i < TITLE_HEIGHT; i++)
        {
            printf("%s\n", title[i]);
        }
        usleep(500000); // 0.5 seconds delay
    }
    return;
}

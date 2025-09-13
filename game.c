#include <stdio.h>
#include <stdlib.h>

typedef enum {
    CELL_EMPTY = 0b00,
    CELL_PLAYER = 0b01,
    CELL_ROCK = 0b10,
    CELL_PLAYER_HIT = 0b11
} CELL;

// creates a nxn array to store gamestate
CELL **createGameArray(int n)
{
    int **game_array = calloc(n, sizeof(CELL*));
    for(int i = 0; i < n; i++)
    {
        game_array[i] = calloc(n, sizeof(CELL));
    }
    game_array[0][n/2] = CELL_PLAYER;
}


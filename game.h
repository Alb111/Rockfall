#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

#define SPRITE_WIDTH 38
#define SPRITE_HEIGHT 11



typedef enum {
    CELL_EMPTY = 0b00,
    CELL_PLAYER = 0b01,
    CELL_ROCK = 0b10,
    CELL_PLAYER_HIT = 0b11
} CELL;


typedef struct {
    CELL **game_array;
    atomic_int player_hit;
    int n;
    pthread_mutex_t mutex;
    char **print_buffer;
} GAME;

bool createGame(int n, GAME **rockfall);
bool destoryGame(GAME *rockfall);
bool createGameArray(GAME *rockfall);
bool freeGameArray(GAME *to_destroy);
bool createMutex(GAME *rockfall);
bool freeMutex(GAME *to_destroy);
bool createPrintBuffer(GAME *rockfall);
bool freePrintBuffer(GAME *rockfall);



#endif
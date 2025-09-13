#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

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
} GAME;


void destoryGame(GAME *rockfall);
GAME *createGame(int n);

#endif
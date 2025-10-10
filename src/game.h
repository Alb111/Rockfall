#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

#include "../lib/chan/chan.h"

#define SPRITE_WIDTH 38
#define SPRITE_HEIGHT 11

typedef enum {
    CELL_EMPTY = 0b00,
    CELL_PLAYER = 0b01,
    CELL_ROCK = 0b10,
    CELL_PLAYER_HIT = 0b11
} CELL;

typedef enum {
    STARTING = 1,
    GAMING = 2,
    ENDING = 3
} GAMESTATE;

typedef struct {
    CELL **game_array;
    bool player_hit;
    GAMESTATE gameState;
    int n;
    chan_t* key_stroke_buff;
    char **print_buffer;
} GAME;

bool createGame(int n, GAME **rockfall);
bool destoryGame(GAME *rockfall);
bool createGameArray(GAME *rockfall);
bool freeGameArray(GAME *to_destroy);
bool createKeyStrokeBuff(GAME *rockfall);
bool freeKeyStrokeBuff(GAME *to_destory);
bool createPrintBuffer(GAME *rockfall);
bool freePrintBuffer(GAME *rockfall);

#endif

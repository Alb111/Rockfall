#ifndef GAMEARRAY_H
#define GAMEARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "binUtils.h"


struct gameArray
{
    int** cells;
    int playerLocation;
    pthread_mutex_t lock;
};

struct gameArray *initalizeGameArray();
int freeGameArray(struct gameArray* x);
void printArray(struct gameArray* x);
void moveLeft(struct gameArray *x);
void moveRight(struct gameArray *x);

#endif

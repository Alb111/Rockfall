#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "binUtils.h"

#define rows 4
#define cols 4

struct gameArray
{
    int** cells;
    int playerLocation;
    pthread_mutex_t lock;
};


struct gameArray* initalizeGameArray()
{
    struct gameArray* x =  calloc(1, sizeof(struct gameArray));

    // init the mutex
    if (pthread_mutex_init(&(x->lock), NULL) != 0)
    {
        fprintf(stderr, "mutex initalization failed");
        return NULL;
    }

    // Allocating the memory
    // make space for rows
    int **gameArray = (int **)calloc(rows, sizeof(int *));
    if (!gameArray)
    {
        fprintf(stderr, "alloc for rows failed");
    }

    // make space for the cols
    for (int i = 0; i < rows; i++)
    {
        gameArray[i] = (int *)calloc(cols, sizeof(int));
        if (!gameArray[i])
        {
            fprintf(stderr, "alloc for cols failed");
        }
    }

    // fill Game Array
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            if (i < rows - 1)
            {
                if (setAir(&gameArray[i][k]) != 0)
                {
                    fprintf(stderr, "failed setting cell to air");
                }
            }
            else
            {
                if (setGroundAir(&gameArray[i][k]) != 0)
                {
                    fprintf(stderr, "failed setting cell to groundAir");
                }
            }
        }
    }
    if (setGroundAirPlayer(&gameArray[rows - 1][(cols / 2)]) != 0)
    {
        fprintf(stderr, "failed setting cell to player");
    }

    x->cells = gameArray;
    x->playerLocation = cols / 2;
    return x
}

int freeGameArray(int **gameArray)
{
    for (int i = 0; i < rows; i++)
    {
        free(gameArray[i]);
        gameArray[i] = NULL;
    }
    free(gameArray);
    gameArray = NULL;
    pthread_mutex_destroy(&lock);
    return 1;
}

void printArray(int **gameArray)
{
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            printf("%d", gameArray[i][k]);
        }
        printf("\n");
    }
}

void move(bool Left)
{
    // if left true player moves Left
    // and right if left is false
    pthread_mutex_lock(&lock);
    if (Left)
    {
    }
    pthread_mutex_unlock(&lock);
}

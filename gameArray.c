#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define rows 4
#define cols 4

pthread_mutex_t lock;
int playerlocation;

int **initalizeGameArray()
{
    // init the mutex
    if (pthread_mutex_init(&lock, NULL) != 0)
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
                gameArray[i][k] = 1;
            }
            else
            {
                gameArray[i][k] = 3;
            }
        }
    }
    gameArray[rows - 1][(cols / 2)] = 5;
    playerlocation = cols / 2;

    return gameArray;
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

#include <stdio.h>
#include <stdlib.h>

#define rows 4
#define cols 4

enum Day
{
    air,                // 1
    rockAir,            // 2
    airGround,          // 3
    rockAirGround,      // 4
    airPlayerGround,    // 5
    rockAirPlayerGround // 6
};

int **initalizeGameArray()
{
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
    gameArray[rows-1][(cols/2)] = 5; 

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

    return 1;
}



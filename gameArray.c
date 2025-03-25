#include "gameArray.h"

#define rows 4
#define cols 4

struct gameArray *initalizeGameArray()
{
    struct gameArray *x = calloc(1, sizeof(struct gameArray));

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
    return x;
}

int freeGameArray(struct gameArray *x)
{
    for (int i = 0; i < rows; i++)
    {
        free(x->cells[i]);
        x->cells[i] = NULL;
    }
    free(x->cells);

    x->cells = NULL;
    pthread_mutex_destroy(&(x->lock));
    return 1;
}

void printArray(struct gameArray *x)
{
    int **gameArray = x->cells;
    pthread_mutex_lock(&(x->lock));
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            printf("%d", gameArray[i][k]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&(x->lock));
}

void moveLeft(struct gameArray *x)
{
    pthread_mutex_lock(&(x->lock));
    if (x->playerLocation != 0)
    {
        setGroundAir(&(x->cells[rows - 1][x->playerLocation]));
        setGroundAirPlayer(&(x->cells[rows - 1][x->playerLocation - 1]));
    }
    x->playerLocation--;
    pthread_mutex_unlock(&(x->lock));
}

void moveRight(struct gameArray *x)
{
    pthread_mutex_lock(&(x->lock));
    if (x->playerLocation != cols - 1)
    {
        setGroundAir(&(x->cells[rows - 1][x->playerLocation]));
        setGroundAirPlayer(&(x->cells[rows - 1][x->playerLocation + 1]));
    }
    x->playerLocation++;
    pthread_mutex_unlock(&(x->lock));
}

void rockFall(bool *gameState, struct gameArray *x)
{
    // array to store rock postions of falling row
    int rocks[cols / 3] = {0};
    // find places to generate the rocks in the row
    for (int i = 0; i < cols / 3; i++)
    {
        rocks[i] = rand() % (cols);
    }

    // propagate the rows down
    for (int j = 0; j < rows; j++)
    {
        // generate all the rocks and then check for player colision
        pthread_mutex_lock(&(x->lock));
        for (int k = 0; k < cols / 3; k++)
        {
            if (setNthBitHigh(2, x->cells[j][rocks[k]]) == 15)
            {
                gameState = false;
                return;
            }
            x->cells[j][rocks[k]] = setNthBitHigh(2, x->cells[j][rocks[k]]);
        }
        sleep(1);
        for (int p = 0; p < cols / 3; p++)
        {
            x->cells[j][rocks[p]] = setNthBitLow(2, x->cells[j][rocks[p]]);
        }
        pthread_mutex_unlock(&(x->lock));
    }
}

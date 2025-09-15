#include "game.h"

// sets up memory and inits for a game with (nxn) pixel
bool createGame(int n, GAME *rockfall)
{
    rockfall = malloc(sizeof(GAME));

    if(rockfall == NULL)
    {
        fprintf(stderr, "Error: game couldn't malloc\n");
        return false;
    } 
    
    if(!createGameArray(rockfall))
    {
        free(rockfall);
        return false;
    } 

    if(!createMutex(rockfall))
    {
        freeGameArray(rockfall);
        return false;
    } 

    // store size and wincon for other threads
    atomic_store(&rockfall->player_hit, 0);
    rockfall->n = n;

    return true;
    
}

void destoryGame(GAME *rockfall)
{
        if(rockfall == NULL)
        {
            fprintf(stderr, "ur a dumbass give me an actual pointer");
            return;
        }
        freeGameArray(rockfall);
        freeMutex(rockfall);
        free(rockfall);
        return;
}

// creates a nxn array to store gamestate
bool createGameArray(GAME *rockfall)
{
    // cols init 
    rockfall->game_array = calloc(rockfall->n, sizeof(CELL*));
    if(rockfall->game_array == NULL)
    {
        fprintf(stderr, "Error: gameArray rows couldn't calloc\n");
        return false;
    }

    // rows init
    for(int i = 0; i < rockfall->n; i++)
    {
        rockfall->game_array[i] = calloc(rockfall->n, sizeof(CELL));
        if(rockfall->game_array[i] == NULL)
        {
            fprintf(stderr, "Error: gameArray col %d couldn't malloc\n", i);
            for(int k = 0; k < i; k++) free(rockfall->game_array[k]); // prev rows
            free(rockfall->game_array);
            return false;
        }
    }
    // put player in middle
    rockfall->game_array[0][rockfall->n/2] = CELL_PLAYER;
     
    return true;
}

// free memory for 2D cell arr
void freeGameArray(GAME *to_destroy)
{
    if(to_destroy->game_array == NULL)
    {
        fprintf(stderr, "gameArr to destroy is null: skill issue =(\n");
        return;
    }
    for(int i = 0; i < to_destroy->n; i++)
    {
        if(to_destroy->game_array[i] == NULL)
        {
            fprintf(stderr, "gameArr[%d] to destroy is null: skill issue =(\n", i);
            return;
        }
        free(to_destroy->game_array[i]);
    } 
    free(to_destroy->game_array);
    return;
}

    
// setup mutex 
bool createMutex(GAME *rockfall)
{
    if (pthread_mutex_init(&rockfall->mutex, NULL) != 0) {
        printf("Mutex init failed\n");
        return false;
    }
    return true;
}

// destroy mutex
void freeMutex(GAME *to_destroy)
{
    if(pthread_mutex_destroy(&to_destroy->mutex) != 0)       
    {
        fprintf(stderr, "mutex is to strong it didn't destroy\n");
    }
    return;
}


   
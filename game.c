#include "game.h"

// sets up memory and inits for a game with (nxn) pixel
GAME *createGame(int n)
{
    GAME *rockfall = malloc(sizeof(GAME));
    if(rockfall == NULL){
        fprintf(stderr, "Error: game couldn't malloc\n");
        return NULL;
    } 
    
    rockfall->game_array = createGameArray(n);
    if(rockfall->game_array == NULL){
        fprintf(stderr, "Error: gamearray couldn't malloc\n");
        return NULL;
    } 

    if()
 
    // store size and wincon for other threads
    atomic_store(&rockfall->player_hit, 0);
    rockfall->n = n;

    return rockfall;
}

void destoryGame(GAME *rockfall)
{
        if(rockfall == NULL)
        {
            fprintf(stderr, "ur a dumbass give me an actual pointer");
            return;
        }
        if(!destoryGameArray(rockfall->n, rockfall->game_array))
        {
            return;
        }

       pthread_mutex_destroy(&rockfall->mutex);       
        free(rockfall);
        return;
}

// creates a nxn array to store gamestate
CELL **createGameArray(int n)
{
    // cols init 
    CELL **game_array = calloc(n, sizeof(CELL*));
    if(game_array == NULL)
    {
        fprintf(stderr, "Error: gameArray rows couldn't calloc\n");
        return NULL;
    }

    // rows init
    for(int i = 0; i < n; i++)
    {
        game_array[i] = calloc(n, sizeof(CELL));
        if(game_array[i] == NULL)
        {
            fprintf(stderr, "Error: gameArray col %d couldn't malloc\n", i);
            for(int k = 0; k < i; k++) free(game_array[k]); // prev rows
            free(game_array);
            return NULL;
        }
    }
    // put player in middle
    game_array[0][n/2] = CELL_PLAYER;
     
    return game_array;
}

// free memory for 2D cell arr
bool destoryGameArray(int n, CELL **to_destroy)
{
    if(to_destroy == NULL)
    {
        fprintf(stderr, "gameArr to destroy is null: skill issue =(\n");
        return false;
    }
    for(int i = 0; i < n; i++)
    {
        if(to_destroy[i] == NULL)
        {
            fprintf(stderr, "gameArr[%d] to destroy is null: skill issue =(\n", i);
            return false;
        }
        free(to_destroy[i]);
    } 
    free(to_destroy);
    return true;
}

    
// setup mutex 
bool createMutex(pthread_mutex_t *mutex)
{
    if (pthread_mutex_init(mutex, NULL) != 0) {
        printf("Mutex init failed\n");
        return false;
    }
    return true;
}


        for(int i = 0; i < n; i++) free(rockfall->game_array[i]);
        free(rockfall->game_array);
        free(rockfall);
 
#include "game.h"

GAME *createGame(int n)
{
    GAME *rockfall = malloc(sizeof(GAME));
    if(rockfall == NULL){
        fprintf(stderr, "Error: game couldn't malloc\n");
        return NULL;
    } 

    // creates a nxn array to store gamestate
    // cols init 
    rockfall->game_array = calloc(n, sizeof(CELL*));
    if(rockfall->game_array == NULL)
    {
        fprintf(stderr, "Error: gameArray rows couldn't calloc\n");
        free(rockfall);
        return NULL;
    }

    // rows init
    for(int i = 0; i < n; i++)
    {
       rockfall->game_array[i] = calloc(n, sizeof(CELL));
        if(rockfall->game_array[i] == NULL)
        {
            fprintf(stderr, "Error: gameArray col %d couldn't malloc\n", i);
            for(int k = 0; k < i; k++) free(rockfall->game_array[k]); // prev rows
            free(rockfall->game_array);
            free(rockfall);
            return NULL;
        }
    }

    // put player in middle
    rockfall->game_array[0][n/2] = CELL_PLAYER;

    // setup mutex 
    if (pthread_mutex_init(&rockfall->mutex, NULL) != 0) {
        printf("Mutex init failed\n");
        for(int i = 0; i < n; i++) free(rockfall->game_array[i]);
        free(rockfall->game_array);
        free(rockfall);
        return NULL;
    }

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
        for(int i = 0; i < rockfall->n; i++) free(rockfall->game_array[i]);
        free(rockfall->game_array);
        pthread_mutex_destroy(&rockfall->mutex);       
        free(rockfall);
        return;
}
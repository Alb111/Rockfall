#include "game.h"

// sets up memory and inits for a game with (nxn) pixel
bool createGame(int n, GAME **rockfall)
{
    *rockfall = malloc(sizeof(GAME));
    
    // store size and wincon for other threads
    (*rockfall)->player_hit = false;
    (*rockfall)->n = n;
    (*rockfall)->gameState = STARTING;

    if(*rockfall == NULL)
    {
        fprintf(stderr, "Error: game couldn't malloc\n");
        return false;
    } 
    if(!createGameArray(*rockfall))
    {
        free(*rockfall);
        return false;
    } 
    if(!createMutex(*rockfall))
    {
        freeGameArray(*rockfall);
        return false;
    } 
    if(!createPrintBuffer(*rockfall))
    {
        freeGameArray(*rockfall);
        freeMutex(*rockfall);
        return false;
    } 
    return true;
}

bool destoryGame(GAME *rockfall)
{
    if(rockfall == NULL)
    {
        fprintf(stderr, "ur a dumbass give me an actual pointer");
        return false;
    }
    bool success = true;
    success = success & freeGameArray(rockfall);
    success = success & freeMutex(rockfall);
    success = success & freePrintBuffer(rockfall);
    free(rockfall);
    return success;
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
    rockfall->game_array[rockfall->n - 1][rockfall->n/2] = CELL_PLAYER;
     
    return true;
}

// free memory for 2D cell arr
bool freeGameArray(GAME *to_destroy)
{
    if(to_destroy->game_array == NULL)
    {
        fprintf(stderr, "gameArr to destroy is null: skill issue =(\n");
        return false;
    }
    for(int i = 0; i < to_destroy->n; i++)
    {
        if(to_destroy->game_array[i] == NULL)
        {
            fprintf(stderr, "gameArr[%d] to destroy is null: skill issue =(\n", i);
            return false;
        }
        free(to_destroy->game_array[i]);
    } 
    free(to_destroy->game_array);
    return true;
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
bool freeMutex(GAME *to_destroy)
{
    if(pthread_mutex_destroy(&to_destroy->mutex) != 0)       
    {
        fprintf(stderr, "mutex is to strong it didn't destroy\n");
        return false;
    }
    return true;
}

// setup print buffer that contains a printable verrsion of gamearr
bool createPrintBuffer(GAME *rockfall)
{
    // make an array of empty strs based on game size
    int to_print_height = SPRITE_HEIGHT * rockfall->n;
    int to_print_width = SPRITE_WIDTH * rockfall->n + 1; // extra for null termin
    char **to_print = calloc(to_print_height, sizeof(char*));

    if (to_print == NULL)
    {
        fprintf(stderr, "to_print rows didnt calloc");
        return false;
    }

    for (int i = 0; i < to_print_height; i++)
    {
        to_print[i] = calloc(to_print_width, sizeof(char));
        if(to_print[i] == NULL)
        {
            fprintf(stderr, "to_print col %d didnt calloc", i);
            for (int k = 0; k < i; k++)
            {
                free(to_print[k]);
            }
            free(to_print);
            return false;
        }
    }
    rockfall->print_buffer = to_print;
    return true;
}

// free for print buffer
bool freePrintBuffer(GAME *rockfall)
{
    char **to_print = rockfall->print_buffer;
    if(to_print == NULL)
    {
        fprintf(stderr, "to_print is null");
        return false;
    }

    int to_print_height = SPRITE_HEIGHT * rockfall->n;
    bool noerr = true;
    for (int i = 0; i < to_print_height; i++)
    {
        if(to_print[i] == NULL)
        {
            fprintf(stderr, "to_print col %d is null", i);
            noerr = false;
        }
        else
        {
            free(to_print[i]);
        }
    }
    free(to_print);
    return noerr;
}


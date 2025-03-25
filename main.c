#include "gameArray.h"

struct args
{
    int tid;
    struct gameArray *game;
    bool x;
};

void *threadfunct(void *data)
{
    struct args *params = (struct args *)data;
    int tid = params->tid;
    struct gameArray *curGame = params->game;
    bool gameState = params->x;

    if (tid == 0)
    {
        rockFall(&gameState, curGame);
    }
    else
    {
        printArray(curGame);
    }

    printf("thread done");
    pthread_exit(NULL);
}

int main()
{
    struct gameArray *game = initalizeGameArray();
    bool x = true;
    pthread_t threads[2];
    struct args threadArgs[2];

    // Set up args for 2 diff threads
    for (int i = 0; i < 2; i++)
    {
        threadArgs[i].tid = i;
        threadArgs[i].game = game;
        threadArgs[i].x = x;
    }

    // launch the threads
    for (int i = 0; i < 2; i++)
    {
        if (pthread_create(&threads[i], NULL, threadfunct, &threadArgs[i]) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    freeGameArray(game);
    return 0;
}

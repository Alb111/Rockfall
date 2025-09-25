#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include "art.h"
#include "display.h"
#include "movement.h"

GAME *x;

void *printGameThread(void *arg) {
    printTitle((GAME *)arg);
    return NULL;
}

void *listenerThread(void *arg) {
    listener((GAME *)arg);
    return NULL;
}

int main() {
    createGame(4, &x);
    pthread_t t1, t2;

    // Launch threads
    pthread_create(&t1, NULL, printGameThread, x);
    pthread_create(&t2, NULL, listenerThread, x);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    destoryGame(x);
    return 0;
}

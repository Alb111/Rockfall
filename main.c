#include "gameArray.h"

int main()
{
    struct gameArray *game = initalizeGameArray();
    printArray(game);
    moveLeft(game);
    printArray(game);
    moveRight(game);
    printArray(game);
    freeGameArray(game);
    return 0;
}


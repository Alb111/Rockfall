#include "gameArray.h"

int main()
{
    struct gameArray *game = initalizeGameArray();
    printArray(game);
    freeGameArray(game);
    rockFall(true, game);
    return 0;
}

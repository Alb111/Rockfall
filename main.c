#include "gameArray.h"

int main()
{
    int **gameArray = initalizeGameArray();
    printArray(gameArray);
    freeGameArray(gameArray);
    return 0;
}
#include "gameArray.h"

int main()
{
    int **gameArray = initalizeGameArray();
    freeGameArray(gameArray);
    return 0;
}
#include "Print.h"
#include <stdio.h>
#include "gameArray.h"

int main()
{
     startGame();
     int **lol = initGameArray();
     if (freeGameArray(lol) == 0)
     {
          return 0;
     }
     printf("Error");
     return 1;
}

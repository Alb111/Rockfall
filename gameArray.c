#include <stdio.h>
#include <stdlib.h>
#include "gameArray.h"

// Our game array is going to be encoded with binary with our leftmost bit being LSB,
// bit 0 == rock
// bit 1 == air
// bit 2 == player
// bit 3 == ground
// So 0011 or 3 in decimal would signify a cell with a rock in the air

int **initGameArray(void)
{
     // first alloc memory for 7 int array pointers
     int **gameArray = (int **)malloc(7 * sizeof(int *));
     // then go through this pointer and alloc memory for each array the pointers point to
     for (int i = 0; i < 7; i++)
     {
          gameArray[i] = (int *)malloc(7 * sizeof(int));
     }

     // set everything game array to its default state
     for (int i = 0; i < 7; i++)
     {
          for (int k = 0; k < 7; k++)
          {
               if (i < 5)
               {
                    // top part should be all air at first 0010
                    gameArray[i][k] = 2;
               }
               else
               {
                    // last row should be ground with middle cell having a player 1000 or 1100
                    if (k == 2)
                    {
                         gameArray[i][k] = 12;
                    }
                    else
                    {

                         gameArray[i][k] = 8;
                    }
               }
          }
     }
     return gameArray;
}

int freeGameArray(int **gameArray)
{
     for (int i = 0; i < 6; i++)
     {
          free(gameArray[i]);
     }
     free(gameArray);
     return 0;
}
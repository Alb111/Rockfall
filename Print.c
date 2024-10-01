#include "Print.h"
#include "Art.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

void set_input_mode(void)
{
     struct termios newt;
     // Get the current terminal settings
     tcgetattr(STDIN_FILENO, &newt);
     newt.c_lflag &= ~(ICANON | ECHO);
     tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void reset_input_mode(void)
{
     struct termios oldt;
     // Restore the original terminal settings
     tcgetattr(STDIN_FILENO, &oldt);
     oldt.c_lflag |= (ICANON | ECHO);
     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void startGame(void)
{

     set_input_mode();

     printf("%s", titleArt);

     printf("Press Enter to start playing \n");

     char c;
     while (1)
     {
          c = getchar();
          if (c == '\n')
          {
               break;
          }
     }
     reset_input_mode();

     system("clear");
     printf("Switch to playing state\n");
}

void printQ(void)
{
     printf("askdlj;sldfa;lsk");
}

void printFrame(int **gameArray)
{
     char *toPrint = malloc(10000 * sizeof(char));
     for (int r = 0; r < 7; r++)
     {
          for (int pr = 0; pr < 3; pr++)
          {
               for (int c = 0; c < 7; c++)
               {
                    switch (gameArray[r][c])
                    {
                    case 2:
                         strcat(toPrint, air[pr]);
                         break;

                    case 12:
                         strcat(toPrint, playerGround[pr]);
                         break;

                    case 3:
                         strcat(toPrint, groundAir[pr]);
                         break;

                    default:
                         printf("ERROR");
                         break;
                    }
               }
          strcat(toPrint," \n");
          }
     }
     printf(toPrint);
     free(toPrint);
}

#include "Print.h"
#include "Art.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

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

     printf( "%s", titleArt);

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

void printQ(void){
     printf("askdlj;sldfa;lsk");
}

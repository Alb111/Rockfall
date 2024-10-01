#include "Print.h"

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

     printf(
         " _      _____ _     ____  ____  _      _____                    \n"
         "/ \\  /|/  __// \\   /   _\\ /  _ \\/ \\__/|/  __/                    \n"
         "| |  |||  \\  | |   |  /  | / \\|| |\\/|||  \\                      \n"
         "| |/\\|||  /_ | |_\\/|  \\_ | \\_/|| |  |||  /_                     \n"
         "\\_/  \\|\\____\\\\____/\\____/\\____/\\_/  \\|\\____\\                    \n"
         "                   _____  ____                                   \n"
         "                  /__ __\\/  _ \\                                   \n"
         "                    / \\  | / \\|                                   \n"
         "                    | |  | \\_/|                                   \n"
         "                    \\_/  \\____/                                   \n"
         "                 ____  ____  ____  _  __ _____ ____  _     _    \n"
         "                /  __\\/  _ \\/   _\\/ |/ //    //  _ \\/ \\   / \\   \n"
         "                |  \\/|| / \\||  /  |   / |  __\\| / \\|| |   | |   \n"
         "                |    /| \\_/||  \\_ |   \\ | |   | |-||| |_\\/| |_/\n"
         "                \\_/\\_\\\\____/\\____/\\_|\\_\\\\_/   \\_/ \\\\____/\\____/\n");

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

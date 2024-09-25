#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void set_input_mode()
{
     struct termios newt;
     // Get the current terminal settings
     tcgetattr(STDIN_FILENO, &newt);
     // Disable canonical mode and echoing
     newt.c_lflag &= ~(ICANON | ECHO);
     // Set the new terminal settings
     tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void reset_input_mode()
{
     struct termios oldt;
     // Restore the original terminal settings
     tcgetattr(STDIN_FILENO, &oldt);
     oldt.c_lflag |= (ICANON | ECHO);
     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int main()
{

     set_input_mode(); // Set the terminal to non-canonical mode: enter is only thing allowed

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
               reset_input_mode();
               break;
          }
     }

     system("clear"); // Clear the screen
     printf("Switch to playing state\n");

     return 0;
}

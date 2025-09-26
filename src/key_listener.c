#include "key_listener.h"

#define ESC 27
#define RIGHT 67
#define LEFT 68
#define START_REQ 120
#define END_REQ 113

void listener(GAME *rockfall){
    struct termios oldt, newt;
    char c;

    tcgetattr(STDIN_FILENO, &oldt);   // get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // While in Starting Listen for x to start
    while(1)
    {
        c = getchar();
        if(c == START_REQ)
        {
            //send c into buff
        }
        else if(c == END_REQ)
        {
            //send c into buff
        }
        else if(c == ESC) 
        {
            c = getchar();
            if(c == '[')
            {
                c = getchar();
                //send c into buff
            }
        }
        else
        {
            //nothing
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal
    return;
}


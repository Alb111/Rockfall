#include "movement.h"

#define ESC 27
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68

void listener() {
    struct termios oldt, newt;
    char c;

    tcgetattr(STDIN_FILENO, &oldt);   // get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // infinite loop that listens for keys
    while (1) {
        // arrow keys are given by the following esc seq:
        // esc -> [ -> (a or b or c or d)
        c = getchar();
        if(c == ESC) 
        {
            c = getchar();
            if(c == '[')
            {
                c = getchar();
                switch (c)
                {
                case LEFT:
                    printf("left\n");
                    break;
                case RIGHT:
                    printf("right\n");
                    break;
                case UP:
                    printf("up\n");
                    break;
                case DOWN:
                    printf("down\n");
                    break;
                default:
                    break;
                }
            }
        } 
        if (c == 'q') break;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal
    return;
}
#include "movement.h"

#define ESC 27
#define RIGHT 67
#define LEFT 68

void listener(GAME *rockfall) {
    struct termios oldt, newt;
    char c;

    tcgetattr(STDIN_FILENO, &oldt);   // get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // infinite loop that listens for keys
    while (1) {
        // arrow keys are given by the following esc seq:
        // esc -> [ -> (a or b)
        c = getchar();
        if(c == ESC) 
        {
            c = getchar();
            if(c == '[')
            {
                c = getchar();
                movePlayer(rockfall, c);
                printGame(rockfall);
            }
        } 
        if (c == 'q') break;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal
    return;
}

bool movePlayer(GAME *rockfall, int direction)
{
    if(rockfall == NULL)
    {
        printf("move player: rockfall null");
        return false;
    }

    int to_add = (direction == RIGHT) ? 1 : rockfall->n - 1;

    // find player
    for (int i = 0; i < rockfall->n; i++)
    {
        if(rockfall->game_array[rockfall->n - 1][i] == CELL_PLAYER)
        {
            // move player
            rockfall->game_array[rockfall->n - 1][i] = CELL_EMPTY;
            rockfall->game_array[rockfall->n - 1][(i+to_add)%rockfall->n] = CELL_PLAYER;
            break;
        }
    }
    return true;
}

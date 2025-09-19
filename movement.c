#include "movement.h"
void listener() {
    struct termios oldt, newt;
    char c;

    tcgetattr(STDIN_FILENO, &oldt);   // get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    printf("use arrow keys to move\n");
    while (1) {
        c = getchar();
        printf("You pressed: %c\n", c);
        if (c == 'q') break;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal
    return;
}
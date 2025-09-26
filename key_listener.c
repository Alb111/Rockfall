#import "key_listerner.h"

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

    printf("Past 0");

    // While in Starting Listen for x to start
    while(1)
    {
        pthread_mutex_lock(&(rockfall->mutex));
        if(rockfall->gameState != STARTING) break;
        pthread_mutex_unlock(&(rockfall->mutex));
        c = getchar();
        printf("%c\n", c);
        if(c == 'x')
        {
            pthread_mutex_lock(&(rockfall->mutex));
            printf("xd");
            rockfall->gameState = GAMING;
            pthread_mutex_unlock(&(rockfall->mutex));
        }
    }

    printf("Past 1");

    // While in Gamning Listen for Key Strokes or Quit
    while(1)
    {
        pthread_mutex_lock(&(rockfall->mutex));
        if(rockfall->gameState != GAMING) break;
        pthread_mutex_unlock(&(rockfall->mutex));

        c = getchar();
        if(c == ESC) 
        {
            c = getchar();
            if(c == '[')
            {
                c = getchar();
                if(!movePlayer(rockfall, c))
                {
                    return;
                }
                // printGame(rockfall);
            }
        }
        else if (c == 'q')
        {
            pthread_mutex_lock(&(rockfall->mutex));
            rockfall->gameState = ENDING;
            pthread_mutex_unlock(&(rockfall->mutex));
        }
    }

    printf("Past 2");

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal
    return;
}


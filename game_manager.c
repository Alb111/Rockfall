#include "game_manager.h"

bool movePlayer(GAME *rockfall, int direction)
{
    if(rockfall == NULL)
    {
        fprintf(stderr, "move player: rockfall null\n");
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

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <unistd.h>

#define ESC 27
#define RIGHT 67
#define LEFT 68

#include "art.h"
#include "game.h"
#include "display.h"

bool movePlayer(GAME *rockfall, int direction);

#endif
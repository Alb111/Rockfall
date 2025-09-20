#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#include "movement.h"
#include "art.h"
#include "game.h"
#include "display.h"

void listener(GAME *rockfall);
bool movePlayer(GAME *rockfall, int direction);

#endif
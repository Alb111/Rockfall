#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include "art.h"
#include "display.h"
#include "game_manager.h"
#include "key_listener.h"


int main() {
    GAME *x;
    createGame(4, &x);
    destoryGame(x);
    return 0;
}

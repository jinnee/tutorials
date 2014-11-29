#include <stdio.h>
#include <stdlib.h>

#include "include/Game.h"
#include "gsrc/FifteenGame.h"

int main(int argc, char *argv[]) {
    Game * mg = new FifteenGame();
    mg->start();
    delete mg;

   return 0;
}

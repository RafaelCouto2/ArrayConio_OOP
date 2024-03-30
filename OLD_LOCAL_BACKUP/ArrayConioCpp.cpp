#include <iostream>
#include "arrayconio.h"
#include "game.h"

int main(int argc, char* argv[]) {
    Player player; //CREATE PLAYER OBJ
    Game game(7, player); //CREATE THE GAME, PARSING THE SIZE AND PLAYER OBJ
    game.play(); //THE ALL FUNC
}

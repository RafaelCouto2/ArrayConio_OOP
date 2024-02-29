#include <iostream>
#include "arrayconio.h"
#include "game.h"

int main() {
    Player player;
    
    Game game(8, player);
    game.play();

    
}

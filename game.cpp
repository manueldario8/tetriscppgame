#include "game.h"
#include <iostream>

bool PuedoMover(std::vector<Bloque> bloques, int dx, int dy)
{
    for (int i = 0; i < 4; i++) {
        std::cout << bloques[i].x << "," << bloques[i].y << std::endl;
        if (bloques[i].x + dx > 9 || bloques[i].x + dx < 0 || bloques[i].y + dy > 19 || bloques[i].y + dy < 0) {
            return false;
        }
    }
    return true;
}

#pragma once
#include <vector>
#include "board.h"

enum class TipoPieza {
    I,
    O,
    T,
    L,
    J,
    S,
    Z
};

struct Bloque {
    int x;
    int y;
};

class Pieza {
    TipoPieza tipo;
    int x;
    int y;
    int rotacion;

    public:
    Pieza(TipoPieza tipo, int x, int y);
    std::vector<Bloque> GetBloques() const;
    void Mover(int dx, int dy);
    void Rotar();

};
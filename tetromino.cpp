#include <iostream>
#include "tetromino.h"


Pieza::Pieza(TipoPieza tipo, int x, int y)
{
	this->tipo = tipo;
	this->x = x;
	this->y = y;
	rotacion = 0;
};

std::vector<Bloque> Pieza::GetBloques() const
{
    std::vector<Bloque> bloques;

    if (tipo == TipoPieza::I)
    {
        //####
        if (rotacion == 0 || rotacion == 2){
            bloques.push_back({ x, y });
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x + 2, y });
            bloques.push_back({ x + 3, y });
        }
        if (rotacion == 1 || rotacion == 3){
            bloques.push_back({ x, y });
            bloques.push_back({ x, y + 1});
            bloques.push_back({ x, y + 2});
            bloques.push_back({ x, y + 3});
        }
    }

    if (tipo == TipoPieza::L)
    {
        if (rotacion == 0) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x, y + 2 });
            bloques.push_back({ x + 1, y + 2 });
        }
        else if (rotacion == 1) {
            bloques.push_back({ x, y });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x - 2, y });
            bloques.push_back({ x - 2, y + 1 });
        }
        else if (rotacion == 2) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y - 1 });
            bloques.push_back({ x, y - 2 });
            bloques.push_back({ x - 1, y -2 });
        }
        else if (rotacion == 3) {
            bloques.push_back({ x, y });
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x + 2, y });
            bloques.push_back({ x + 2, y - 1});
        }
    }

    if (tipo == TipoPieza::J)
    {
        if (rotacion == 0) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x, y + 2 });
            bloques.push_back({ x - 1, y + 2 });
        }
        else if (rotacion == 1) {
            bloques.push_back({ x, y });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x - 2, y });
            bloques.push_back({ x - 2, y - 1 });
        }
        else if (rotacion == 2) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y - 1 });
            bloques.push_back({ x, y - 2 });
            bloques.push_back({ x + 1, y - 2 });
        }
        else if (rotacion == 3) {
            bloques.push_back({ x, y });
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x + 2, y });
            bloques.push_back({ x + 2, y + 1 });
        }
    }

    if (tipo == TipoPieza::T)
    {
        if (rotacion == 0) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x + 1, y });
        }
        else if (rotacion == 1) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y - 1 });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x, y + 1 });
        }
        else if (rotacion == 2) {
            bloques.push_back({ x, y });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x, y - 1 });
            bloques.push_back({ x + 1, y });
        }
        else if (rotacion == 3) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y - 1});
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x, y + 1 });
        }
    }

    if (tipo == TipoPieza::O)
    {
        bloques.push_back({ x, y });
        bloques.push_back({ x + 1, y });
        bloques.push_back({ x +1, y + 1 });
        bloques.push_back({ x, y + 1 });
    }

    if (tipo == TipoPieza::Z)
    {
        if (rotacion == 0) {
            bloques.push_back({ x, y });
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x + 1, y + 1});
            bloques.push_back({ x + 2, y + 1 });
        }
        else if (rotacion == 1) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x - 1, y + 1 });
            bloques.push_back({ x - 1, y + 2 });
        }
        else if (rotacion == 2) {
            bloques.push_back({ x, y });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x - 1, y - 1 });
            bloques.push_back({ x - 2, y - 1});
        }
        else if (rotacion == 3) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y - 1 });
            bloques.push_back({ x + 1, y - 1 });
            bloques.push_back({ x + 1, y - 2 });
        }
    }

    if (tipo == TipoPieza::S)
    {
        if (rotacion == 0) {
            bloques.push_back({ x, y });
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x - 1, y + 1 });
        }
        else if (rotacion == 1) {
            bloques.push_back({ x, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x - 1, y - 1 });
        }
        else if (rotacion == 2) {
            bloques.push_back({ x, y });
            bloques.push_back({ x - 1, y });
            bloques.push_back({ x, y - 1 });
            bloques.push_back({ x + 1, y - 1 });
        }
        else if (rotacion == 3) {
            bloques.push_back({ x, y });
            bloques.push_back({ x + 1, y });
            bloques.push_back({ x, y + 1 });
            bloques.push_back({ x - 1, y +1 });
        }
    }

    return bloques;
}

void Pieza::Mover(int dx, int dy) {
    x += dx;
    y += dy;
}

void Pieza::Rotar() {
    rotacion = (rotacion + 1) % 4;
}



#include <iostream>
#include "board.h"
#include <vector>
#include "tetromino.h"

void Board::Inicializar(){

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			tablero[i][j] = 0 ;
		}
	}
}

void Board::SetCasilla(int x, int y, int valor) {
	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
		tablero[x][y] = valor;
}

int Board::GetCasilla(int x, int y) const {
	return tablero[x][y];
}

bool Board::PuedoMover(std::vector<Bloque> bloques, int dx, int dy)
{
    for (int i = 0; i < 4; i++) {
        int nx = bloques[i].x + dx;
        int ny = bloques[i].y + dy;

        if (nx >= Board::WIDTH || nx < 0 || ny >= Board::HEIGHT || ny < 0) {
            return false;
        }

        if (GetCasilla(nx, ny) != 0) {
            return false;
        }
    }
    return true;
}

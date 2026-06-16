#include <iostream>
#include "board.h"

void Board::Inicializar(){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			tablero[i][j] = 0 ;
		}
	}
}

void Board::SetCasilla(int x, int y, int valor) {
	if (x >= 0 && x < 10 && y >= 0 && y < 20)
		tablero[x][y] = valor;
}

int Board::GetCasilla(int x, int y) const {
	return tablero[x][y];
}
#pragma once
#include "tetromino.h"
#include <vector>
#include <iostream>

class Board {
	static const int HEIGHT = 20;
	static const int WIDTH = 10;

	int tablero[WIDTH][HEIGHT];
public:
	void Inicializar();
	void SetCasilla(int x, int y, int valor);
	int GetCasilla(int x, int y) const;
	bool PuedoMover(std::vector<Bloque> bloques, int dx, int dy);
};
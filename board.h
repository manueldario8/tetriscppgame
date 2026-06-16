#pragma once
class Board {
	int tablero[10][20];
public:
	void Inicializar();
	void SetCasilla(int x, int y, int valor);
	int GetCasilla(int x, int y) const;
	
};
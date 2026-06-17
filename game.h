#pragma once
#include <vector>
#include "board.h"
#include "tetromino.h"
#include <SFML/System/Clock.hpp>


const float MOVE_INITIAL_DELAY = 0.15f;
const float MOVE_REPEAT_DELAY = 0.05f;
const float GRAVEDAD_DELAY = 0.8f;

enum class Estado {
	Iniciar,
	Pausar,
	Reiniciar
};

class Game {
	Estado estadoActual;
	Board tablero;
	Pieza* piezaActual;
public:
	Game() {
		estadoActual = Estado::Iniciar;
		piezaActual = nullptr;
		tablero.Inicializar();

	}
	void IniciarJuego();
};
#pragma once
#include "Casilla.h"

class Pieza {
public: 
	Casilla casilla;
	enum pieza_t { NO_PIEZA = -1, PEON = 0, TORRE = 1, ALFIL = 2, CABALLO = 3, REY = 4, REINA = 5 };
	enum color_t {NO_COLOR = -1, BLANCO = 0, NEGRO = 1};

public:
	//Métodos gráficos
	void dibuja();

	//Métodos lógicos

};

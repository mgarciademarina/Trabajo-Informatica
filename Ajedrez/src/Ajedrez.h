#pragma once
#include "Tablero.h"
#include <iostream>

class Ajedrez { //Esta clase es la que hace de nexo entre parte gráfica y la lógica
private:
	Tablero tablero;
	int turno;

public:
	//Métodos gráficos
	void dibuja();
	void inicializa();

	//Métodos lógicos
	void jugada(int button, int state, int x, int y);
	bool validarTurno(int color);
};

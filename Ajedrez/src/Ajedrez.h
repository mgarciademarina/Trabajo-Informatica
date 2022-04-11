#pragma once
#include "Tablero.h"
#include <iostream>

class Ajedrez { //Esta clase es la que hace de nexo entre parte gráfica y la lógica
private:
	Tablero tablero;
	Casilla origen{ -10, -10 };
	Casilla destino{ -10, -10 };
	int turno;

public:
	//Métodos gráficos
	void dibuja();
	void inicializa();

	//Métodos lógicos
	int jugada(int button, int state, int x, int y);
	Casilla getCasilla(int x, int y); //Casilla de origen de la pieza
	bool validarTurno(int color);
};

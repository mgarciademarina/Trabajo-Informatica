#pragma once
#include "Tablero.h"
#include <iostream>
#define  HOME -10

class Ajedrez { //Esta clase es la que hace de nexo entre parte gráfica y la lógica
private:
	Tablero tablero;
	Casilla origen{ HOME, HOME };
	Casilla destino{ HOME, HOME };
	int turno = 0;

public:
	//Métodos gráficos
	void dibuja();
	void inicializa();

	//Métodos lógicos
	int jugada(int button, int state, int x, int y);
	Casilla getCasilla(int x, int y); //Casilla de origen de la pieza
	bool validarTurno(int color);
};

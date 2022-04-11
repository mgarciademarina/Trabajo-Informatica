#pragma once
#include "Tablero.h"
#include <iostream>

class Ajedrez { //Esta clase es la que hace de nexo entre parte gr�fica y la l�gica
private:
	Tablero tablero;
	Casilla origen{ -10, -10 };
	Casilla destino{ -10, -10 };
	int turno;

public:
	//M�todos gr�ficos
	void dibuja();
	void inicializa();

	//M�todos l�gicos
	int jugada(int button, int state, int x, int y);
	Casilla getCasilla(int x, int y); //Casilla de origen de la pieza
	bool validarTurno(int color);
};

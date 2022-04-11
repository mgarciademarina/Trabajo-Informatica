#pragma once
#include "Tablero.h"
#include <iostream>

class Ajedrez { //Esta clase es la que hace de nexo entre parte gr�fica y la l�gica
private:
	Tablero tablero;
	int turno;

public:
	//M�todos gr�ficos
	void dibuja();
	void inicializa();

	//M�todos l�gicos
	void jugada(int button, int state, int x, int y);
	Casilla getCasillaOrigen(int x, int y); //Casilla de origen de la pieza
	Casilla getCasillaDestino(int x, int y); //Casilla de destino de la pieza
	bool validarTurno(int color);
};

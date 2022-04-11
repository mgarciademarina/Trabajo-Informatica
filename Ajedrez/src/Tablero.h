#pragma once
#include "Pieza.h"
#include <cmath>

class Tablero {
public:
	Pieza tab[8][8];

public:
	//M�todos gr�ficos
	void dibuja();

	//M�todos l�gicos
	void setPosInit();
	Casilla getCasillaOrigen(int x, int y); //Casilla de origen de la pieza
	Casilla getCasillaDestino(int x, int y); //Casilla de destino de la pieza
	bool checkMove(int fo, int co, int fd, int cd); //Determinar si un movimiento es v�lido o no
	
};
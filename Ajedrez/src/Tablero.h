#pragma once
#include "Pieza.h"

class Tablero {
public:
	Pieza tab[8][8];

public:
	//M�todos gr�ficos
	void dibuja();

	//M�todos l�gicos
	void setPosInit();
	void checkMove(); //m�todo para determinar si un movimiento es v�lido o no
};
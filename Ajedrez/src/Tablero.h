#pragma once
#include "Pieza.h"
#include <cmath>

class Tablero {
private:
	Pieza tab[8][8];

public:
	//M�todos gr�ficos
	void dibuja();

	//M�todos l�gicos
	void setPosInit();
	int getColor(Casilla c);
	
	friend class Ajedrez;
};
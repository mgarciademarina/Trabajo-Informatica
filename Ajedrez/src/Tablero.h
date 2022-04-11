#pragma once
#include "Pieza.h"
#include <cmath>

class Tablero {
private:
	Pieza tab[8][8];

public:
	//Métodos gráficos
	void dibuja();

	//Métodos lógicos
	void setPosInit();
	int getColor(Casilla c);
	
	friend class Ajedrez;
};
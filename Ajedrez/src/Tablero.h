#pragma once
#include "Pieza.h"

class Tablero {
public:
	Pieza tab[8][8];

public:
	//Métodos gráficos
	void dibuja();

	//Métodos lógicos
	void setPosInit();
};
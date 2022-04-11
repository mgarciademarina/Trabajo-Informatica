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
	void checkMove(); //método para determinar si un movimiento es válido o no
};
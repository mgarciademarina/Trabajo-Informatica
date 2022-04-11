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
	Casilla getCasillaOrigen(int x, int y); //Casilla de origen de la pieza
	Casilla getCasillaDestino(int x, int y); //Casilla de destino de la pieza
	int getColor(Casilla c);
	
	friend class Ajedrez;
};
#pragma once
#include "Pieza.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Tablero {
private:
	const int n = 8;
	Pieza** tab;
	//Pieza tab[8][8];

public:
	Tablero();
	~Tablero();

	//Métodos gráficos
	void dibuja();

	//Métodos lógicos
	void setPosInit();
	int getColor(Casilla c);
	bool validarMov(Casilla co, Casilla cd);//Método para validar movimiento, dentro llama al método validar movimiento de la pieza de la casilla de origen
	void actualiza(Casilla co, Casilla cd);//Actualiza la matriz del tablero

	//Otros métodos
	string to_string();
	ostream& print(ostream& o);
	
};
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

	//M�todos gr�ficos
	void dibuja();

	//M�todos l�gicos
	void setPosInit();
	int getColor(Casilla c);
	bool validarMov(Casilla co, Casilla cd);//M�todo para validar movimiento, dentro llama al m�todo validar movimiento de la pieza de la casilla de origen
	void actualiza(Casilla co, Casilla cd);//Actualiza la matriz del tablero

	//Otros m�todos
	string to_string();
	ostream& print(ostream& o);
	
};
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
	int** pmov;
	
public:
	Tablero();
	~Tablero();

	//Métodos gráficos
	void dibuja();
	int posiblesMov(Casilla co);
	void setMovInit();

	//Métodos lógicos
	void setPosInit();
	int getColor(Casilla c);
	int validarEnroque(Casilla co, Casilla cd);
	bool validarMov(Casilla co, Casilla cd);//Método para validar movimiento, dentro llama al método validar movimiento de la pieza de la casilla de origen
	void actualiza(Casilla co, Casilla cd);//Actualiza la matriz del tablero
	int jaque(); //Devuelve 0 si hay jaque, 1 si hay jaque mate y -1 si no hay nada
	bool jaqueMate(Casilla rn, Casilla rb); //Comprueba el jaque mate

	//Otros métodos
	string to_string();
	ostream& print(ostream& o);
	
};

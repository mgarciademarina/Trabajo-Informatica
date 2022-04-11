#pragma once
#include "freeglut.h"

class Casilla {
private:
	int f; //fila (1,2...8)
	int c; //columna (a,b,c...h en tablero, pero numeralizado en código)
	
public:
	//Constr-Destr
	Casilla(int x=-1, int y=-1);
	~Casilla();
	
	//Métodos (sobrecarga de operadores)
	Casilla operator +(Casilla);
	Casilla operator +(float); //suma numero a fila
	Casilla operator -(Casilla);
	Casilla operator *(float);
	float operator *(Casilla);
	
	float argumento();
	float modulo();

	friend class Pieza;
	friend class Tablero;
	friend class Ajedrez;
};

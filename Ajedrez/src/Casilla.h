#pragma once
#include "freeglut.h"

class Casilla {
private:
	
public:
	int f; //fila (1,2...8)
	int c; //columna (a,b,c...h en tablero, pero numeralizado en código)
	
	
	//Constr-Destr
	Casilla(int x=-1, int y=-1);
	Casilla(const Casilla& cas);
	~Casilla();
	
	//Métodos (sobrecarga de operadores)
	Casilla operator +(Casilla);
	Casilla operator +(float); //suma numero a fila
	Casilla operator -(Casilla);
	Casilla operator *(float);
	float operator *(Casilla);
	friend bool operator ==(Casilla cas1, Casilla cas2);
	friend bool operator != (Casilla cas1, Casilla cas2);
	
	float argumento();
	float modulo();

	friend class Pieza;
	friend class Tablero;
	friend class Ajedrez;
};

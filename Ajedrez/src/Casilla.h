#pragma once

class Casilla {
public:
	int fila;
	int columna;
	
public:
	//Constr-Destr
	Casilla(int x=0, int y=0);
	~Casilla();
	
	//Métodos (sobrecarga de operadores)
	Casilla operator +(Casilla);
	Casilla operator +(float);
	Casilla operator -(Casilla);
	Casilla operator *(float);
	float operator *(Casilla);
	
	Casilla unitario(); //devuelve v unitario
	float argumento();
	float modulo();

};

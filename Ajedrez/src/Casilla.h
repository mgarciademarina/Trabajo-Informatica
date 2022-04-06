#pragma once

class Casilla {
public:
	int f; //fila (1,2...8)
	int c; //columna (a,b,c...h en tablero, pero numeralizado en código)
	
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

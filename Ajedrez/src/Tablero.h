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
	Pieza** tab;		//Tablero es una matriz de piezas
	int** pmov;			//Matriz auxiliar para implementar la ayuda al movimiento
	
public:
	Tablero();
	~Tablero();

	//Métodos gráficos
	void dibuja();
	int posiblesMov(Casilla co);							//Ayuda al movimiento
	void setMovInit();										//Inicialización de la matriz de posibles movimientos

	//Métodos lógicos
	void setPosInit();										//Inicializa el tablero
	int getColor(Casilla c);						
	int validarEnroque(Casilla co, Casilla cd);				//Auxiliar a validarMov para validar los dos tipos de enroque
	bool validarMov(Casilla co, Casilla cd);				//Método para validar movimiento
	void actualiza(Casilla co, Casilla cd);					//Actualiza la matriz del tablero si el movmiento es válido
	int jaque(int turn);									//Comprobación de jaque y jaque mate
	int Trayectoria(Casilla co, Casilla cd, Casilla cp);	//Comprobación de trayectorias para jaque y jaque mate
	

	//Otros métodos
	string to_string();										//Auxiliares para test unitarios
	ostream& print(ostream& o);								//Auxiliares para test unitarios
	
};

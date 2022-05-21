#pragma once
#include "Tablero.h"
#include <iostream>
#define  HOME -10					//Valor arbitrario de inicio de las casillas de origen y destino


class Ajedrez {						//Primer coordinador de la estructura
private:
	Tablero tablero;
	Casilla origen{ HOME, HOME };	//Casilla de origen para la implementaci�n del movimeinto por rat�n
	Casilla destino{ HOME, HOME };	//Casilla de destsino para la implementaci�n del movimiento por rat�n
	int turno = 0;					//gesti�n del turno

public:
	//M�todos gr�ficos
	void dibuja();					
	void inicializa();									//Inicializaci�n de variables de tablero

	//M�todos l�gicos
	int jugada(int button, int state, int x, int y);	//Coordina los diferentes m�todos de tablero para gestionar una jugada
	Casilla getCasilla(int x, int y);					//Casilla en la que se pincha
	bool validarTurno(int color);						//Determina si el turno es de las piezas negras o blancas
	int jaque();										//Llamada al m�todo jaque de tablero
	void setTurno(int v);								//Setter del turno para permitir reiniciar la partida sin errores
};

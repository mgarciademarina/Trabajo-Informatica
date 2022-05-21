#pragma once
#include "Tablero.h"
#include <iostream>
#define  HOME -10					//Valor arbitrario de inicio de las casillas de origen y destino


class Ajedrez {						//Primer coordinador de la estructura
private:
	Tablero tablero;
	Casilla origen{ HOME, HOME };	//Casilla de origen para la implementación del movimeinto por ratón
	Casilla destino{ HOME, HOME };	//Casilla de destsino para la implementación del movimiento por ratón
	int turno = 0;					//gestión del turno

public:
	//Métodos gráficos
	void dibuja();					
	void inicializa();									//Inicialización de variables de tablero

	//Métodos lógicos
	int jugada(int button, int state, int x, int y);	//Coordina los diferentes métodos de tablero para gestionar una jugada
	Casilla getCasilla(int x, int y);					//Casilla en la que se pincha
	bool validarTurno(int color);						//Determina si el turno es de las piezas negras o blancas
	int jaque();										//Llamada al método jaque de tablero
	void setTurno(int v);								//Setter del turno para permitir reiniciar la partida sin errores
};

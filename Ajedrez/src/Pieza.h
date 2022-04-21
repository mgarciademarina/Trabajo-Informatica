#pragma once
#include "Casilla.h"
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "freeglut.h"
#include "ETSIDI.h"

enum pieza_t { NO_PIEZA = -1, PEON = 0, TORRE = 1, ALFIL = 2, CABALLO = 3, REY = 4, REINA = 5 };
enum color_t { NO_COLOR = -1, BLANCO = 0, NEGRO = 1 };

class Pieza {
private: 
	Casilla casilla;
	pieza_t pieza;
	color_t color;

public:
	Pieza();
	Pieza(pieza_t p, color_t c, Casilla cas): pieza(p), color(c), casilla(cas){}
	Pieza(const Pieza& p);
	~Pieza();

	//Métodos gráficos
	void dibuja(int flag, int auxmov);
	
	friend class Tablero;
	friend class Torre;
	friend class Reina;
	friend class Peon;
	friend class Alfil;
};

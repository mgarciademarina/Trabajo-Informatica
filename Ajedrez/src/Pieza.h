#pragma once
#include "Casilla.h"
#include "freeglut.h"

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

	//M�todos gr�ficos
	void dibuja(int flag);

	//M�todos l�gicos
	bool validarMov(Casilla cd);
	
	friend class Tablero;
};

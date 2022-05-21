#pragma once
#include "Pieza.h"

class Peon{
  public:
	static bool Mov(Casilla cd, Casilla co, Pieza** tab);	//Ley de movimiento del peón
	static bool Comer(Casilla cd, Casilla co, Pieza** tab);	//Auxiliar por si se dan las condiciones de comer para el peón
};

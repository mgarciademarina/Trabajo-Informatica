#pragma once
#include "Pieza.h"

class Peon{
  public:
	static bool Mov(Casilla cd, Casilla co, int color);
	static bool Comer(Casilla cd, Casilla co, int color);
};

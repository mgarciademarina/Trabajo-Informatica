#pragma once
#include "Pieza.h"

class Peon{
  public:
	static bool Mov(Casilla cd, Casilla co, Pieza** tab);
	static bool Comer(Casilla cd, Casilla co, Pieza** tab);
};

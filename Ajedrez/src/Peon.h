#pragma once
#include "Pieza.h"

class Peon : public Pieza{
  public:
	static bool Mov(Casilla cd, Casilla co, color_t color);
	static bool Comer(Casilla cd, Casilla co, color_t color);
};

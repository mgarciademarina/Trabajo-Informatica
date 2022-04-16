#pragma once
#include "Pieza.h"

class Rey : public Pieza{
public:
	static bool Mov(Casilla cd, Casilla co);
};

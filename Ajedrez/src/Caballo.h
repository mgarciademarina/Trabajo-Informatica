#pragma once
#include "Pieza.h"

class Caballo : public Pieza{
public:
  static bool Mov(Casilla cd, Casilla co);
};

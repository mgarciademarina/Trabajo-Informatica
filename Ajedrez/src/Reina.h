#pragma once
#include "Pieza.h"

class Reina{
 public:
  static bool Mov(Casilla cd, Casilla co, Pieza** tab);
  //Comprueba el movimiento de la reina
  //Necesita comprobar la trayectoria mediante un puntero al tablero
};

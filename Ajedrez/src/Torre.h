#pragma once
#include "Pieza.h"

class Torre{
public:
	static bool Mov(Casilla cd, Casilla co, Pieza** tab);
	//M�todo que valida el movimiento de la torre a partir de las casillas de origen y destino seleccionadas
	//Comprueba tambi�n la trayectoria del movimiento
};


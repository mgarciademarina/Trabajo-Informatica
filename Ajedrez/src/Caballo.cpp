#include "Caballo.h"
#include <math.h>
bool Caballo::Mov(Casilla cd, Casilla co){
//Puede saltar solo es neecsario comprobar que el destino cumple la ley de movimiento

	if (((abs(cd.f - co.f) == 2) && (abs(cd.c - co.c) == 1)) || ((abs(cd.f - co.f) == 1) && (abs(cd.c - co.c) == 2))) {
		return true;
	}
	else {
		return false;
	}
}

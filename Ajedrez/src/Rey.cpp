
#include "Rey.h"
#include <math.h>
bool Rey::Mov(Casilla cd, Casilla co) {
//Basta con determinar que el destino cumple la ley de movimiento del rey

	if ((abs(cd.f - co.f) <= 1) && (abs(cd.c - co.c)<=1) && ((cd.c != co.c) || (cd.f != co.f))){ 
		return true;
	}
	else { return false; }
}

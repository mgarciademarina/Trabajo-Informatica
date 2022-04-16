#include "Alfil.h"
#include <math.h>
bool Alfil::Mov(Casilla cd, Casilla co)
{
	if ((abs(cd.f - co.f) == abs(cd.c - co.c))) {return true;}
	else { return false; }
}


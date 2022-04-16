#include "Reina.h"
#include <math.h>
bool Reina::Mov(Casilla cd, Casilla co)
{
	if ((cd.f == co.f || cd.c == co.c)||(abs(cd.f - co.f) == abs(cd.c - co.c))){ return true; }
	else {return false;}
}

#include "Alfil.h"
bool Alfil::Mov(Casilla cd, Casilla co)
{
	if (((cd.f - co.f) == (cd.c - co.c)) && ((cd.f - co.f) != 0)) {	return true;}
	else { return false; }
}

#include "Reina.h"
bool Reina::Mov(Casilla cd, Casilla co)
{
	if ((cd.f == co.f || cd.c == co.c)||((cd.f - co.f) == (cd.c - co.c))){ return true; }
	else {return false;}
}

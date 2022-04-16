#include "Peon.h"
#include <math.h>
bool Peon::Mov(Casilla cd, Casilla co)
{
	if ((cd.c=co.c)&&(((cd.f-co.f)==1)||((cd.f =4 )))){ return true; } //Para blanco (pieza.color == BLANCO) &&
	else if ((cd.c = co.c) && (((co.f - cd.f) == 1) || ((cd.f = 5)))) { return true; } //Para negro (pieza.color == NEGRO) &&
	else { return false; }
}
bool Peon::Comer(Casilla cd, Casilla co)
{
	return true; // Necesito saber si hay una pieza de otro color 
	/* if ((pieza.color == BLANCO) && (abs(cd.c - co.c) == 1) && (((cd.f-co.f)==1)||((cd.f =4 )))) { return true; }
	else if ((pieza.color == NEGRO)&&(abs(cd.c-co.c)==1)&&(((co.f - cd.f) == 1) || ((cd.f = 5)))){return true;}
	else { return false; }*/
}

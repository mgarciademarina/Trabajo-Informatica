#include "Peon.h"
#include <math.h>

bool Peon::Mov(Casilla cd, Casilla co, int color){

	if(cd.c=co.c)
	{
		if (color == 0) {
			if (((cd.f - co.f) == 1) || ((cd.f == 4) && (co.f == 2))) { return true; }
			else { return false; }
		}
		else if (color == 1)
		{
			if (((cd.f - co.f) == -1) || ((cd.f == 5)&&(co.f==7))) { return true; }
			else { return false; }
		}
	}
	else { return false; }
}
bool Peon::Comer(Casilla cd, Casilla co, int color)
{
	if (abs(cd.c - co.c)==1)
	{
		if (color == 0) {
			if (((cd.f - co.f) == 1) || ((cd.f = 4))) { return true; }
			else { return false; }
		}
		else if (color == 1)
		{
			if (((co.f - cd.f) == 1) || ((cd.f = 5))) { return true; }
			else { return false; }
		}
	}
	else { return false; }
}


#include "Peon.h"
#include <math.h>

bool Peon::Mov(Casilla cd, Casilla co, Pieza** tab){
	//Comprobación del movimiento de peon
	if(cd.c==co.c)
	{
		if (tab[co.f][co.c].getColor() == 0) {
			if (((cd.f - co.f) == 1)) { 
				return true; 
			}
			else if ((cd.f == 3) && (co.f == 1) && tab[2][co.c].getPieza() == NO_PIEZA) { //Dos casillas en el primer movimiento
				return true;
			}
			else { return false; }
		}
		else if (tab[co.f][co.c].getColor() == 1)
		{
			if (((cd.f - co.f) == -1) ) { 
				return true; 
			}
			else if ((cd.f == 4) && (co.f == 6) && tab[5][co.c].getPieza() == NO_PIEZA) { //Dos casillas en el primer movimiento
				return true;
			}
			else { return false; }
		}
	}
	else { return false; }
}


bool Peon::Comer(Casilla cd, Casilla co, Pieza** tab){
	if (abs(cd.c - co.c)==1)
	{
		if (tab[co.f][co.c].getColor() == 0) {
			if ((cd.f - co.f) == 1) { return true; } 
			else { return false; }
		}
		else if (tab[co.f][co.c].getColor() == 1)
		{
			if ((co.f - cd.f) == 1) { return true; }
			else { return false; }
		}
	}
	else { return false; }
}


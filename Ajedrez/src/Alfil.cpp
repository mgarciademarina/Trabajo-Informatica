#include "Alfil.h"
#include <math.h>

bool Alfil::Mov(Casilla cd, Casilla co, Pieza** tab){
//Comprbaci�n de la trayectoria en sus difernetes posibilidades
//Basta con recorrer el tablero desde la casilla de origen hasta el destino
//Teniedno en cuenta la ley de movimiento para evitar comprobaciones innecesarias
//Hay 4 posibilidades en cuanto a la relaci�n entre casilla de origen y destino 

	if ((abs(cd.f - co.f) == abs(cd.c - co.c))) {
		if (cd.f > co.f && cd.c > co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].getPieza() != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f--;
				cd.c--;
			}
		}else if (cd.f > co.f && cd.c < co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].getPieza() != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f--;
				cd.c++;
			}
		}else if (cd.f < co.f && cd.c < co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].getPieza() != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f++;
				cd.c++;
			}
		}else if (cd.f < co.f && cd.c > co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].getPieza() != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f++;
				cd.c--;
			}
		}
		return true;
	}
	else { return false; }
}


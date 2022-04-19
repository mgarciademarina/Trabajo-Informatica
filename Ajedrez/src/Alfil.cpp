#include "Alfil.h"
#include <math.h>

bool Alfil::Mov(Casilla cd, Casilla co, Pieza** tab){

	if ((abs(cd.f - co.f) == abs(cd.c - co.c))) {
		if (cd.f > co.f && cd.c > co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].pieza != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f--;
				cd.c--;
			}
		}else if (cd.f > co.f && cd.c < co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].pieza != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f--;
				cd.c++;
			}
		}else if (cd.f < co.f && cd.c < co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].pieza != NO_PIEZA && (cd.f != i && cd.c != j)) {
					return false;
				}
				cd.f++;
				cd.c++;
			}
		}else if (cd.f < co.f && cd.c > co.c) {
			int i = cd.f;
			int j = cd.c;
			while (cd.f != co.f && cd.c != co.c) {
				if (tab[cd.f][cd.c].pieza != NO_PIEZA && (cd.f != i && cd.c != j)) {
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


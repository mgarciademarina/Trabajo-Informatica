#include "Reina.h"
#include <math.h>

bool Reina::Mov(Casilla cd, Casilla co, Pieza** tab){

	if (cd.f == co.f || cd.c == co.c || (abs(cd.f - co.f) == abs(cd.c - co.c))){ 
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
		} else if (cd.f == co.f) {
			switch (cd.c > co.c) {
			case true:
				for (int i = cd.c; i != co.c; i--) {

					if (tab[co.f][i].pieza != NO_PIEZA && i != cd.c) {

						return false;
					}
				}
				break;
			case false:
				for (int i = cd.c; i != co.c; i++) {
					if (tab[co.f][i].pieza != NO_PIEZA && i != cd.c) {
						return false;
					}
				}
				break;
			}
		}
		else if (cd.c == co.c) {
			switch (cd.f > co.f) {
			case true:
				for (int i = cd.f; i != co.f; i--) {
					if (tab[i][co.c].pieza != NO_PIEZA && i != cd.f) {
						return false;
					}
				}
				break;
			case false:
				for (int i = cd.f; i != co.f; i++) {
					if (tab[i][co.c].pieza != NO_PIEZA && i != cd.f) {
						return false;
					}
				}
			}
		}
		return true;
	}
	else {return false;}
}

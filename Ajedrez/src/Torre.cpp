#include "Torre.h"
#include <iostream>
using namespace std;

bool Torre::Mov(Casilla cd, Casilla co, Pieza** tab){

	if (cd.f == co.f) {
		switch (cd.c > co.c) {
		case true:
			for (int i = cd.c; i != co.c; i--) {
				
				if (tab[co.f][i].pieza != NO_PIEZA && i != cd.c ) {
					
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
		return true;
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
		return true;
	}
	else {return false; }
}

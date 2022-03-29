#include <iostream>
#include "Tablero.h"
using namespace std;

void Tablero::setPosInit() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Asignaci�n de color
			if (i == 1 || i == 0) {
				tab[i][j].color = BLANCO;
			}else if (i == 6 || i == 7) {
				tab[i][j].color = NEGRO;
			}
			else {
				tab[i][j].color = NO_COLOR;
			}
			
			//Asiganci�n de tipo
			if (i == 1 || i == 6) {
				tab[i][j].pieza = PEON;
			}//Seguir haciendo la asiganci�n con else if()
		}
	}
}
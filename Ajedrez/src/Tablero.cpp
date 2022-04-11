#include <iostream>
#include "Tablero.h"
using namespace std;

void Tablero::setPosInit() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Asignación de color
			if (i == 1 || i == 0) {
				tab[i][j].color = BLANCO;
			}else if (i == 6 || i == 7) {
				tab[i][j].color = NEGRO;
			}
			else {
				tab[i][j].color = NO_COLOR;
			}
			
			//Asiganción de tipo
			if (i == 1 || i == 6) {
				tab[i][j].pieza = PEON;
			}
			else if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
				tab[i][j].pieza = TORRE;
			}
			else if ((i == 0 || i == 7) && (j == 1 || j == 6)) {
				tab[i][j].pieza = CABALLO;
			}
			else if ((i == 0 || i == 7) && (j == 2 || j == 5)) {
				tab[i][j].pieza = ALFIL;
			}
			else if ((i == 0 || i == 7) && j == 4) {
				tab[i][j].pieza = REY;
			}
			else if ((i == 0 || i == 7) && j == 3) {
				tab[i][j].pieza = REINA;
			}
			else {
				tab[i][j].pieza = NO_PIEZA;
			}

			//Asignación de casilla
			tab[i][j].casilla.f = i;
			tab[i][j].casilla.c = j;
		}
	}
}

void Tablero::dibuja() {
	int aux = 0; //Variable auxiliar para pintar el color de fondo de la casilla
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j].dibuja(aux);//Llama al dibuja de pieza
			aux++;
		}
		aux++;
	}

	//Dibuja el fondo marrón
	glColor3ub(160, 64, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, -0.5f);
	glVertex3f(-0.5, 8.5, -0.5f);
	glVertex3f(8.5, 8.5, -0.5f);
	glVertex3f(8.5, -0.5, -0.5f);
	glEnd();
}

Casilla Tablero::getCasillaOrigen(int x, int y) { //Devuelve la casilla de origen en función de las coordenadas x,y del ratón
	Casilla origen;
	origen.c = floor((x - 125) / 69);
	origen.f = 7 - floor((y - 25) / 69);
	return origen;
}

Casilla Tablero::getCasillaDestino(int x, int y) { //Devuelve la casilla de destino en función de las coordenadas x,y del ratón
	Casilla destino;
	destino.c = floor((x - 125) / 69);
	destino.f = 7 - floor((y - 25) / 69);
	return destino;
}

bool Tablero::checkMove(int fo, int co, int fd, int cd) {
	return false;
}
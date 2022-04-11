#include <iostream>
#include <string>
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

			//Asignaci�n de casilla
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

	//Dibuja el fondo marr�n
	glColor3ub(160, 64, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, -0.5f);
	glVertex3f(-0.5, 8.5, -0.5f);
	glVertex3f(8.5, 8.5, -0.5f);
	glVertex3f(8.5, -0.5, -0.5f);
	glEnd();
}

int Tablero::getColor(Casilla cas){
	return tab[cas.f][cas.c].color;
}

bool Tablero::validarMov(Casilla co, Casilla cd){
	
	return tab[co.f][co.c].validarMov(cd);
}

void Tablero::actualiza(Casilla co, Casilla cd) {
	//Hay dos posibilidades: movimiento a casilla vac�a o comer pieza
	//Conviene borrar la casilla de origen (NO_PIEZA y NO_COLOR) y sobreescribir los datos en la de destino
	tab[cd.f][cd.c].pieza = tab[co.f][co.c].pieza;
	tab[cd.f][cd.c].color = tab[co.f][co.c].color;
	tab[co.f][co.c].color = NO_COLOR;
	tab[co.f][co.c].pieza = NO_PIEZA;
	
}

string Tablero::to_string() {
	stringstream str;
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			str << tab[i][j].pieza << " " << tab[i][j].color << "|";
		}
		str << endl;
	}
	return str.str();
}

ostream& Tablero::print(ostream& o){
	o << to_string();
	return o;
}


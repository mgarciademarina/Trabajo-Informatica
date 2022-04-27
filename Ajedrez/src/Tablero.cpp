#include <iostream>
#include <string>
#include "Tablero.h"
using namespace std;

Tablero::Tablero() {
	tab = new Pieza * [n];
	for (int i = 0; i < n; i++) {
		tab[i] = new Pieza[n];
	}

	//Matriz de posibles movimientos
	pmov = new int* [n];
	for (int i = 0; i < n; i++) {
		pmov[i] = new int[n];
	}
}

Tablero::~Tablero() {
	for (int i = 0; i < n; i++) {
		delete[] tab[i];
	}
	delete[] tab;

	//Matriz de posibles movimientos
	for (int i = 0; i < n; i++) {
		delete[] pmov[i];
	}
	delete[] pmov;
}

void Tablero::setPosInit() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Asignación de color
			if (i == 1 || i == 0) { tab[i][j].color = BLANCO;}
			else if (i == 6 || i == 7) {tab[i][j].color = NEGRO;}
			else {tab[i][j].color = NO_COLOR;}
			
			//Asiganción de tipo
			if (i == 1 || i == 6) { tab[i][j].pieza = PEON; }
			else if ((i == 0 || i == 7) && (j == 0 || j == 7)) { tab[i][j].pieza = TORRE; }
			else if ((i == 0 || i == 7) && (j == 1 || j == 6)) { tab[i][j].pieza = CABALLO; }
			else if ((i == 0 || i == 7) && (j == 2 || j == 5)) { tab[i][j].pieza = ALFIL; }
			else if ((i == 0 || i == 7) && j == 4) { tab[i][j].pieza = REY; }
			else if ((i == 0 || i == 7) && j == 3) {tab[i][j].pieza = REINA;}
			else {tab[i][j].pieza = NO_PIEZA;}

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
			tab[i][j].dibuja(aux, pmov[i][j]);//Llama al dibuja de pieza
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

int Tablero::getColor(Casilla cas){
	return tab[cas.f][cas.c].color;
}


int Tablero::validarEnroque(Casilla co, Casilla cd) {

	if ((tab[co.f][co.c].moved != 0) || (tab[cd.f][cd.c].moved != 0)) return 0;	//evalua si las piezas se han movido
	else if ((tab[co.f][co.c].pieza != REY) || (tab[cd.f][cd.c].pieza != TORRE))  return 0;	//evalua si es rey y torre
	else if (tab[co.f][co.c].color != tab[cd.f][cd.c].color) return 0;	//evalua si son del mismo color

	else if (co.c > cd.c) return 1; //enroque largo
	else return -1;	//enroque corto

}

bool Tablero::validarMov(Casilla co, Casilla cd){
	
	if (validarEnroque(co, cd) != 0) return Torre::Mov(cd, co, tab);
	
	if (tab[co.f][co.c].color == tab[cd.f][cd.c].color) {
		return false;
	}
	else {
		bool R = false;
		switch (tab[co.f][co.c].pieza) {
		case PEON:
			if (((tab[co.f][co.c].color == BLANCO)&&(tab[cd.f][cd.c].color == NEGRO))||((tab[co.f][co.c].color == NEGRO)&&(tab[cd.f][cd.c].color == BLANCO)))
			{ R=Peon::Comer(cd, co, tab[co.f][co.c].color);} //Si hay una Pieza de Negro en el destino de un peon blanco o al reves se llama al metodo que comprueva el movimiento de mover
			else {R = Peon::Mov(cd, co, tab[co.f][co.c].color);}
			break;
		case TORRE:
			R = Torre::Mov(cd, co, tab); //Completo
			break;
		case CABALLO:
			R = Caballo::Mov(cd, co); //Como el caballo puede saltar ya está completo
			break;
		case ALFIL:
			R = Alfil::Mov(cd, co, tab); //Completo
			break;
		case REINA:
			R = Reina::Mov(cd, co, tab); //Completo
			break;
		case REY:
			R = Rey::Mov(cd, co, tab); //Completo a falta del enroque 
			break;
		}
		return R;
	}
}

void Tablero::actualiza(Casilla co, Casilla cd) {
	//Hay dos posibilidades: movimiento a casilla vacía o comer pieza
	//Conviene borrar la casilla de origen (NO_PIEZA y NO_COLOR) y sobreescribir los datos en la de destino
	tab[cd.f][cd.c].pieza = tab[co.f][co.c].pieza;
	tab[cd.f][cd.c].color = tab[co.f][co.c].color;
	
	tab[cd.f][cd.c].moved = 1;

	tab[co.f][co.c].color = NO_COLOR;
	tab[co.f][co.c].pieza = NO_PIEZA;
	
}

void Tablero::posiblesMov(Casilla co) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (validarMov(co, tab[i][j].casilla)) {
					pmov[i][j] = 1;
			}
		}
	}
}

void Tablero::setMovInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pmov[i][j] = 0;
		}
	}
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

bool Tablero::jaque() {
	int i, j, jaque = 0;
	Casilla rb, rn;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (tab[i][j].pieza == REY && tab[i][j].color == NEGRO) {
				rn = tab[i][j].casilla;
			}
			else if (tab[i][j].pieza == REY && tab[i][j].color == BLANCO) {
				rb = tab[i][j].casilla;
			}
		}
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (tab[i][j].pieza !=NO_PIEZA && tab[i][j].color == NEGRO) {
					if (validarMov(tab[i][j].casilla, rb)) {
						jaque++;
					}
			}
			else if (tab[i][j].color == BLANCO) {
				if (validarMov(tab[i][j].casilla, rn)) {
					jaque++;
				}
			}
		}
	}
	if (jaque > 0) {
		return true;
	}
	else {
		return false;
	}
}


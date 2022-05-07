#include "CoordinadorAjedrez.h"

CoordinadorAjedrez::CoordinadorAjedrez() {
	estado = INICIO;
}

CoordinadorAjedrez::~CoordinadorAjedrez() {

}

void CoordinadorAjedrez::dibuja() {
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/fuente.ttf", 16);
		ETSIDI::printxy("Ajedrez", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("WenasnoCHESS", 2, 1);
	}
	else if (estado == JUEGO) {
		ajedrez.dibuja();
	}
}

void CoordinadorAjedrez::tecla(unsigned char key) {
	if (estado == INICIO) {
		ajedrez.inicializa();
		if (key == 'e'){
			estado = JUEGO;
		}
		else if (key == 's') {
			exit(0);
		}
		
	}
	else if (estado == JUEGO) {
		if (key == 's') {
			exit(0); //Salir del juego si se pulsa la tecla s
		}
	}
}

void CoordinadorAjedrez::jugada(int button, int state, int x, int y) {
	if (estado == JUEGO) {
		ajedrez.jugada(button, state, x, y);
	}
}

void CoordinadorAjedrez::jaque() {
	if (estado == JUEGO) {
		ajedrez.jaque();
	}
}

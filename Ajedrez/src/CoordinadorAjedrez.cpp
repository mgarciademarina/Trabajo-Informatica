#include "CoordinadorAjedrez.h"

CoordinadorAjedrez::CoordinadorAjedrez() {
	estado = INICIO;
}

CoordinadorAjedrez::~CoordinadorAjedrez() {

}

void CoordinadorAjedrez::dibuja() {
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, 
			0.0, 7.5, 0.0, 
			0.0, 1.0, 0.0); 

		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("Ajedrez", -5, 8);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/fuente2.otf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("WenasnoCHESS", 2, 1);
	}
	else if (estado == JUEGO) {
		ajedrez.dibuja();
	}
	else if (estado == JAQUEBLANCO) {
		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("JAQUE!!!", -1, 8);
	}
	else if (estado == JAQUENEGRO) {
		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("JAQUE!!!", -1, 8);
	}
	else if (estado == PAUSE) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("Pausa", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 12);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("WenasnoCHESS", 2, 1);
	}
	else if (estado == FIN) {
		gluLookAt(4, 4, 12,
			4, 4, 0.0,
			0.0, 1.0, 0.0);

		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("JAQUE MATE!!!!!", 2, 5);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 12);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA LA REVANCHA", 1, 4);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", 1, 3);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("WenasnoCHESS", 4, 1);
	}
}

void CoordinadorAjedrez::tecla(unsigned char key) {
	if (estado == INICIO) {
		ajedrez.inicializa();
		if (key == 'e'){
			estado = JUEGO;
			ETSIDI::play("sonidos/tablero.wav");
		}
		else if (key == 's') {
			exit(0);
		}
		
	}
	else if (estado == JUEGO || estado == JAQUEBLANCO || estado == JAQUENEGRO) {
		if (key == 'p') {
			estado = PAUSE;
		}
	}
	else if (estado == PAUSE) {
		if (key == 's') {
			exit(0);
		}
		else if (key == 'c' && jaqueBlanco) {
			estado = JAQUEBLANCO;
		}
		else if (key == 'c' && jaqueNegro) {
			estado = JAQUENEGRO;
		}
		else if (key == 'c' && !jaqueNegro && !jaqueBlanco) {
			estado = JUEGO;
		}
	}
	else if (estado == FIN) {
		if (key == 'c') {
			estado = INICIO;
		}
		else if (key == 's') {
			exit(0);
		}
	}
}

void CoordinadorAjedrez::jugada(int button, int state, int x, int y) {
	if (estado == JUEGO) {
		ajedrez.jugada(button, state, x, y);
	}if (estado == JAQUEBLANCO || estado == JAQUENEGRO) {
		ajedrez.jugada(button, state, x, y);
	}
}

void CoordinadorAjedrez::jaque() {
	if (estado == JUEGO) {
		if (ajedrez.jaque() == 1) {
			estado = JAQUEBLANCO;
			jaqueBlanco = true;
		}
		else if (ajedrez.jaque() == 2) {
			estado = JAQUENEGRO;
			jaqueNegro = true;
		}
		else if (ajedrez.jaque() == 3 || ajedrez.jaque() == 4) {
			estado = FIN;
		}
	}
	else if (estado == JAQUEBLANCO || estado == JAQUENEGRO) {
		if (ajedrez.jaque() == 0) { 
			jaqueNegro = false;
			jaqueBlanco = false;
			estado = JUEGO; 
		}
		else if (ajedrez.jaque() == 3 || ajedrez.jaque() == 4) { estado = FIN; }
	}
}

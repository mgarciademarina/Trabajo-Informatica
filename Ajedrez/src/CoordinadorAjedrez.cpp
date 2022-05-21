#include "CoordinadorAjedrez.h"

CoordinadorAjedrez::CoordinadorAjedrez() {
	estado = INICIO;
}

CoordinadorAjedrez::~CoordinadorAjedrez() {

}

void CoordinadorAjedrez::dibuja() {
	if (estado == INICIO) {											//Dibuja la pantalla de inicio
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
		ETSIDI::printxy("PULSE LA TECLA -L- PARA CARGAR LA ULTIMA PARTIDA GUARDADA", -5, 5);
		ETSIDI::printxy("WenasnoCHESS", 2, 1);
	}
	else if (estado == JUEGO) {
		ajedrez.dibuja();											//Dibuja el tablero con las piezas
	}
	else if (estado == JAQUEBLANCO) {								//Incluye aviso de jaque a rey blanco
		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("JAQUE AL REY BLANCO!!!", -1, 8);
	}
	else if (estado == JAQUENEGRO) {								//Incluye aviso de jaque a rey negro
		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("JAQUE AL REY NEGRO!!!", -1, 8);
	}
	else if (estado == PAUSE) {										//Pantalla de pausa 
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("PAUSA", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 12);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -R- PARA REINICIAR LA PARTIDA", -5, 5);
		ETSIDI::printxy("PULSE LA TECLA -G- PARA GUARDAR LA PARTIDA", -5, 4);
		ETSIDI::printxy("WenasnoCHESS", 2, 1);
	}
	else if (estado == FIN) {										//Pantalla de fin
		ajedrez.dibuja();

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(205, 92, 92);
		glVertex3f(1, 2, 0.1);
		glVertex3f(1, 6, 0.1);
		glVertex3f(7, 6, 0.1);
		glVertex3f(7, 2, 0.1);
		glEnd();
		glEnable(GL_LIGHTING);

		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("ENHORABUENA HAS GANADO!!!!", 2, 5);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/fuente2.otf", 12);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", 3, 4);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", 3, 3);
	}
}

void CoordinadorAjedrez::tecla(unsigned char key) {	//Navegación por los menús con el teclado
	if (estado == INICIO) {
		ajedrez.inicializa();
		if (key == 'e'){
			estado = JUEGO;
			ETSIDI::play("sonidos/tablero.wav");
		}
		else if (key == 's') {
			exit(0);
		}
		else if (key == 'l') {
			ajedrez.cargar();
			estado = JUEGO;
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
		else if (key == 'r') {
			estado = INICIO;
			ajedrez.setTurno(0);
		}
		else if(key=='g') {
			ajedrez.guardar();	
		}
	}
	else if (estado == FIN) {
		if (key == 'c') {
			estado = INICIO;
			ajedrez.setTurno(0);
		}
		else if (key == 's') {
			exit(0);
		}
	}
}

void CoordinadorAjedrez::jugada(int button, int state, int x, int y) { //En qué estados se pueden mover las piezas
	if (estado == JUEGO) {
		ajedrez.jugada(button, state, x, y);
	}if (estado == JAQUEBLANCO || estado == JAQUENEGRO) {
		ajedrez.jugada(button, state, x, y);
	}
}

void CoordinadorAjedrez::jaque() { //Transiciones entre estados relacionas con jaque y jaque mate en función del valor devuelto
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

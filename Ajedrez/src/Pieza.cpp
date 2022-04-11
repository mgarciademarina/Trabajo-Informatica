#include "Pieza.h"

Pieza::Pieza() {

}

Pieza::Pieza(const Pieza& p){
	pieza = p.pieza;
	color = p.color;
	casilla = p.casilla;
}

Pieza::~Pieza(){

}

void Pieza::dibuja(int flag) {
	if (flag %2 == 0) {
		glColor3ub(0, 0, 0);
	}
	else {
		glColor3ub(255, 255, 255);
	}
	
	//Cada casilla mide 1x1, empiezan en el (0,0) esquina inf izda del tablero
	glBegin(GL_POLYGON);
	glVertex3f(casilla.c, casilla.f, 0.0f);
	glVertex3f(casilla.c, casilla.f + 1, 0.0f);
	glVertex3f(casilla.c + 1, casilla.f + 1, 0.0f);
	glVertex3f(casilla.c + 1, casilla.f, 0.0f);
	glEnd();

	//Falta cada textura de las piezas en función del tipo de pieza y color
	switch (pieza) {
	case PEON:
		//Textura de peón blanco o negro
		break;
	case TORRE:
		//Textura de torre blanca o negra
		break;
	case ALFIL:
		//Textura de alfil blanco o negro
		break;
	case CABALLO:
		//Textura de Caballo negro o blanco
		break;
	case REY:
		//Textura de rey negro o blanco
		break;
	case REINA:
		//Textura de reina negro o blanco
		break;
	default:
		break;
	}

}

bool Pieza::validarMov(Casilla cd){

	return false;
}



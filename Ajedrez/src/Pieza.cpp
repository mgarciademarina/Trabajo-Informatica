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
	glEnable(GL_TEXTURE_2D);

	switch (pieza) {
	case PEON:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Peon_B.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Peon_N.png").id); }
		break;
	case TORRE:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Torre_B.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Torre_N.png").id); }
		break;
	case ALFIL:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Alfil_B.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Alfil_N.png").id); }
		break;
	case CABALLO:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Caballo_B.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Caballo_N.png").id); }
		break;
	case REY:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Rey_B.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Rey_N.png").id); }
		break;
	case REINA:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Reina_B.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Reina_N.png").id); }
		break;
	case NO_PIEZA:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/vacio.png").id);
		break;
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	if (flag % 2 == 0) {
		glColor3ub(160, 64, 0);
	}
	else {
		glColor3ub(255, 255, 255);
	}
	glTexCoord2d(1, 1); glVertex3f(casilla.c, casilla.f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(casilla.c, casilla.f + 1, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(casilla.c + 1, casilla.f + 1, 0.0f);
	glTexCoord2d(0, 1); glVertex3f(casilla.c + 1, casilla.f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

bool Pieza::validarMov(Casilla cd) {
	
	bool R=false;
	switch (pieza) {
	case PEON:
		R=Peon::Mov(cd,  casilla, color);
		break;
	case TORRE:
		R=Torre::Mov( cd,  casilla);
		break;
	case CABALLO:
		R=Caballo::Mov( cd, casilla);
			break;
	case ALFIL:
		R=Alfil::Mov( cd,  casilla);
		break;
	case REINA:
		R=Reina::Mov(cd,  casilla);
		break;
	case REY:
		R=Rey::Mov( cd, casilla);
		break;
	}
	return R;
}


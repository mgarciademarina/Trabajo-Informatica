#include "Pieza.h"

Pieza::Pieza() {
	moved = 0;
}

Pieza::Pieza(const Pieza& p){
	pieza = p.pieza;
	color = p.color;
	casilla = p.casilla;
	moved = p.moved;
}

Pieza::~Pieza(){

}

void Pieza::dibuja(int flag, int auxmov) { //Cada pieza se dibuja a sí misma 
	glEnable(GL_TEXTURE_2D);

	switch (pieza) {	//Carga las texturas en función del tipo de pieza
	case PEON:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Peon_B_Mod.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Peon_N_Mod.png").id); }
		break;
	case TORRE:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Torre_B_Mod.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Torre_N_Mod.png").id); }
		break;
	case ALFIL:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Alfil_B_Mod.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Alfil_N_Mod.png").id); }
		break;
	case CABALLO:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Caballo_B_Mod.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Caballo_N_Mod.png").id); }
		break;
	case REY:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Rey_B_Mod.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Rey_N_Mod.png").id); }
		break;
	case REINA:
		if (color == 0) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Reina_B_Mod.png").id); }
		else if (color == 1) { glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Reina_N_Mod.png").id); }
		break;
	case NO_PIEZA:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/vacio.png").id);
		break;
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	//Carga el color de fondo de la casilla teniendo en cuenta la ayuda al movimiento
	if (flag % 2 == 0 && auxmov == 0) {
		glColor3ub(160, 64, 0);
		
	}
	else if (flag % 2 != 0 && auxmov == 0) {
		glColor3ub(255, 255, 255);
		
	}
	else if (flag % 2 == 0 && auxmov == 1) {
		glColor3ub(66, 99, 20);
	}
	else if (flag % 2 != 0 && auxmov == 1) {
		glColor3ub(131, 169, 79);
	}
	glTexCoord2d(1, 1); glVertex3f(casilla.c, casilla.f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(casilla.c, casilla.f + 1, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(casilla.c + 1, casilla.f + 1, 0.0f);
	glTexCoord2d(0, 1); glVertex3f(casilla.c + 1, casilla.f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}


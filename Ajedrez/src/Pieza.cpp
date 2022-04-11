#include "Pieza.h"

void Pieza::dibuja(int flag) {
	if (flag %2 == 0) {
		glColor3ub(0, 0, 0);
	}
	else {
		glColor3ub(255, 255, 255);
	}
	
	//Texturas

	glBegin(GL_POLYGON);
	glVertex3f(casilla.c, casilla.f, 0.0f);
	glVertex3f(casilla.c, casilla.f + 1, 0.0f);
	glVertex3f(casilla.c + 1, casilla.f + 1, 0.0f);
	glVertex3f(casilla.c + 1, casilla.f, 0.0f);
	glEnd();

}

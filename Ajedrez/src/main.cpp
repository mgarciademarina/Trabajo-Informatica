#include "freeglut.h"
#include "CoordinadorAjedrez.h"

CoordinadorAjedrez miajedrez;

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y); 	
void OnMouseDown(int button, int state, int x, int y);

int main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseDown);
	
	glutMainLoop();

	return 0;
}

void OnDraw(void){
		
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	miajedrez.dibuja();

	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t){

	miajedrez.tecla(key);

	glutPostRedisplay();
}

void OnMouseDown(int button, int state, int x, int y) {
	//Solo permite la jugada si se pulsa el botón izdo. dentro del tablero
	//Si se pulsa fuera no hace nada
	//Dependiente del tamaño de la ventana de juego, si se cambia no funciona
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>=125 && x<= 677 && y>= 25 && y <= 577) {
		miajedrez.jugada(button, state, x, y);
	}
	
}

void OnTimer(int value){

	miajedrez.jaque();

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

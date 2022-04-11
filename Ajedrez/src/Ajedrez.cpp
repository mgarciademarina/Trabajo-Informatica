#include "Ajedrez.h"
using namespace std;

void Ajedrez::dibuja() {
	gluLookAt(4, 4, 12,	// posicion del ojo
		4, 4, 0,			// hacia que punto mira  
		0.0, 1.0, 0.0);		// definimos hacia arriba (eje Y)  

	tablero.dibuja();

}

void Ajedrez::inicializa() {
	tablero.setPosInit();

}

void Ajedrez::jugada(int button, int state, int x, int y) {
	//Implementa una jugada
	
	
	
}

bool Ajedrez::validarTurno(int color){
	if (turno % 2 == 0 && color == 0) { return true; }
	else if (turno % 2 != 0 && color == 1) { return true; }
	else { return false; }
}

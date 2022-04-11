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

int Ajedrez::jugada(int button, int state, int x, int y) {
	//Implementa una jugada con los clics del ratón
	if (origen.f == -10 && origen.c == -10) {
		origen = getCasilla(x, y);
		if (!validarTurno(tablero.getColor(origen))) {
			cout << "Casilla no válida!" << endl;
			origen.f = origen.c = -10;
			return 0;
		}
		cout << origen.f << " " << origen.c << endl;
	}
	else if (origen.f != -10 && origen.c != -10 && destino.f == -10 && destino.c == -10) {
		destino = getCasilla(x, y);
		//Lamada a función que valida el movmiento
		//Actualizar tablero si la jugada es válida
		//Hacer turno++ al final de la jugada
		cout << destino.f << " " << destino.c << endl;
	}
	
	
}

bool Ajedrez::validarTurno(int color){
	if (turno % 2 == 0 && color == 0) { return true; }
	else if (turno % 2 != 0 && color == 1) { return true; }
	else { return false; }
}

Casilla Ajedrez::getCasilla(int x, int y) { //Devuelve la casilla en función de las coordenadas x,y del ratón
	Casilla casilla;
	casilla.c = floor((x - 125) / 69);
	casilla.f = 7 - floor((y - 25) / 69);
	return casilla;
}

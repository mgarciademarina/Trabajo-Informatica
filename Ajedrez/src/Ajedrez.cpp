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
	//Implementa una jugada con los clics del ratón
	
	
	
}

bool Ajedrez::validarTurno(int color){
	if (turno % 2 == 0 && color == 0) { return true; }
	else if (turno % 2 != 0 && color == 1) { return true; }
	else { return false; }
}

Casilla Ajedrez::getCasillaOrigen(int x, int y) { //Devuelve la casilla de origen en función de las coordenadas x,y del ratón
	Casilla origen;
	origen.c = floor((x - 125) / 69);
	origen.f = 7 - floor((y - 25) / 69);
	return origen;
}

Casilla Ajedrez::getCasillaDestino(int x, int y) { //Devuelve la casilla de destino en función de las coordenadas x,y del ratón
	Casilla destino;
	destino.c = floor((x - 125) / 69);
	destino.f = 7 - floor((y - 25) / 69);
	return destino;
}

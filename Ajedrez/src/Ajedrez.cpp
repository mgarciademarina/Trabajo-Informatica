#include "Ajedrez.h"
using namespace std;

void Ajedrez::dibuja() {
	gluLookAt(4, 4, 12,	
		4, 4, 0,			
		0.0, 1.0, 0.0);		

	tablero.dibuja();

}

void Ajedrez::inicializa() {
	tablero.setPosInit();
	tablero.setMovInit();
}

int Ajedrez::jugada(int button, int state, int x, int y) { //Implementación de una jugada
	
	if (origen.f == HOME && origen.c == HOME) { //Si no hay origen seleccionado, se slecciona uno

		origen = getCasilla(x, y);

		if (!validarTurno(tablero.getColor(origen))) { //Si no es el turno o se pulsa una casilla vacía se borra el origen
			
			origen.f = origen.c = HOME;
			return 0;
		}
		tablero.posiblesMov(origen); //Muestra los posibles movimiento de la pieza seleccionada
		
	}
	else if (origen.f != HOME && origen.c != HOME && destino.f == HOME && destino.c == HOME) {	//Si ya está guarado el origen
																								//slecciona el destino
		destino = getCasilla(x, y);
		
		if (destino == origen) { //Si el origen es igual al destino, se borra el origen y el destino
			
			origen.f = origen.c = destino.f = destino.c = HOME; 
			tablero.setMovInit(); //Borra la matriz de ayuda el movimeinto
			return 0;

		}else if (!tablero.validarMov(origen, destino)) {//Si el movimiento no es válido borra el destino
			
			destino.f = destino.c = HOME;
			return 0;

		}
		
		else if ((tablero.validarEnroque(origen, destino)!=0) && tablero.validarMov(origen, destino)) {		//Si se dan condiciones de enroque y no hay piezas en medio 

			if (tablero.validarEnroque(origen, destino) > 0) {		//ENROQUE LARGO	
				tablero.actualiza(origen, { origen.f, origen.c - 2 });
				tablero.actualiza(destino, { destino.f, destino.c + 3 });
			}

			else if (tablero.validarEnroque(origen, destino) < 0) {		//ENROQUE CORTO
				tablero.actualiza(origen, { origen.f, origen.c + 2 });
				tablero.actualiza(destino, { destino.f, destino.c - 2 });
			}
			turno++; //Se completa el movimiento y se aumenta el turno
			origen.f = origen.c = destino.f = destino.c = HOME; //Se borran origen y destino
			tablero.setMovInit();
			ETSIDI::play("sonidos/piezas1.wav");
			return 0;

		}
		else { //Se valida el movimiento y no es enroque

			tablero.actualiza(origen, destino);						//Atualiza la matriz del tablero
			turno++;												//Aumenta el turno
			origen.f = origen.c = destino.f = destino.c = HOME;		//Resetea las casillas de origen y destino
			tablero.setMovInit();									//Resetea la matriz de ayuda al movimiento

			//Sonidos de movimiento
			int r = rand() % 4;
			switch (r) {
			case 0:
				ETSIDI::play("sonidos/piezas1.wav");
				break;
			case 1:
				ETSIDI::play("sonidos/piezas2.wav");
				break;
			case 2:
				ETSIDI::play("sonidos/piezas3.wav");
				break;
			case 3:
				ETSIDI::play("sonidos/piezas4.wav");
				break;
			}

		}
	}
	return 0;
}

bool Ajedrez::validarTurno(int color){
	
	if (turno % 2 == 0 && color == 0) { return true; }		//Turno par -> piezas blancas
	else if (turno % 2 != 0 && color == 1) { return true; }	//Turno impar -> piezas negras
	else { return false; }
	
}

Casilla Ajedrez::getCasilla(int x, int y) { //Devuelve la casilla en función de las coordenadas x,y del ratón
	Casilla casilla;
	casilla.c = floor((x - 125) / 69);		//Obtenido experimentalmente para el tamaño de ventana del juego
	casilla.f = 7 - floor((y - 25) / 69);	//Si se cambia el tamaño de ventana, esto no vale
	return casilla;
}

int Ajedrez::jaque() {
	return tablero.jaque(turno);
}

void Ajedrez::setTurno(int v) {
	turno = v;
}


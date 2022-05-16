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

int Ajedrez::jugada(int button, int state, int x, int y) {
	//Get Origen si el origen no está guardado ya, se dan valores por defecto de -10 para origen y destino
	if (origen.f == HOME && origen.c == HOME) {

		origen = getCasilla(x, y);

		if (!validarTurno(tablero.getColor(origen))) { //Si no es el turno o se pulsa una casilla vacía
			
			cout << "Casilla no valida!" << endl;
			origen.f = origen.c = HOME;
			return 0;
		}
		tablero.posiblesMov(origen);
		cout <<"Origen " << origen.f << " " << origen.c << endl;//Test
	}
	else if (origen.f != HOME && origen.c != HOME && destino.f == HOME && destino.c == HOME) {//Si ya está guarado el origen
		
		destino = getCasilla(x, y);
		
		if (destino == origen) {
			
			origen.f = origen.c = destino.f = destino.c = HOME; //Borra el origen si se pulsa la misma casilla
			tablero.setMovInit(); //Resetea la matriz de posibles movimientos
			cout << "Origen borrado" << endl;//Test
			return 0;

		}else if (!tablero.validarMov(origen, destino)) {//Si el movimiento no es válido borra el destino
			
			cout << "Destino no valido!" << endl;
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
			turno++;
			origen.f = origen.c = destino.f = destino.c = HOME;
			tablero.setMovInit();
			ETSIDI::play("sonidos/piezas1");
			return 0;

		}
		else {

			cout << "Destino " << destino.f << " " << destino.c << endl;//Test
			tablero.actualiza(origen, destino);
			turno++;
			origen.f = origen.c = destino.f = destino.c = HOME;
			tablero.setMovInit();

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
		//Poner las casillas origen y destino a -10 una vez finalizada la jugada
		
	}
	return 0;
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

int Ajedrez::jaque() {
	return tablero.jaque(turno);
}

void Ajedrez::setTurno(int v) {
	turno = v;
}


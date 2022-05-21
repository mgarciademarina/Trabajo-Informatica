#include <iostream>
#include <string>
#include "Tablero.h"
using namespace std;

Tablero::Tablero() {
	tab = new Pieza * [n];
	for (int i = 0; i < n; i++) {
		tab[i] = new Pieza[n];
	}

	//Matriz de posibles movimientos
	pmov = new int* [n];
	for (int i = 0; i < n; i++) {
		pmov[i] = new int[n];
	}
}

Tablero::~Tablero() {
	for (int i = 0; i < n; i++) {
		delete[] tab[i];
	}
	delete[] tab;

	//Matriz de posibles movimientos
	for (int i = 0; i < n; i++) {
		delete[] pmov[i];
	}
	delete[] pmov;
}

void Tablero::setPosInit() {	//Inicialización del tablero a las posiciones iniciales de las piezas
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Asignación de color
			if (i == 1 || i == 0) { tab[i][j].setColor(BLANCO);}
			else if (i == 6 || i == 7) {tab[i][j].setColor(NEGRO);}
			else {tab[i][j].setColor(NO_COLOR);}
			
			//Asiganción de tipo
			if (i == 1 || i == 6) { tab[i][j].setPieza(PEON); }
			else if ((i == 0 || i == 7) && (j == 0 || j == 7)) { tab[i][j].setPieza(TORRE); }
			else if ((i == 0 || i == 7) && (j == 1 || j == 6)) { tab[i][j].setPieza(CABALLO); }
			else if ((i == 0 || i == 7) && (j == 2 || j == 5)) { tab[i][j].setPieza(ALFIL); }
			else if ((i == 0 || i == 7) && j == 4) { tab[i][j].setPieza(REY); }
			else if ((i == 0 || i == 7) && j == 3) {tab[i][j].setPieza(REINA);}
			else {tab[i][j].setPieza(NO_PIEZA);}

			//Asignación de casilla
			tab[i][j].setCasilla(i, j);
		}
	}
}

void Tablero::dibuja() {
	int aux = 0; //Variable auxiliar para pintar el color de fondo de la casilla
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tab[i][j].dibuja(aux, pmov[i][j]);//Llama al dibuja de pieza
			aux++;
		}
		aux++;
	}

	//Dibuja el fondo marrón
	glColor3ub(160, 64, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, -0.5f);
	glVertex3f(-0.5, 8.5, -0.5f);
	glVertex3f(8.5, 8.5, -0.5f);
	glVertex3f(8.5, -0.5, -0.5f);
	glEnd();
}

int Tablero::getColor(Casilla cas){
	return tab[cas.f][cas.c].getColor();
}


int Tablero::validarEnroque(Casilla co, Casilla cd) {

	if ((tab[co.f][co.c].getMoved() != 0) || (tab[cd.f][cd.c].getMoved() != 0)) return 0;	//evalua si las piezas se han movido
	else if ((tab[co.f][co.c].getPieza() != REY) || (tab[cd.f][cd.c].getPieza() != TORRE))  return 0;	//evalua si es rey y torre
	else if (tab[co.f][co.c].getColor() != tab[cd.f][cd.c].getColor()) return 0;	//evalua si son del mismo color

	else if (co.c > cd.c) return 1; //enroque largo
	else return -1;	//enroque corto

}

bool Tablero::validarMov(Casilla co, Casilla cd){
	
	if (validarEnroque(co, cd) != 0) return Torre::Mov(cd, co, tab); //Comprobación de enroque si procede
	
	if (tab[co.f][co.c].getColor() == tab[cd.f][cd.c].getColor()) { //Si el color de destino es igual que el de origen invalida el movimiento
		return false;
	}
	else {
		bool R = false;
		switch (tab[co.f][co.c].getPieza()) { //Comprobación del movimiento en función de la pieza de origen y destino
		case PEON:
			if (((tab[co.f][co.c].getColor() == BLANCO)&&(tab[cd.f][cd.c].getColor() == NEGRO))||((tab[co.f][co.c].getColor() == NEGRO)&&(tab[cd.f][cd.c].getColor() == BLANCO)))
			{ R=Peon::Comer(cd, co, tab);} //Si hay una Pieza de Negro en el destino de un peon blanco o al reves se llama al metodo que comprueba el movimiento de comer
			else {R = Peon::Mov(cd, co, tab);}
			break;
		case TORRE:
			R = Torre::Mov(cd, co, tab); 
			break;
		case CABALLO:
			R = Caballo::Mov(cd, co); 
			break;
		case ALFIL:
			R = Alfil::Mov(cd, co, tab);
			break;
		case REINA:
			R = Reina::Mov(cd, co, tab); 
			break;
		case REY:
			R = Rey::Mov(cd, co); 
			break;
		}
		return R;
	}
}

void Tablero::actualiza(Casilla co, Casilla cd) {
	//Hay dos posibilidades: movimiento a casilla vacía o comer pieza
	//borra la casilla de origen (NO_PIEZA y NO_COLOR) y sobreescribe los datos en la de destino
	//Indica que la pieza se ha movido
	tab[cd.f][cd.c].setPieza(tab[co.f][co.c].getPieza());
	tab[cd.f][cd.c].setColor(tab[co.f][co.c].getColor());

	tab[cd.f][cd.c].setMoved(true);

	tab[co.f][co.c].setColor(NO_COLOR);
	tab[co.f][co.c].setPieza(NO_PIEZA);

}

int Tablero::posiblesMov(Casilla co) { 
	//Recorre el tablero y asigna valor 1 a la casilla de destino si la pieza se puede mover ahí
	//Matriz de ayuda al movimiento
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (validarMov(co, tab[i][j].getCasilla())) {
				pmov[i][j] = 1;
			}
		}
	}
	return 0;
}

void Tablero::setMovInit() { //Reseta la matriz de ayuda al movimiento a 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pmov[i][j] = 0;
		}
	}
}

int Tablero::jaque(int turn) {
	int a, b, i, j, jaque1 = 0, jaque2 = 0, comer1 = 0, comer2 = 0, proteger1 = 0, proteger2 = 0, mover1 = 0, mover2 = 0;
	Casilla rb, rn, EnemigoB, EnemigoN, posibles;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (tab[i][j].getPieza() == REY && tab[i][j].getColor() == NEGRO) {
				rn = tab[i][j].getCasilla();
			}
			else if (tab[i][j].getPieza() == REY && tab[i][j].getColor() == BLANCO) {
				rb = tab[i][j].getCasilla();
			}
		}//Obtener la posición de los reyes
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (tab[i][j].getPieza() != NO_PIEZA && tab[i][j].getColor() == NEGRO) {
				if (validarMov(tab[i][j].getCasilla(), rb)) {
					EnemigoN = tab[i][j].getCasilla();
					jaque1++;
				}
			}
			else if (tab[i][j].getPieza() != NO_PIEZA &&  tab[i][j].getColor() == BLANCO) {
				if (validarMov(tab[i][j].getCasilla(), rn)) {
					EnemigoB = tab[i][j].getCasilla();
					jaque2++;
				}
			}
		}//Saber si algún rey está en jaque
	}
	if (jaque2 > 0) {
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (tab[i][j].getColor() == NEGRO && tab[i][j].getCasilla() != rn) {
					if (validarMov(tab[i][j].getCasilla(), EnemigoB)) {
						comer2++;//significa que una pieza aliada se puede comer a la pieza enemiga
						for (a = 0; a < 8; a++) {
							for (b = 0; b < 8; b++) {
								if (tab[a][b].getColor() == BLANCO && validarMov(tab[a][b].getCasilla(), tab[i][j].getCasilla())) {
									if (Trayectoria(tab[a][b].getCasilla(), rn, rn) == 1) {
										comer2--;
									}//si la pieza que puede comer a la enemiga está bloqueando la trayectoria de otra pieza enemiga que
									//causaría otro jaque, no cuenta como movimiento posible
								}
							}
						}
					}
					if (Trayectoria(EnemigoB, rn, tab[i][j].getCasilla()) == 2) {
						proteger2++;//significa que una pieza aliada puede interponerse en el camino
					}
				}
				if (validarMov(rn, tab[i][j].getCasilla()) && Trayectoria(EnemigoB, tab[i][j].getCasilla(), NULL) == 0) {//si el rey puede ir y el enemigo no
					posibles = tab[i][j].getCasilla();
					mover2++;//significa que el rey se puede mover a una casilla no amenzada, ya sea porque esté libre o pueda comer una pieza enemiga
					for (a = 0; a < 8; a++) {
						for (b = 0; b < 8; b++) {
							if (mover2 > 0) {//para evitar valores negativos que afecten al conteo
								if (tab[a][b].getColor() == BLANCO && tab[a][b].getCasilla() != EnemigoB) {
									if (tab[posibles.f][posibles.c].getPieza() == NO_PIEZA) {//si la casilla era una casilla libre
										if (tab[a][b].getPieza() == PEON) {
											if ((abs(b - posibles.c) == 1 && a - posibles.f == -1)) {
												mover2--;
											}//si está amenazada por un peón enemigo, no cuenta como movimiento posible
										}
										else if (validarMov(tab[a][b].getCasilla(), posibles)) {
											mover2--;
										}//si está amenazada por pieza enemiga, no cuenta como movimiento posible
									}
									else if (tab[posibles.f][posibles.c].getColor() == BLANCO) {//si la casilla es una pieza enemiga que el rey puede comer
										tab[posibles.f][posibles.c].setColor(NEGRO);//para que funcione validarMov, ya que Trayectoria ignoraría la pieza
										if (validarMov(tab[a][b].getCasilla(), posibles)) {
											mover2--;
										}//si está amenazada por una pieza enemiga, no cuenta como movimiento posible
										tab[posibles.f][posibles.c].setColor(BLANCO);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (jaque1 > 0) {
		for (i = 7; i >= 0; i--) {
			for (j = 7; j >= 0; j--) {
				if (tab[i][j].getColor() == BLANCO && tab[i][j].getCasilla() != rb) {
					if (validarMov(tab[i][j].getCasilla(), EnemigoN)) {
						comer1++;
						for (a = 7; a >= 0; a--) {
							for (b = 7; b >= 0; b--) {
								if (tab[a][b].getColor() == NEGRO && validarMov(tab[a][b].getCasilla(), tab[i][j].getCasilla())) {
									if (Trayectoria(tab[a][b].getCasilla(), rb, rb) == 1) {
										comer1--;
									}
								}
							}
						}
					}
					if (Trayectoria(EnemigoN, rb, tab[i][j].getCasilla()) == 2) {
						proteger1++;
					}
				}
				if (validarMov(rb, tab[i][j].getCasilla()) && Trayectoria(EnemigoN, tab[i][j].getCasilla(), NULL) == 0) {
					posibles = tab[i][j].getCasilla();
					mover1++;
					for (a = 7; a >= 0; a--) {
						for (b = 7; b >= 0; b--) {
							if (mover1 > 0) {
								if (tab[a][b].getColor() == NEGRO && tab[a][b].getCasilla() != EnemigoN) {
									if (tab[posibles.f][posibles.c].getPieza() == NO_PIEZA) {
										if (tab[a][b].getPieza() == PEON) {
											if ((abs(b - posibles.c) == 1 && a - posibles.f == 1)) {
												mover1--;
											}
										}
										else if (validarMov(tab[a][b].getCasilla(), posibles)) {
											mover1--;
										}
									}
									else if (tab[posibles.f][posibles.c].getColor() == NEGRO) {
										tab[posibles.f][posibles.c].setColor(BLANCO);
										if (validarMov(tab[a][b].getCasilla(), posibles)) {
											mover1--;
										}
										tab[posibles.f][posibles.c].setColor(NEGRO);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//cout << jaque1 << "/" << comer1 << "/" << mover1 << "/" << proteger1 << endl;
	//cout << jaque2 << "/" << comer2 << "/" << mover2 << "/" << proteger2 << endl;//para ver como van variando las variables y si coinciden con lo que está pasando
	//en el tablero
	if (jaque1 > 0) {
		if (jaque1 > 1 && mover1 == 0) {
			return 3;
		}
		else if (comer1 == 0 && mover1 == 0 && (proteger1 == 0 || tab[EnemigoN.f][EnemigoN.c].getPieza() == CABALLO)) {
			return 3;
		}//Jaque Mate al blanco
		else if(turn % 2 == 0){
			return 1;
		}//Jaque al blanco si el turno es de los blancos
		else {
			return 3;
		}
	}
	if (jaque2 > 0) {
		if (jaque2 > 1 && mover2 == 0) {//si hay más de un jaque a la vez y no se puede mover, Jaque Mate
			return 4;
		}
		else if (comer2 == 0 && mover2 == 0 && (proteger2 == 0 || tab[EnemigoB.f][EnemigoB.c].getPieza() == CABALLO)) {
			//si hay jaque y no se cumple ninguno, o la pieza no tiene trayectoria, por lo que no se puede proteger, Jaque Mate
			return 4;
		}//Jaque Mate al negro
		else if(turn % 2 != 0){
			return 2;
		}//Jaque al negro si el tueno es de los negros
		else {
			return 4;
		}
	}
	else {
		return 0;
	}
}


int Tablero::Trayectoria(Casilla ori, Casilla des, Casilla prot) {
	int i = 0, j = 0, k = 0, l = 0;
	Casilla aux;
	aux = ori;
	if (ori != des) {
		if (tab[ori.f][ori.c].getPieza() == TORRE || tab[ori.f][ori.c].getPieza() == REINA) {
			if (ori.c == des.c) {
				do {
					if (ori.f - des.f > 0) {
						aux.f--;
					}
					else if (ori.f - des.f < 0) {
						aux.f++;
					}
					if (aux.f == des.f) {
						i++;
					}
					if (prot == des) {
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							l++;
						}//para ver si hay una pieza más entre el enmigo, el que puede comer pero está bloqueando y el rey
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].getPieza() == REY && tab[aux.f][aux.c].getColor() != tab[ori.f][ori.c].getColor()) {
								k--;
							}
						}//si en la casilla hay una pieza, que termine el do-while, pero si esa pieza es el rey opuesto, seguir para ver si la casilla
						//a la que quiere ir el rey seguiría amenazada por la pieza
					}
				} while ((aux.f != des.f) && k == 0 && l <= 1);
			}
			else if (ori.f == des.f) {
				do {
					if (ori.c - des.c > 0) {
						aux.c--;
					}
					else if (ori.c - des.c < 0) {
						aux.c++;
					}
					if (aux.c == des.c) {
						i++;
					}
					if (prot == des) {
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							l++;
						}
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].getPieza() == REY && tab[aux.f][aux.c].getColor() != tab[ori.f][ori.c].getColor()) {
								k--;
							}
						}//si en la casilla hay una pieza, que termine el do-while, pero si esa pieza es el rey opuesto, seguir para ver si la casilla
						//a la que quiere ir el rey seguiría amenazada por la pieza
					}
				} while ((aux.c != des.c) && k == 0 && l <= 1);
			}
		}
		if (tab[ori.f][ori.c].getPieza() == ALFIL || tab[ori.f][ori.c].getPieza() == REINA) {
			if (ori.f - des.f < 0) {
				do {
					if (ori.c - des.c > 0) {
						aux.c--;
						aux.f++;
					}
					else if (ori.c - des.c < 0) {
						aux.c++;
						aux.f++;
					}
					if (aux == des) {
						i++;
					}
					if (prot == des) {
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							l++;
						}
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].getPieza() == REY && tab[aux.f][aux.c].getColor() != tab[ori.f][ori.c].getColor()) {
								k--;
							}
						}//si en la casilla hay una pieza, que termine el do-while, pero si esa pieza es el rey opuesto, seguir para ver si la casilla
						//a la que quiere ir el rey seguiría amenazada por la pieza
					}
				} while ((aux.c != des.c && aux.f != des.f) && k == 0 && l <= 1);
			}
			else if (ori.f - des.f > 0) {
				do {
					if (ori.c - des.c > 0) {
						aux.c--;
						aux.f--;
					}
					else if (ori.c - des.c < 0) {
						aux.c++;
						aux.f--;
					}
					if (aux == des) {
						i++;
					}
					if (prot == des) {
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							l++;
						}
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].getPieza() != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].getPieza() == REY && tab[aux.f][aux.c].getColor() != tab[ori.f][ori.c].getColor()) {
								k--;
							}
						}//si en la casilla hay una pieza, que termine el do-while, pero si esa pieza es el rey opuesto, seguir para ver si la casilla
						//a la que quiere ir el rey seguiría amenazada por la pieza
					}
				} while ((aux.c != des.c && aux.f != des.f) && k == 0 && l <= 1);
			}
		}
	}
	if (i > 0) {
		if (j > 0) {
			return 2;
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}


string Tablero::to_string() { //Métodos para test unitarios, no se utilizan en el juego
	stringstream str;
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			str << tab[i][j].getPieza() << " " << tab[i][j].getColor() << "|";
		}
		str << endl;
	}
	return str.str();
}

ostream& Tablero::print(ostream& o) { //Métodos para test unitarios, no se utilizan en el juego
	o << to_string();
	return o;
}
void Tablero::guardar() {
	int i, j, fila, colum;
	char pieza, color;
	ofstream guarda("Partida.txt");
	for (i = 0; i <8; i++) {
		for (j = 0; j <8; j++) {
			switch (tab[i][j].pieza) {
			case PEON:
				pieza = 'P';
				break;
			case TORRE:
				pieza = 'T';
				break;
			case CABALLO:
				pieza = 'C';
				break;
			case ALFIL:
				pieza = 'A';
				break;
			case REY:
				pieza = 'R';
				break;
			case REINA:
				pieza = 'X';
				break;
			case NO_PIEZA:
				pieza = 'Q';
				break;
			}
			switch (tab[i][j].color) {
			case BLANCO:
				color = 'B';
				break;
			case NEGRO:
				color = 'N';
				break;
			case NO_COLOR:
				color = 'Q';
				break;
			}
			guarda << pieza << color << endl;
		}
	}
}
void Tablero::cargar() {
	string cas;
	int i, j;
	setPosInit();
	setMovInit();
	ifstream carga("Partida.txt");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			carga >> cas;
			cout << cas << endl;
			switch (cas[0]) {
			case 'P':
				tab[i][j].pieza = PEON;
				break;
			case 'T':
				tab[i][j].pieza = TORRE;
				break;
			case 'A':
				tab[i][j].pieza = ALFIL;
				break;
			case 'C':
				tab[i][j].pieza = CABALLO;
				break;
			case 'R':
				tab[i][j].pieza = REY;
				break;
			case 'X':
				tab[i][j].pieza = REINA;
				break;
			case 'Q':
				tab[i][j].pieza = NO_PIEZA;
				break;
			}
			switch (cas[1]) {
			case 'B':
				tab[i][j].color = BLANCO;
				break;
			case 'N':
				tab[i][j].color = NEGRO;
				break;
			case 'Q':
				tab[i][j].color = NO_COLOR;
				break;
			}
		}
	}
	carga.close();
}



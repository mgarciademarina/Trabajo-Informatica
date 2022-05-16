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

void Tablero::setPosInit() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Asignación de color
			if (i == 1 || i == 0) { tab[i][j].color = BLANCO;}
			else if (i == 6 || i == 7) {tab[i][j].color = NEGRO;}
			else {tab[i][j].color = NO_COLOR;}
			
			//Asiganción de tipo
			if (i == 1 || i == 6) { tab[i][j].pieza = PEON; }
			else if ((i == 0 || i == 7) && (j == 0 || j == 7)) { tab[i][j].pieza = TORRE; }
			else if ((i == 0 || i == 7) && (j == 1 || j == 6)) { tab[i][j].pieza = CABALLO; }
			else if ((i == 0 || i == 7) && (j == 2 || j == 5)) { tab[i][j].pieza = ALFIL; }
			else if ((i == 0 || i == 7) && j == 4) { tab[i][j].pieza = REY; }
			else if ((i == 0 || i == 7) && j == 3) {tab[i][j].pieza = REINA;}
			else {tab[i][j].pieza = NO_PIEZA;}

			//Asignación de casilla
			tab[i][j].casilla.f = i;
			tab[i][j].casilla.c = j;
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
	return tab[cas.f][cas.c].color;
}


int Tablero::validarEnroque(Casilla co, Casilla cd) {

	if ((tab[co.f][co.c].moved != 0) || (tab[cd.f][cd.c].moved != 0)) return 0;	//evalua si las piezas se han movido
	else if ((tab[co.f][co.c].pieza != REY) || (tab[cd.f][cd.c].pieza != TORRE))  return 0;	//evalua si es rey y torre
	else if (tab[co.f][co.c].color != tab[cd.f][cd.c].color) return 0;	//evalua si son del mismo color

	else if (co.c > cd.c) return 1; //enroque largo
	else return -1;	//enroque corto

}

bool Tablero::validarMov(Casilla co, Casilla cd){
	
	if (validarEnroque(co, cd) != 0) return Torre::Mov(cd, co, tab);
	
	if (tab[co.f][co.c].color == tab[cd.f][cd.c].color) {
		return false;
	}
	else {
		bool R = false;
		switch (tab[co.f][co.c].pieza) {
		case PEON:
			if (((tab[co.f][co.c].color == BLANCO)&&(tab[cd.f][cd.c].color == NEGRO))||((tab[co.f][co.c].color == NEGRO)&&(tab[cd.f][cd.c].color == BLANCO)))
			{ R=Peon::Comer(cd, co, tab);} //Si hay una Pieza de Negro en el destino de un peon blanco o al reves se llama al metodo que comprueva el movimiento de mover
			else {R = Peon::Mov(cd, co, tab);}
			break;
		case TORRE:
			R = Torre::Mov(cd, co, tab); //Completo
			break;
		case CABALLO:
			R = Caballo::Mov(cd, co); //Como el caballo puede saltar ya está completo
			break;
		case ALFIL:
			R = Alfil::Mov(cd, co, tab); //Completo
			break;
		case REINA:
			R = Reina::Mov(cd, co, tab); //Completo
			break;
		case REY:
			R = Rey::Mov(cd, co, tab); //Completo a falta del enroque 
			break;
		}
		return R;
	}
}

void Tablero::actualiza(Casilla co, Casilla cd) {
	//Hay dos posibilidades: movimiento a casilla vacía o comer pieza
	//Conviene borrar la casilla de origen (NO_PIEZA y NO_COLOR) y sobreescribir los datos en la de destino
	tab[cd.f][cd.c].pieza = tab[co.f][co.c].pieza;
tab[cd.f][cd.c].color = tab[co.f][co.c].color;

tab[cd.f][cd.c].moved = 1;

tab[co.f][co.c].color = NO_COLOR;
tab[co.f][co.c].pieza = NO_PIEZA;

}

int Tablero::posiblesMov(Casilla co) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (validarMov(co, tab[i][j].casilla)) {
				pmov[i][j] = 1;
				sum++;
			}
		}
	}
	return sum;
}

void Tablero::setMovInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pmov[i][j] = 0;
		}
	}
}

string Tablero::to_string() {
	stringstream str;
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			str << tab[i][j].pieza << " " << tab[i][j].color << "|";
		}
		str << endl;
	}
	return str.str();
}

ostream& Tablero::print(ostream& o) {
	o << to_string();
	return o;
}

int Tablero::jaque(int turn) {
	int a, b, i, j, jaque1 = 0, jaque2 = 0, comer1 = 0, comer2 = 0, proteger1 = 0, proteger2 = 0, mover1 = 0, mover2 = 0;
	Casilla rb, rn, EnemigoB, EnemigoN, posibles;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (tab[i][j].pieza == REY && tab[i][j].color == NEGRO) {
				rn = tab[i][j].casilla;
			}
			else if (tab[i][j].pieza == REY && tab[i][j].color == BLANCO) {
				rb = tab[i][j].casilla;
			}
		}//Obtener la posición de los reyes
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (tab[i][j].pieza != NO_PIEZA && tab[i][j].color == NEGRO) {
				if (validarMov(tab[i][j].casilla, rb)) {
					EnemigoN = tab[i][j].casilla;
					jaque1++;
				}
			}
			else if (tab[i][j].pieza != NO_PIEZA &&  tab[i][j].color == BLANCO) {
				if (validarMov(tab[i][j].casilla, rn)) {
					EnemigoB = tab[i][j].casilla;
					jaque2++;
				}
			}
		}//Saber si algún rey está en jaque
	}
	if (jaque2 > 0) {
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (tab[i][j].color == NEGRO && tab[i][j].casilla != rn) {
					if (validarMov(tab[i][j].casilla, EnemigoB)) {
						comer2++;//significa que una pieza aliada se puede comer a la pieza enemiga
						for (a = 0; a < 8; a++) {
							for (b = 0; b < 8; b++) {
								if (tab[a][b].color == BLANCO && validarMov(tab[a][b].casilla, tab[i][j].casilla)) {
									if (Trayectoria(tab[a][b].casilla, rn, rn) == 1) {
										comer2--;
									}//si la pieza que puede comer a la enemiga está bloqueando la trayectoria de otra pieza enemiga que
									//causaría otro jaque, no cuenta como movimiento posible
								}
							}
						}
					}
					if (Trayectoria(EnemigoB, rn, tab[i][j].casilla) == 2) {
						proteger2++;//significa que una pieza aliada puede interponerse en el camino
					}
				}
				if (validarMov(rn, tab[i][j].casilla) && Trayectoria(EnemigoB, tab[i][j].casilla, NULL) == 0) {//si el rey puede ir y el enemigo no
					posibles = tab[i][j].casilla;
					mover2++;//significa que el rey se puede mover a una casilla no amenzada, ya sea porque esté libre o pueda comer una pieza enemiga
					for (a = 0; a < 8; a++) {
						for (b = 0; b < 8; b++) {
							if (mover2 > 0) {//para evitar valores negativos que afecten al conteo
								if (tab[a][b].color == BLANCO && tab[a][b].casilla != EnemigoB) {
									if (tab[posibles.f][posibles.c].pieza == NO_PIEZA) {//si la casilla era una casilla libre
										if (tab[a][b].pieza == PEON) {
											if ((abs(b - posibles.c) == 1 && a - posibles.f == -1)) {
												mover2--;
											}//si está amenazada por un peón enemigo, no cuenta como movimiento posible
										}
										else if (validarMov(tab[a][b].casilla, posibles)) {
											mover2--;
										}//si está amenazada por pieza enemiga, no cuenta como movimiento posible
									}
									else if (tab[posibles.f][posibles.c].color == BLANCO) {//si la casilla es una pieza enemiga que el rey puede comer
										tab[posibles.f][posibles.c].color = NEGRO;//para que funcione validarMov, ya que Trayectoria ignoraría la pieza
										if (validarMov(tab[a][b].casilla, posibles)) {
											mover2--;
										}//si está amenazada por una pieza enemiga, no cuenta como movimiento posible
										tab[posibles.f][posibles.c].color = BLANCO;
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
				if (tab[i][j].color == BLANCO && tab[i][j].casilla != rb) {
					if (validarMov(tab[i][j].casilla, EnemigoN)) {
						comer1++;
						for (a = 7; a >= 0; a--) {
							for (b = 7; b >= 0; b--) {
								if (tab[a][b].color == NEGRO && validarMov(tab[a][b].casilla, tab[i][j].casilla)) {
									if (Trayectoria(tab[a][b].casilla, rb, rb) == 1) {
										comer1--;
									}
								}
							}
						}
					}
					if (Trayectoria(EnemigoN, rb, tab[i][j].casilla) == 2) {
						proteger1++;
					}
				}
				if (validarMov(rb, tab[i][j].casilla) && Trayectoria(EnemigoN, tab[i][j].casilla, NULL) == 0) {
					posibles = tab[i][j].casilla;
					mover1++;
					for (a = 7; a >= 0; a--) {
						for (b = 7; b >= 0; b--) {
							if (mover1 > 0) {
								if (tab[a][b].color == NEGRO && tab[a][b].casilla != EnemigoN) {
									if (tab[posibles.f][posibles.c].pieza == NO_PIEZA) {
										if (tab[a][b].pieza == PEON) {
											if ((abs(b - posibles.c) == 1 && a - posibles.f == 1)) {
												mover1--;
											}
										}
										else if (validarMov(tab[a][b].casilla, posibles)) {
											mover1--;
										}
									}
									else if (tab[posibles.f][posibles.c].color == NEGRO) {
										tab[posibles.f][posibles.c].color = BLANCO;
										if (validarMov(tab[a][b].casilla, posibles)) {
											mover1--;
										}
										tab[posibles.f][posibles.c].color = NEGRO;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << jaque1 << "/" << comer1 << "/" << mover1 << "/" << proteger1 << endl;
	cout << jaque2 << "/" << comer2 << "/" << mover2 << "/" << proteger2 << endl;//para ver como van variando las variables y si coinciden con lo que está pasando
	//en el tablero
	if (jaque1 > 0) {
		if (jaque1 > 1 && mover1 == 0) {
			return 3;
		}
		else if (comer1 == 0 && mover1 == 0 && (proteger1 == 0 || tab[EnemigoN.f][EnemigoN.c].pieza == CABALLO)) {
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
		else if (comer2 == 0 && mover2 == 0 && (proteger2 == 0 || tab[EnemigoB.f][EnemigoB.c].pieza == CABALLO)) {
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
		if (tab[ori.f][ori.c].pieza == TORRE || tab[ori.f][ori.c].pieza == REINA) {
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
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							l++;
						}//para ver si hay una pieza más entre el enmigo, el que puede comer pero está bloqueando y el rey
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].pieza == REY && tab[aux.f][aux.c].color != tab[ori.f][ori.c].color) {
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
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							l++;
						}
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].pieza == REY && tab[aux.f][aux.c].color != tab[ori.f][ori.c].color) {
								k--;
							}
						}//si en la casilla hay una pieza, que termine el do-while, pero si esa pieza es el rey opuesto, seguir para ver si la casilla
						//a la que quiere ir el rey seguiría amenazada por la pieza
					}
				} while ((aux.c != des.c) && k == 0 && l <= 1);
			}
		}
		if (tab[ori.f][ori.c].pieza == ALFIL || tab[ori.f][ori.c].pieza == REINA) {
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
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							l++;
						}
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].pieza == REY && tab[aux.f][aux.c].color != tab[ori.f][ori.c].color) {
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
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							l++;
						}
					}
					else {
						if (validarMov(prot, aux)) {
							j++;
						}
						if (tab[aux.f][aux.c].pieza != NO_PIEZA) {
							k++;
							if (tab[aux.f][aux.c].pieza == REY && tab[aux.f][aux.c].color != tab[ori.f][ori.c].color) {
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



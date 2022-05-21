#pragma once
#include "Ajedrez.h"

//Segundo coordinador del juego, implementa una sencilla máquina de estados

class CoordinadorAjedrez {
private:
	Ajedrez ajedrez;
	enum Estado {INICIO, JUEGO, JAQUEBLANCO, JAQUENEGRO, FIN, PAUSE};	//Estados de la máquina
	Estado estado;
	bool jaqueBlanco = false;											//Auxiliares para las transiciones entre estados
	bool jaqueNegro = false;											

public:
	CoordinadorAjedrez();
	~CoordinadorAjedrez();

	void dibuja();										//Gestiona lo que se muestar en las pantallas de cada estado
	void jugada(int button, int state, int x, int y);	//Determina en qúe momentos se puede jugar y en cuáles no
	void jaque();										//Gestión del jaque en diferenets estados
	void tecla(unsigned char key);						//COntrl de menús y máquina de estados por teclado

};

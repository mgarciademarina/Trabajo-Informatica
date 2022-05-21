#pragma once
#include "Ajedrez.h"

//Segundo coordinador del juego, implementa una sencilla m�quina de estados

class CoordinadorAjedrez {
private:
	Ajedrez ajedrez;
	enum Estado {INICIO, JUEGO, JAQUEBLANCO, JAQUENEGRO, FIN, PAUSE};	//Estados de la m�quina
	Estado estado;
	bool jaqueBlanco = false;											//Auxiliares para las transiciones entre estados
	bool jaqueNegro = false;											

public:
	CoordinadorAjedrez();
	~CoordinadorAjedrez();

	void dibuja();										//Gestiona lo que se muestar en las pantallas de cada estado
	void jugada(int button, int state, int x, int y);	//Determina en q�e momentos se puede jugar y en cu�les no
	void jaque();										//Gesti�n del jaque en diferenets estados
	void tecla(unsigned char key);						//COntrl de men�s y m�quina de estados por teclado

};

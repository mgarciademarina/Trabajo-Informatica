#pragma once
#include "Ajedrez.h"

class CoordinadorAjedrez {
private:
	Ajedrez ajedrez;
	enum Estado {INICIO, JUEGO};
	Estado estado;

public:
	CoordinadorAjedrez();
	~CoordinadorAjedrez();

	void dibuja();
	void jugada(int button, int state, int x, int y);
	void jaque();
	void tecla(unsigned char key);

};

#pragma once
#include "Ajedrez.h"

class CoordinadorAjedrez {
private:
	Ajedrez ajedrez;
	enum Estado {INICIO, JUEGO, JAQUEBLANCO, JAQUENEGRO, FIN, PAUSE};
	//Jaque -> Salida de texto por pantalla que indique a quien se le da jaque
	//Fin -> si jaque mate
	//Pause -> si se pulsa 'p' se para el juego
	Estado estado;
	bool jaqueBlanco = false; //para saber a donde volver desde la pausa
	bool jaqueNegro = false; //para saber a donde volver desde la pausa

public:
	CoordinadorAjedrez();
	~CoordinadorAjedrez();

	void dibuja();
	void jugada(int button, int state, int x, int y);
	void jaque();
	void tecla(unsigned char key);

};

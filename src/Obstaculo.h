#pragma once
#include "ObjetoMovil.h"
class Obstaculo : public ObjetoMovil
{
private:
	SpriteSequence sprite_obstaculo{ "imagenes/asteroide.png",1 };
	float radio;
	float daño;
public:
	Obstaculo();
	void dibuja();
	float getRadio() { return radio; }
	float getDano() { return daño; }
	

	friend class Interaccion;
};


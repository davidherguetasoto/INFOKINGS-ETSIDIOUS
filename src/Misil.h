#pragma once
#include "DisparoAliado.h"

class Misil : public DisparoAliado
{
private:
	SpriteSequence sprite_misil{ "imagenes/misil.png",1 };
public:
	Misil();
	void dibuja();
	friend class Interaccion;
};


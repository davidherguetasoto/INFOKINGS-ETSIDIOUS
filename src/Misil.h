#pragma once
#include "DisparoAliado.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;
class Misil : public DisparoAliado
{
private:
	SpriteSequence sprite_misil{ "imagenes/misil.png",1 };
public:
	Misil();
	virtual ~Misil();
	void dibuja();
	friend class Interaccion;
};


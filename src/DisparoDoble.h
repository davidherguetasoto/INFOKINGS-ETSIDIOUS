#pragma once
#include "DisparoAliado.h"
class DisparoDoble : public DisparoAliado
{
private:
	SpriteSequence sprite_doble{ "imagenes/laser.png",1 };
public:
	DisparoDoble();
	virtual ~DisparoDoble();
	void dibuja();
	friend class Interaccion;
};


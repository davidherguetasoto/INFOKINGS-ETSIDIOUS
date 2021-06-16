#pragma once
#include "disparo.h"

class DisparoAliado : public Disparo{
private:
	SpriteSequence sprite_DisparoAliado{ "imagenes/Disparo.png",1 };
public:
	friend class Interaccion;
	DisparoAliado();
	//Constructor sobrecargado para especificar el daño y tipo de los derivados.
	DisparoAliado(float daño,int tipo);
	void dibuja();
};


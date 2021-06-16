#pragma once
#include "disparo.h"
class DisparoEnemigo : public Disparo
{
private:
	SpriteSequence sprite_DisparoEnemigo{ "imagenes/Disparo.png",1 };
public:
	DisparoEnemigo(); 
	void dibuja();
	float getRadio() { return radio; }
	friend class Interaccion;
};


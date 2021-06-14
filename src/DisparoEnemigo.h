#pragma once
#include "disparo.h"
class DisparoEnemigo : public Disparo
{
private:
	SpriteSequence sprite_DisparoEnemigo{ "imagenes/Disparo.png",1 };
public:
	DisparoEnemigo();
	//Constructor sobrecargado para especificar el daño y tipo de los derivados.
	//Si no se especifica el tipo, será disparo enemigo estándar
	DisparoEnemigo(float daño, int tipo=DISPARO_ENEMIGO); 
	void dibuja();
	float getRadio() { return radio; }
	friend class Interaccion;
};


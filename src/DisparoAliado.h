#pragma once
#include "disparo.h"

class DisparoAliado : public Disparo{
private:
	SpriteSequence sprite_DisparoAliado{ "imagenes/Disparo.png",1 };
protected:
	//provisional para dibujarlos
	float radio;
public:
	friend class Interaccion;
	DisparoAliado();
	//Constructor sobrecargado para especificar el daño y tipo de los derivados.
	//Si no se especifica el tipo, será disparo aliado estándar
	DisparoAliado(float daño,int tipo=DISPARO_ALIADO);
	void dibuja();
	float getRadio() { return radio; }
};


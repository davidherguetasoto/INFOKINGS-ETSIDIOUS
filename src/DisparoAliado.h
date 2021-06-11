#pragma once
#include "disparo.h"
class DisparoAliado : public Disparo{
protected:
	//provisional para dibujarlos
	float radio;
public:
	friend class Interaccion;
	DisparoAliado();
	DisparoAliado(float daño,int tipo); //Constructor sobrecargado para crear los dsparos derivados con otro daño
	void dibuja();
	float getRadio() { return radio; }
};


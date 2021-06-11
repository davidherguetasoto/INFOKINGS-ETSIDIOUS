#pragma once
#include "disparo.h"
class DisparoAliado : public Disparo{
protected:
	//provisional para dibujarlos
	float radio;
public:
	friend class Interaccion;
	DisparoAliado();
	void dibuja();
	float getRadio() { return radio; }
};


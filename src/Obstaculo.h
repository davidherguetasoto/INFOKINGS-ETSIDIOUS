#pragma once
#include "ObjetoMovil.h"
class Obstaculo : public ObjetoMovil
{
	float radio;
public:
	Obstaculo();
	void dibuja();
	float getRadio() { return radio; }
	

	friend class Interaccion;
};


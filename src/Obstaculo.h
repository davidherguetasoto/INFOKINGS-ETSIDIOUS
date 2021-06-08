#pragma once
#include "ObjetoMovil.h"
class Obstaculo : public ObjetoMovil
{
	float radio;
public:
	Obstaculo();
	void Dibuja();
	

	friend class Interaccion;
};


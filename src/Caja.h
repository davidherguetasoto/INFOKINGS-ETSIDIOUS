#pragma once
//IMPLEMENTACION DE LA RELACION DE COMPOSICION
#include "Pared.h"
class Caja
{
public:
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
	Caja();
	virtual ~Caja();
	
	void dibuja();

	friend class Interaccion;
};
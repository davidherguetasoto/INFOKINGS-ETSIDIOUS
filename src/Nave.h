#pragma once
#include "ObjetoMovil.h"
class Nave : public ObjetoMovil
{
protected:
	float vida; //Vida de las naves
public:
	Nave();
	Nave(float vida);
	virtual void dibuja()=0;
	//añadir funcion para disparo (?)
};


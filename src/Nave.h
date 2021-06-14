#pragma once
#include "ObjetoMovil.h"
class Nave : public ObjetoMovil
{
protected:
	float vida; //Vida de las naves
public:
	Nave(float vida); //Hay que pasarle la vida para construir una nave
	virtual void dibuja()=0;
	float getVida();
	virtual	void setVida(float vida);

	//añadir funcion para disparo (?)
};


#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
class Nave : public ObjetoMovil
{
protected:
	float vida; //Vida de las naves

	//Provisional para dibujar
	float radio;
	float altura;
	ColorRGB color;
public:
	Nave();
	Nave(float vida, unsigned char red, unsigned char green, unsigned char blue);
	virtual void dibuja()=0;
	//añadir funcion para disparo
};


#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
class Nave : public ObjetoMovil
{
protected:
	float vida; //Vida de las naves
	//provisional
	float radio;
	float altura;
	ColorRGB color;
public:
	Nave();
	Nave(float vida, unsigned char red, unsigned char green, unsigned char blue);
	void Dibuja();
	//añadir funcion para disparo
};


#pragma once
#include "NavePersonaje.h"
#include"disparo.h"
#include "Nave.h"



class Factoria
{
public:
	Factoria();
	virtual ~Factoria();
	static Disparo* CrearDisparo(NavePersonaje h);
};


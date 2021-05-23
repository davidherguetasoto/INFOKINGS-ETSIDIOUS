#pragma once
#include "Nave.h"
class NavePersonaje :public Nave
{
public:
	NavePersonaje();
	friend class Interaccion;
};


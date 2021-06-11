#pragma once
#include "Nave.h"
class NavePersonaje :public Nave
{
public:
	NavePersonaje();
	void dibuja(); //Define cómo se dibuja el personaje
	friend class Interaccion;
};
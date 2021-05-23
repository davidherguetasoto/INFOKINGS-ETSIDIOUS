#pragma once
#include"Pared.h"
#include"Caja.h"
#include"NavePersonaje.h"
class Interaccion
{
public:
	static bool Rebote(NavePersonaje& nave, Pared pared);
	static void Rebote(NavePersonaje& nave, Caja caja);
};


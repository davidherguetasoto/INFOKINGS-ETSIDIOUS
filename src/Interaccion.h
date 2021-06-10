#pragma once
#include"Pared.h"
#include"Caja.h"
#include"NavePersonaje.h"
#include "Obstaculo.h"
#include "disparo.h"
class Interaccion
{
public:
	static bool rebote(NavePersonaje& nave, Pared pared);
	static void rebote(NavePersonaje& nave, Caja caja);
	static bool colision(Obstaculo e, Disparo d);
};


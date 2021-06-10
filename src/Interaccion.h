#pragma once
#include"Pared.h"
#include"Caja.h"
#include"NavePersonaje.h"
#include "NaveEnemiga.h"
#include "Obstaculo.h"
#include "disparo.h"
class Interaccion
{
public:
	static bool rebote(NavePersonaje& nave, Pared pared);
	static void rebote(NavePersonaje& nave, Caja caja);
	static bool rebote(NaveEnemiga& n, Pared p);
	static bool rebote(NaveEnemiga& n, Caja c);
	static bool colision(Obstaculo e, Disparo d);
	static bool colision(Disparo d, Caja c);
	static bool colision(Disparo d, Obstaculo o);
	static bool colision(Disparo d, NaveEnemiga ne);
};


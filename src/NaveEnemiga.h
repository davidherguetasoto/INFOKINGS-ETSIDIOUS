#pragma once
#include "Nave.h"
class NaveEnemiga :public Nave
{
public:
	NaveEnemiga(); //Habrá distintos tipos de enemigos
	friend class Interaccion;
};


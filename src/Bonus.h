#pragma once
#include "ObjetoMovil.h"

class Bonus:public ObjetoMovil
{
	float lado = 5.0;

public:
	Bonus();
	void mueve(float t);
	virtual ~Bonus();
	void dibuja();
};


#pragma once
#include "ObjetoMovil.h"
#define BONUS_DISPARO_DOBLE 0
#define BONUS_MISILES 1
#define BONUS_PUNT_EXTRAS 2
#define BONUS_VIDAS 3

class Bonus:public ObjetoMovil
{
protected:
	float lado;
	float extra; //aumento de vida, o disparos de la nave personaje
	int tipo; //tipo de bonus(0,1,2 o 3)

public:
	Bonus(float extra, int tipo);
	virtual ~Bonus();
	virtual void dibuja() = 0;
	float getExtra();
	int getTipo();
	float getLado() { return lado; }
};


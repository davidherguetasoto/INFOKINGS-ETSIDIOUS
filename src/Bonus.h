#pragma once
#include "ObjetoMovil.h"
#include"ColorRGB.h"
#define BONUS_DISPARO_DOBLE 0
#define BONUS_MISILES 1
#define BONUS_PUNT_EXTRAS 2
#define BONUS_VIDAS 3

class Bonus:public ObjetoMovil
{
protected:
	float lado;
	float extra; //aumento de vida, o disparos de la nave personaje
	Vector2D origen;//Origen donde este el enemigo
	int tipo; //tipo de bonus(0,1,2 o 3)

public:
	//Tipos de Bonus
	//Bonus();
	Bonus(float extra, int tipo);
	void mueve(float t);
	virtual ~Bonus();
	virtual void dibuja()=0;
	Vector2D getOrigen();
	void setOrigen(float ix, float iy);
	float getExtra();
	int getTipo();
	float getLado() { return lado; }
};


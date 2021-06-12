#pragma once
#include "ObjetoMovil.h"
#include"ColorRGB.h"

class Bonus:public ObjetoMovil
{
protected:
	float lado = 5.0;
	float extra; //aumento de vida, o disparos de la nave personaje
	Vector2D origen;//Origen donde este el enemigo
	int tipo; //tipo de bonus(0,1,2 o 3)

public:
	//Tipos de Bonus
	const int BONUS_DISPARO_DOBLE = 0;
	const int BONUS_MISILES = 1;
	const int BONUS_PUNT_EXTRAS = 2;
	const int BONUS_VIDAS = 3;
	Bonus();
	Bonus(float daño, int tipo);
	void mueve(float t);
	virtual ~Bonus();
	void dibuja();
	Vector2D getOrigen();
	void setOrigen(float ix, float iy);
	float getExtra();
	int getTipo();
};


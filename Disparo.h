#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
class Disparo:public ObjetoMovil
{
private:
	float daño; //Daño que produce el disparo
	Vector2D origen;

public:
	Disparo();
	virtual ~Disparo();
	virtual void Dibuja();
	void setPos(Vector2D pos);
	void setPos(float ix, float iy);
};


#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
#include "Vector2D.h"

class Disparo:public ObjetoMovil
{
private:
	float daño; //Daño que produce el disparo
	float radio;
	Vector2D origen;
	ColorRGB color;
public:
	Disparo();
	virtual ~Disparo();

	virtual void dibuja();
	void setPos(Vector2D pos);
	void setPos(float ix, float iy);
	float getRadio();
	Vector2D getOrig();
};


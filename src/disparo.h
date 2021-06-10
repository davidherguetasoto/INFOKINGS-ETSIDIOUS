#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
class Disparo:public ObjetoMovil
{
private:
	float daño; //Daño que produce el disparo
public:
	Disparo();
	virtual ~Disparo();
	virtual void dibuja();
	void setPos(Vector2D pos);
	void setPos(float ix, float iy);
};


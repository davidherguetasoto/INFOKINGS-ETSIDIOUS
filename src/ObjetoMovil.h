#pragma once
#include"Vector2D.h"
class ObjetoMovil
{
protected:
	Vector2D posicion, velocidad;
public:
	virtual void Mueve(float t);
	Vector2D getPos() { return posicion; }
	void setVel(Vector2D vel) { velocidad = vel; }
	void setPos(Vector2D pos) { posicion = pos; }
};


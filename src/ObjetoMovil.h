#pragma once
#include"Vector2D.h"
class ObjetoMovil
{
protected:
	Vector2D posicion, velocidad;
public:
	virtual void Mueve(float t);
	void setPos(Vector2D pos) { posicion = pos; }
	void setPos(float ix, float iy) { posicion.x = ix; posicion.y = iy; }
	void setVel(Vector2D vel) { velocidad = vel; }
	void setVel(float vx, float vy) { velocidad.x = vx; velocidad.y = vy; }
	Vector2D getPos() { return posicion; }
	Vector2D getVel() { return velocidad; }
};


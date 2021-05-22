#pragma once
#include"Vector2D.h"
class ObjetoMovil
{
protected:
	float orientacion; //Ángulo que el objeto se encuentra rotado alrededor del eje Z
	float vel_modulo; //Módulo de la velocidad del cuerpo
	Vector2D posicion, velocidad;
public:
	ObjetoMovil();
	ObjetoMovil(float vel, float ori, float posx,float posy);
	ObjetoMovil(float vel, float ori, Vector2D pos);
	virtual void Mueve(float t);
	void setPos(Vector2D pos) { posicion = pos; }
	void setPos(float ix, float iy) { posicion.x = ix; posicion.y = iy; }
	void setVel(float vel);
	void setVel(Vector2D vel) { velocidad = vel; }
	void setOri(float ori) { orientacion = ori; }
	Vector2D getPos() { return posicion; }
};


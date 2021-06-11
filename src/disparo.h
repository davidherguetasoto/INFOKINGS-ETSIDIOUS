//CLASE ABSTRACTA PARA LA DEFINICIÓN DE LOS DISPAROS
#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
#include "Vector2D.h"

//TIPOS DE DISPAROS DEL JUEGO
/*
#define NINGUNO -1
#define DISPARO_ALIADO 0
#define DISPARO_ENEMIGO 1
#define MISIL 2
#define DISPARO_TRIPLE 3
*/


class Disparo:public ObjetoMovil
{
protected:
	float daño; //Daño que produce el disparo
	Vector2D origen; //Origen del disparo
	//int tipo; //Atributo para seleccionar los distintos tipos de disparo
public:
	Disparo(float daño);
	virtual ~Disparo();
	virtual void dibuja()=0;
	Vector2D getOrigen();
	void setOrigen(Vector2D ori);
	void setOrigen(float ix, float iy);
	float getDaño();
	//int getTipo();
};


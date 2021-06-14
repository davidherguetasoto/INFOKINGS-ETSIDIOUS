//CLASE ABSTRACTA PARA LA DEFINICIÓN DE LOS DISPAROS
#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
#include "Vector2D.h"

//TIPOS DE DISPAROS DEL JUEGO
#define NINGUNO -1
#define DISPARO_ALIADO 0
#define DISPARO_ENEMIGO 3
#define MISIL 1
#define DISPARO_DOBLE 2


class Disparo:public ObjetoMovil
{
protected:
	float daño; //Daño que produce el disparo
	Vector2D origen; //Origen del disparo
	int tipo; //Atributo para seleccionar los distintos tipos de disparo
	float radio;
	float altura;
public:
	Disparo(float daño,int tipo);
	virtual ~Disparo();
	virtual void dibuja()=0;
	Vector2D getOrigen();
	void setOrigen(Vector2D ori);
	void setOrigen(float ix, float iy);
	float getDano();
	int getTipo();
	float getRadio() { return radio; }
	float getAltura() { return radio; }
};


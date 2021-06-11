//CLASE PARA LA DEFINICIÓN DEL ENEMIGO ESTÁNDAR
#pragma once
#include "Nave.h"
#include"ColorRGB.h"
class NaveEnemiga :public Nave
{
protected:
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
	float altura;
	float radio;
	ColorRGB color;
public:
	NaveEnemiga();
	void dibuja(); //Se debe definir cómo se dibuja el enemigo estándar
	friend class Interaccion;
};


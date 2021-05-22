#pragma once
#include "Vector2D.h"

class Nave
{
public:
	Nave();
	void Dibuja();

private:
	float altura;
	Vector2D posicion;
	Vector2D velocidad;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};


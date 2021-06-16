//CLASE PARA LA DEFINICIÓN DEL ENEMIGO ESTÁNDAR
#pragma once
#include "Nave.h"
class NaveEnemiga :public Nave
{
private:
	SpriteSequence sprite_nave{ "imagenes/NaveEnemiga.png",1 };
public:
	NaveEnemiga();
	void dibuja(); //Se debe definir cómo se dibuja el enemigo estándar
	friend class Interaccion;
};


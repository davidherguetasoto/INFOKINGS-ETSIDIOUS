//CLASE PARA LA DEFINICIÓN DEL ENEMIGO ESTÁNDAR
#pragma once
#include "Nave.h"
#include"ColorRGB.h"
class NaveEnemiga :public Nave
{
private:

	SpriteSequence sprite_nave{ "imagenes/NaveEnemiga.png",1 };
protected:
	
	float daño; //Daño que harán cuando colisionen con la nave del personaje
public:
	Vector2D origen;
	NaveEnemiga();
	void dibuja(); //Se debe definir cómo se dibuja el enemigo estándar
	float getDano() { return daño; }
	friend class Interaccion;
};


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
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
public:
	NaveEnemiga();
	void dibuja(); //Se debe definir cómo se dibuja el enemigo estándar
	float getDano() { return daño; }
	friend class Interaccion;
};


#pragma once
#include"Bonus.h"
#include"ColorRGB.h"



class BonusMisiles:public Bonus
{
private:
	SpriteSequence sprite_misiles{"imagenes/misil_sin_disparar.png",1 };
public:
	friend class Interaccion;
	void dibuja();
	BonusMisiles();
};


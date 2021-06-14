#pragma once
#include"Bonus.h"
#include"ColorRGB.h"


class BonusPuntExtras:public Bonus
{
private:
	SpriteSequence sprite_puntos{ "imagenes/x2.png",1 };
public:
	friend class Interaccion;
	void dibuja();
	BonusPuntExtras();
};


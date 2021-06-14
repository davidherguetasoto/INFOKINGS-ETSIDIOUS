#pragma once
#include"Bonus.h"
#include"ColorRGB.h"

class BonusVidas:public Bonus
{
private:
	SpriteSequence sprite_Vidas{"imagenes/corazonbueno.png",1 };
public:
	friend class interaccion;
	void dibuja();
	BonusVidas();
};


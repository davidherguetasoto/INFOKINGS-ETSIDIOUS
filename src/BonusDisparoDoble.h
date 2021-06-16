#pragma once
#include"Bonus.h"

class BonusDisparoDoble :public Bonus
{
private:
	SpriteSequence sprite_DispDoble{"imagenes/laser.png",1 };

public:
	friend class Interaccion;
	void dibuja();
	BonusDisparoDoble();

};
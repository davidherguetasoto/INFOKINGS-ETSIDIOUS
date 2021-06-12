#pragma once
#include"Bonus.h"


class BonusDisparoDoble :public Bonus
{
protected:

public:
	friend class Interaccion;
	void dibuja();
	BonusDisparoDoble();
	//BonusDisparoDoble(float extra, int tipo);
};




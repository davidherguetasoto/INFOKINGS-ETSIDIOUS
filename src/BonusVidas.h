#pragma once
#include"Bonus.h"

class BonusVidas:public Bonus
{
protected:

public:
	friend class interaccion;
	void dibuja();
	BonusVidas();
};


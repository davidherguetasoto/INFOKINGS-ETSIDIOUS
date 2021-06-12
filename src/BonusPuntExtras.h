#pragma once
#include"Bonus.h"

class BonusPuntExtras:public Bonus
{
protected:

public:
	friend class Interaccion;
	void dibuja();
	BonusPuntExtras();
};


#pragma once
#include"Bonus.h"

class BonusMisiles:public Bonus
{
protected:

public:
	friend class Interaccion;
	void dibuja();
	BonusMisiles();
};


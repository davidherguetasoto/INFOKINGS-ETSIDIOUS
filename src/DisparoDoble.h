#pragma once
#include "DisparoAliado.h"
class DisparoDoble : public DisparoAliado
{
public:
	DisparoDoble();
	void dibuja();
	friend class Interaccion;
};


#pragma once
#include "DisparoAliado.h"
class DisparoDoble : public DisparoAliado
{
public:
	DisparoDoble();
	virtual ~DisparoDoble();
	void dibuja();
	friend class Interaccion;
};


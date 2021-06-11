#pragma once
#include "DisparoAliado.h"
class Misil : public DisparoAliado
{
	public:
		Misil();
		virtual ~Misil();
		void dibuja();
		friend class Interaccion;
};


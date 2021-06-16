#include "Nave.h"

Nave::Nave(float vida) : vida(vida)
{
	radio = 1.0f;
	altura = 1.0f;
}
float Nave::getVida()
{
	return vida;
}
void Nave::setVida(float vida)
{
	this->vida = vida;
	if (this->vida <= 0)
		this->vida = 0;
}


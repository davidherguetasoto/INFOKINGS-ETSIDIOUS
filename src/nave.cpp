#include "Nave.h"
#include "freeglut.h"

Nave::Nave(float vida) : vida(vida)
{
	
}
float Nave::getVida()
{
	return vida;
}
void Nave::setVida(float vida)
{
	this->vida = vida;
}


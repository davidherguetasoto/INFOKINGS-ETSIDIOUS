#include "Disparo.h"
Disparo::Disparo(float daño) : daño(daño)
{
}
Disparo::~Disparo()
{
}
Vector2D Disparo::getOrigen()
{
	return origen;
}
void Disparo::setOrigen(Vector2D ori)
{
	origen = ori;
}
void Disparo::setOrigen(float ix,float iy)
{
	origen.x = ix;
	origen.y = iy;
}
float Disparo::getDaño()
{
	return daño;
}
/*
int Disparo::getTipo()
{
	return tipo;
}
*/
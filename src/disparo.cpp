#include "Disparo.h"

Disparo::Disparo():daño(10.0f)
{

}
Disparo::~Disparo()
{
}
void Disparo::Dibuja()
{

}
void Disparo::setPos(Vector2D pos)
{
	ObjetoMovil::setPos(pos);
}
void Disparo::setPos(float ix, float iy)
{
	ObjetoMovil::setPos(ix, iy);
}
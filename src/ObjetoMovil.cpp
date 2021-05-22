#include "ObjetoMovil.h"
#include <math.h>
ObjetoMovil::ObjetoMovil():orientacion(0)
{
}
ObjetoMovil::ObjetoMovil(float vel, float angulo, float posx,float posy) : orientacion(angulo),posicion(posx,posy)
{
	velocidad.x = vel * cos(orientacion);
	velocidad.y = vel * sin(orientacion);
}
ObjetoMovil::ObjetoMovil(float vel, float angulo, Vector2D pos) : orientacion(angulo),posicion(pos)
{
	velocidad.x = vel * cos(orientacion);
	velocidad.y = vel * sin(orientacion);
}
void ObjetoMovil::Mueve(float t)
{
	posicion = posicion + velocidad * t;
}
void ObjetoMovil::setVel(float vel)
{
	velocidad.x = vel * cos(orientacion);
	velocidad.y = vel * sin(orientacion);
}
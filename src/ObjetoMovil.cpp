#include "ObjetoMovil.h"
#include <math.h>
ObjetoMovil::ObjetoMovil():orientacion(0),vel_modulo(0)
{
}
ObjetoMovil::ObjetoMovil(float vel, float angulo, float posx,float posy) : orientacion(angulo), vel_modulo(vel), posicion(posx,posy)
{
	velocidad.x = vel_modulo * cos(orientacion);
	velocidad.y = vel_modulo * sin(orientacion);
}
ObjetoMovil::ObjetoMovil(float vel, float angulo, Vector2D pos) : orientacion(angulo), vel_modulo(vel), posicion(pos)
{
	velocidad.x = vel_modulo * cos(orientacion);
	velocidad.y = vel_modulo * sin(orientacion);
}
void ObjetoMovil::Mueve(float t)
{
	posicion = posicion + velocidad * t;
}
void ObjetoMovil::setVel(float vel)
{
	vel_modulo = vel; 
	velocidad.x = vel * cos(orientacion);
	velocidad.y = vel * sin(orientacion);
}
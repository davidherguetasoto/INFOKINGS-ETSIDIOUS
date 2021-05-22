#include "ObjetoMovil.h"
void ObjetoMovil::Mueve(float t)
{
	posicion = posicion + velocidad * t;
}

#include "ObjetoMovil.h"
#include <math.h>

void ObjetoMovil::Mueve(float t)
{
	posicion = posicion + velocidad * t;
}
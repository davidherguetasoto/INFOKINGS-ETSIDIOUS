#include "ObjetoMovil.h"
#include <math.h>

void ObjetoMovil::mueve(float t)
{
	posicion = posicion + velocidad * t;
}
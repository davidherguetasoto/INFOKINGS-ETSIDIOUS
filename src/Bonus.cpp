#include "Bonus.h"
#include <stdlib.h> //para rand()
#include "freeglut.h"

Bonus::Bonus(float extra, int tipo):extra(extra),tipo(tipo)
{
	velocidad.y = -7.0f;
	lado = 2.0f;
}
Bonus::~Bonus() 
{

}
float Bonus::getExtra()
{
	return extra;
}

int Bonus::getTipo()
{
	return tipo;
}
#include "Disparo.h"
Disparo::Disparo(float daño,int tipo) : daño(daño), tipo(tipo)
{
	radio = 0.5f;
	altura = 0.5f;
}
Disparo::~Disparo()
{
	radio = 0.5f;
	altura = 0.5f;
}
float Disparo::getDano()
{
	return daño;
}
int Disparo::getTipo()
{
	return tipo;
}
#include "DisparoAliado.h"
//Por defecto tendrá 35 puntos de daño
DisparoAliado::DisparoAliado() :Disparo(35,DISPARO_ALIADO)
{
	velocidad.y = 30.0f;
	radio = 0.5f;
}
DisparoAliado::DisparoAliado(float daño, int tipo) : Disparo(daño, tipo)
{
	radio=0.5f;
}
void DisparoAliado::dibuja()
{
	//PROVISIONAL
	glPushMatrix();
	glColor3f(0, 255, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
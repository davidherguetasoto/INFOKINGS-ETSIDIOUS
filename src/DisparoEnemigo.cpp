#include "DisparoEnemigo.h"

DisparoEnemigo::DisparoEnemigo() :Disparo(20, DISPARO_ENEMIGO)
{
	radio = 0.25f;
	velocidad.y = -30.0f;
}
DisparoEnemigo::DisparoEnemigo(float daño, int tipo) : Disparo(daño, tipo)
{
	radio = 0.25f;
	velocidad.y = -30.0f;
}
void DisparoEnemigo::dibuja()
{
	//PROVISIONAL
	glPushMatrix();
	glColor3f(255,0, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
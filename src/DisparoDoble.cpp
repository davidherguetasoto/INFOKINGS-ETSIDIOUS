#include "DisparoDoble.h"

DisparoDoble::DisparoDoble() :DisparoAliado(35, DISPARO_DOBLE)
{
	radio = 0.35f;
	velocidad.y = 35.0f;
}
void DisparoDoble::dibuja()
{
	//PROVISIONAL
	glPushMatrix();
	glColor3f(255, 255, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
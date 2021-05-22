#include "Obstaculo.h"
#include "freeglut.h"
Obstaculo::Obstaculo() :radio(0.2f)
{
	posicion.x = 5.0f;
	velocidad.y = -2.0f;
}
void Obstaculo::Dibuja()
{
	glPushMatrix();
	glColor3f(0, 255, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
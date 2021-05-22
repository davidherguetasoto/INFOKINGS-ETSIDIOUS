#include "nave.h"
#include "freeglut.h"

Nave::Nave()
{
	altura = 1.8f;
	rojo = verde = azul = 255;
}

void Nave::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}
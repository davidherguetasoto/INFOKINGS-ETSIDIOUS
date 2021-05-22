#include "Nave.h"
#include "freeglut.h"
Nave::Nave():vida(100),radio(0.5f),altura(2.0f)
{
}
void Nave::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(radio, altura, 20, 20);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
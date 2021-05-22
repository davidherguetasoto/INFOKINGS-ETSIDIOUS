#include "Nave.h"
#include "freeglut.h"
Nave::Nave():vida(100),radio(0.5),altura(1)
{
}
void Nave::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCone(radio, altura, 20, 20);
	glPopMatrix();
}
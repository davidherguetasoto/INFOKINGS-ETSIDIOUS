#include "Nave.h"
#include "freeglut.h"
Nave::Nave():vida(100),radio(0.5f),altura(2.0f)
{
}
Nave::Nave(float vida, unsigned char red, unsigned char green, unsigned char blue) : vida(vida)
{
	color.set(red, green, blue);
	altura = 2.0f;
	radio = 0.5f;
}
void Nave::Dibuja()
{
	color.ponColor();
	glRotatef(-90, 1, 0, 0);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCone(radio, altura, 20, 20);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
#include "Obstaculo.h"
#include "freeglut.h"
Obstaculo::Obstaculo()
{
	radio = 0.5f;
	posicion.x = 5.0f;
	posicion.y = 20.0f;
	velocidad.y = -15.0f;
	daño = 20.0f;
}


void Obstaculo::dibuja()
{
	glPushMatrix();
	glColor3f(0, 255, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
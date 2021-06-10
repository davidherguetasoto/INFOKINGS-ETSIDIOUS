#include "Disparo.h"

Disparo::Disparo():daño(10.0f), radio (0.25f)
{
	color.set(255, 0, 0);
	//velocidad.y = 5.0f;
	// se pondrá en las clases derivadas la velocidad de los disparos
}

Disparo::~Disparo()
{
}

void Disparo::dibuja()
{
	color.ponColor();
	glBegin(GL_LINE_STRIP);
	for (float i = origen.y; i < posicion.y; i += 0.05f) {
		glVertex3f(posicion.x + 0.1f * sin(10 * i), i, 0.5);
	}
	glEnd();

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}

void Disparo::setPos(Vector2D pos)
{
	ObjetoMovil::setPos(pos);
	origen = pos;
}

void Disparo::setPos(float ix, float iy)
{
	ObjetoMovil::setPos(ix, iy);
	origen.x = posicion.x;
	origen.y = posicion.y;
}

float Disparo::getRadio()
{
	return radio;
}

Vector2D Disparo::getOrig()
{
	return origen;
}

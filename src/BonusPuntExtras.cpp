#include "BonusPuntExtras.h"

BonusPuntExtras::BonusPuntExtras() :Bonus(30, BONUS_PUNT_EXTRAS)
{
	velocidad.y = -7.0f;
}


void BonusPuntExtras::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}

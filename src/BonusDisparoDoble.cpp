#include "BonusDisparoDoble.h"

BonusDisparoDoble::BonusDisparoDoble() :Bonus(5, BONUS_DISPARO_DOBLE)
{
	velocidad.y = -7.0f;
}


void BonusDisparoDoble::dibuja()
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



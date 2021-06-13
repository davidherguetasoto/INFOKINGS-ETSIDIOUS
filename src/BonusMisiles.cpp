#include "BonusMisiles.h"

BonusMisiles::BonusMisiles() :Bonus(1, BONUS_MISILES)
{
	velocidad.y = -7.0f;
	//posicion.x = 6;
	//posicion.y = 17;
}

void BonusMisiles::dibuja()
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

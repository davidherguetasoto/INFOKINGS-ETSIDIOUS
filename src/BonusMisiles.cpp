#include "BonusMisiles.h"

BonusMisiles::BonusMisiles() :Bonus(1, BONUS_MISILES)
{
	velocidad.y = -7.0f;
	sprite_misiles.setCenter(lado/2.0f, lado/2.0f);
	sprite_misiles.setSize(lado, lado);
}



void BonusMisiles::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	sprite_misiles.setState(0);
	sprite_misiles.draw();
	glPopMatrix();
}

#include "BonusPuntExtras.h"

BonusPuntExtras::BonusPuntExtras() :Bonus(30, BONUS_PUNT_EXTRAS)
{
	velocidad.y = -7.0f;
	sprite_puntos.setCenter(lado/2.0f, lado/2.0f);
	sprite_puntos.setSize(lado, lado);
}


void BonusPuntExtras::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	sprite_puntos.setState(0);
	sprite_puntos.draw();
	//glutSolidCube(lado);
	glPopMatrix();
}

#include "BonusDisparoDoble.h"

BonusDisparoDoble::BonusDisparoDoble() :Bonus(10, BONUS_DISPARO_DOBLE)//Se pasa el tiempo de duracion y el tiempo de disparo
{
	velocidad.y = -7.0f;
	sprite_DispDoble.setCenter(lado/4.0f, lado/4.0f);
	sprite_DispDoble.setSize(lado/2.0f, lado/2.0f);
}


void BonusDisparoDoble::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	sprite_DispDoble.setState(0);
	sprite_DispDoble.draw();
	glTranslatef(1.0f, 0.0f, 0.0f);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);
	sprite_DispDoble.setState(0);
	sprite_DispDoble.draw();
	glPopMatrix();
}



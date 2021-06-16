#include "BonusVidas.h"

BonusVidas::BonusVidas():Bonus(20, BONUS_VIDAS)
{
	velocidad.y = -7.0f;
	sprite_Vidas.setCenter(lado/2.0f, lado/2.0f);
	sprite_Vidas.setSize(lado, lado);
}

void BonusVidas::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	sprite_Vidas.setState(0);
	sprite_Vidas.draw();
	glPopMatrix();
}

#include "DisparoEnemigo.h"

DisparoEnemigo::DisparoEnemigo() :Disparo(20, DISPARO_ENEMIGO)
{
	radio = 0.25f;
	velocidad.y = -30.0f;
	sprite_DisparoEnemigo.setCenter(0.6f, 1);
	sprite_DisparoEnemigo.setSize(1.2f, 2);
	sprite_DisparoEnemigo.setAngle(180.0f);
}
DisparoEnemigo::DisparoEnemigo(float daño, int tipo) : Disparo(daño, tipo)
{
	radio = 0.25f;
	velocidad.y = -30.0f;
}
void DisparoEnemigo::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_DisparoEnemigo.setState(0);
	sprite_DisparoEnemigo.draw();
	glPopMatrix();
}
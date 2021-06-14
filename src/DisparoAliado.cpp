#include "DisparoAliado.h"
//Por defecto tendrá 35 puntos de daño
DisparoAliado::DisparoAliado() :Disparo(35,DISPARO_ALIADO)
{
	velocidad.y = 30.0f;
	radio = 0.25f;
	sprite_DisparoAliado.setCenter(0.6f, 1);
	sprite_DisparoAliado.setSize(1.2f, 2);
}
DisparoAliado::DisparoAliado(float daño, int tipo) : Disparo(daño, tipo)
{
	velocidad.y = 30.0f;
	radio=0.25f;
}
void DisparoAliado::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_DisparoAliado.setState(0);
	sprite_DisparoAliado.draw();
	glPopMatrix();
}
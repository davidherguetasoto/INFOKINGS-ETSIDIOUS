#include "DisparoAliado.h"
//Por defecto tendrá 35 puntos de daño
DisparoAliado::DisparoAliado() :Disparo(35,DISPARO_ALIADO)
{
	velocidad.y = 30.0f;
	radio = 0.325f; //0.65
	altura = 0.875f; //1.75
	sprite_DisparoAliado.setCenter(radio*2, altura);
	sprite_DisparoAliado.setSize(radio*4, altura*2);
}
DisparoAliado::DisparoAliado(float daño, int tipo) : Disparo(daño, tipo)
{
	velocidad.y = 30.0f;
	radio = 0.65f;
	altura = 1.75f;
	sprite_DisparoAliado.setCenter(radio, altura / 2);
	sprite_DisparoAliado.setSize(radio * 2, altura);
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
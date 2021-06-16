#include "DisparoEnemigo.h"

DisparoEnemigo::DisparoEnemigo() :Disparo(20, DISPARO_ENEMIGO)
{
	radio = 0.325f;
	altura = 0.875f;
	velocidad.y = -30.0f;
	sprite_DisparoEnemigo.setCenter(radio*2,altura);
	sprite_DisparoEnemigo.setSize(radio*4,altura*2);
	sprite_DisparoEnemigo.setAngle(180.0f);
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
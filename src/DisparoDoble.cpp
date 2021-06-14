#include "DisparoDoble.h"

DisparoDoble::DisparoDoble() :DisparoAliado(40, DISPARO_DOBLE)
{
	radio = 0.3f;
	velocidad.y = 35.0f;
	sprite_doble.setCenter(0.375f, 0.75f);
	sprite_doble.setSize(0.75f, 1.5f);
}
DisparoDoble::~DisparoDoble()
{

}
void DisparoDoble::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_doble.setState(0);
	sprite_doble.draw();
	glPopMatrix();
}
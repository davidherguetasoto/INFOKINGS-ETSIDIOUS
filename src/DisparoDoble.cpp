#include "DisparoDoble.h"

DisparoDoble::DisparoDoble() :DisparoAliado(40, DISPARO_DOBLE)
{
	radio = 0.375f;
	altura = 1.5f;
	velocidad.y = 35.0f;
	sprite_doble.setCenter(radio,altura/2);
	sprite_doble.setSize(radio*2, altura);
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
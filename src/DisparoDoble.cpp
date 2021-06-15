#include "DisparoDoble.h"

DisparoDoble::DisparoDoble() :DisparoAliado(40, DISPARO_DOBLE)
{
	radio = 0.1875f; //0.375
	altura = 0.75f; //1.5
	velocidad.y = 35.0f;
	sprite_doble.setCenter(radio*2,altura);
	sprite_doble.setSize(radio*4, altura*2);
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
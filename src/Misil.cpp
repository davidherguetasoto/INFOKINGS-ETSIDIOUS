#include"Misil.h"

//Se crea un disparo de tipo MISIL con 100 de daño
Misil::Misil():DisparoAliado(100,MISIL)
{
	radio = 0.75f;
	altura = 2.5f;
	velocidad.y = 40.0f;
	sprite_misil.setCenter(radio, altura/2);
	sprite_misil.setSize(radio*2, altura);
}
Misil::~Misil()
{

}
void Misil::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_misil.setState(0);
	sprite_misil.draw();
	glPopMatrix();
}
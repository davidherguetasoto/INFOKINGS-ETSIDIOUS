#include "Obstaculo.h"
#include "freeglut.h"
Obstaculo::Obstaculo()
{
	radio = 0.75f;
	posicion.x = 5.0f;
	posicion.y = 20.0f;
	velocidad.y = -15.0f;
	daño = 40.0f;
	sprite_obstaculo.setCenter(radio, radio);
	sprite_obstaculo.setSize(radio*2, radio*2);
}


void Obstaculo::dibuja()
{
	glPushMatrix();
	glColor3f(0, 255, 0);
	glTranslatef(posicion.x, posicion.y, 1);

	//gestion de direccion y animacion
	sprite_obstaculo.setState(0);
	sprite_obstaculo.draw();
	glPopMatrix();
}
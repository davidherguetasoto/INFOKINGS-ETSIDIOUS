#include "NavePersonaje.h"
#include "freeglut.h"
NavePersonaje::NavePersonaje():Nave(100.0f,0,0,255)
{
	
}
void NavePersonaje::dibuja()
{
	glPushMatrix();
	color.ponColor();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(radio, altura, 20, 20);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
#include "NavePersonaje.h"
#include "freeglut.h"


NavePersonaje::NavePersonaje():Nave(100.0f)
{
	altura = 2.0f;
	radio = 0.5f;
	color.set(0, 0, 255);
	num_bonus = 0;//num_bonus para inicializarlo a 0 prueba
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

//prueba
void NavePersonaje::IncrementaNumBonus()
{

}

void NavePersonaje::SetNumBonuns(int num)
{

}

int NavePersonaje::GetNumBonus()
{

}

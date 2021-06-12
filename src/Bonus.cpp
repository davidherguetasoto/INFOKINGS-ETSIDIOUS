#include "Bonus.h"
#include <stdlib.h> //para rand()
#include "freeglut.h"

Bonus::Bonus(float extra, int tipo):extra(extra),tipo(tipo)
{
	velocidad.y = -7.0f;
}


Bonus::Bonus()
{
	velocidad.y = -7.0f;
	lado = 1.0f;
	//aceleracion.y = -9.8f;
}

void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5 * t * t;
	velocidad = velocidad + aceleracion * t;
}

Bonus::~Bonus() 
{

}

void Bonus::dibuja() {
	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();*/
}

Vector2D Bonus::getOrigen()
{
	return origen;
}

void Bonus::setOrigen(float ix,float iy)
{
	origen.x = ix;
	origen.y = iy;
}

float Bonus::getExtra()
{
	return extra;
}

int Bonus::getTipo()
{
	return tipo;
}
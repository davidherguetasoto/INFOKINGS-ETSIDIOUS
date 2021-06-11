#include"Misil.h"

//Se crea un disparo de tipo MISIL con 70 de daño
Misil::Misil():DisparoAliado(100,MISIL)
{

}
Misil::~Misil()
{

}
void Misil::dibuja()
{
	//PROVISIONAL
	glPushMatrix();
	glColor3f(255, 0,0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
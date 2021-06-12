#include"Misil.h"

//Se crea un disparo de tipo MISIL con 100 de daño
Misil::Misil():DisparoAliado(100,MISIL)
{
	radio = 0.3f;
	velocidad.y = 40.0f;
}
Misil::~Misil()
{

}
void Misil::dibuja()
{
	//PROVISIONAL
	glPushMatrix();
	glColor3f(255, 0,255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}
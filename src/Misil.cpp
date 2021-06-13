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
	//glPushMatrix();
	//glColor3f(255, 0,255);
	//glTranslatef(posicion.x, posicion.y, 0);
	//glutSolidSphere(radio, 20, 20);
	//glTranslatef(-posicion.x, -posicion.y, 0);
	//glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/misil.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(posicion.x - 1, posicion.y - 1, 1);
	glTexCoord2d(1, 1); glVertex3f(posicion.x + 1, posicion.y - 1, 1);
	glTexCoord2d(1, 0); glVertex3f(posicion.x + 1, posicion.y + 1, 1);
	glTexCoord2d(0, 0); glVertex3f(posicion.x - 1, posicion.y + 1, 1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
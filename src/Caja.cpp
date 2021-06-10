#include "Caja.h"
#include"ETSIDI.h"
Caja::Caja()
{
	suelo.setColor(0, 100, 0);
	suelo.setPos(-12.0f, -5.0f, 12.0f, -5.0f);

	pared_izq.setColor(0, 150, 0);
	pared_izq.setPos(-12.0f,-5.0f , -12.0f, 20.0f);
	
	pared_dcha.setColor(0, 150, 0);
	pared_dcha.setPos(12.0f, -5.0f, 12.0f, 20.0f);
	
	techo.setColor(0, 100, 0);
	techo.setPos(-12.0f, 20.0f, 12.0f, 20.0f);
}
Caja::~Caja()
{
}
void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();

	
	//DIBUJO DEL FONDO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/espacio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-12, -5);
	glTexCoord2d(1, 1); glVertex2f(12, -5);
	glTexCoord2d(1, 0); glVertex2f(12, 20);
	glTexCoord2d(0, 0); glVertex2f(-12, 20);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

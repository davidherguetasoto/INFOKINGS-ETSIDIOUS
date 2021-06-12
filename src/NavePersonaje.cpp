#include "NavePersonaje.h"
#include "freeglut.h"


NavePersonaje::NavePersonaje():Nave(100.0f)
{
	altura = 2.0f;
	radio = 0.5f;
	color.set(0, 0, 255);
	num_bonus = 0;//num_bonus para inicializarlo a 0 prueba
	num_misiles = 0;
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

	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("vida:", -10, -6);

	for (int i = 0; i < 5; i++) {
		if (vida > 20*i) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/corazonbueno.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex2f(-7 +  i, -6);
			glTexCoord2d(1, 1); glVertex2f(-6 +  i, -6);
			glTexCoord2d(1, 0); glVertex2f(-6 +  i, -5);
			glTexCoord2d(0, 0); glVertex2f(-7 +  i, -5);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}

	}
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
	return num_bonus;
}

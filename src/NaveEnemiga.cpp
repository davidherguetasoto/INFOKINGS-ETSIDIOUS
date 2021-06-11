#include "NaveEnemiga.h"

/*Se construye a partir de la clase nave, pasándole el valor de
la vida que quieres que tengan los enemigos*/
NaveEnemiga::NaveEnemiga():Nave(100.0F)
{
	altura = 2.0f;
	radio = 0.5f;
	color.set(255, 0, 0);
}
void NaveEnemiga::dibuja()
{
	//Código para dibujar las naves enemigas
	glPushMatrix();
	color.ponColor();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCone(radio, altura, 20, 20);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}


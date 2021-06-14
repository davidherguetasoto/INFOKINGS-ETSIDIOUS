#include "NaveEnemiga.h"

/*Se construye a partir de la clase nave, pasándole el valor de
la vida que quieres que tengan los enemigos*/
NaveEnemiga::NaveEnemiga():Nave(100.0F)
{
	daño = 20.0f;
	altura = 2.0f; 
	radio = 1.25f; 
	color.set(255, 0, 0);
	sprite_nave.setCenter(2.5f, 3.0f);
	sprite_nave.setSize(5.0f, 6.0f);
	sprite_nave.setAngle(180.0f);
}
void NaveEnemiga::dibuja()
{
	//Código para dibujar las naves enemigas
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_nave.setState(0);
	sprite_nave.draw();
	glPopMatrix();
}


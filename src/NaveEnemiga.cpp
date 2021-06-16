#include "NaveEnemiga.h"

/*Se construye a partir de la clase nave, pasándole el valor de
la vida que quieres que tengan los enemigos*/
NaveEnemiga::NaveEnemiga():Nave(100.0F)
{
	altura = 1.5f; //3
	radio =0.75f; //1.5
	velocidad.y = -4.0f;
	sprite_nave.setCenter(radio * 2, altura); 
	sprite_nave.setSize(radio * 4, altura * 2);
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

#include "NavePersonaje.h"
#include "freeglut.h"

NavePersonaje::NavePersonaje():Nave(VIDA_MAX)//poner vida_max luego
{
	altura = 2.0f; 
	radio = 1.25f; 
	color.set(0, 0, 255);
	num_bonus = 0;//num_bonus para inicializarlo a 0 prueba
	num_misiles = 3;
	disparo_misiles = false;
	disparo_doble = false;
	sprite_nave.setCenter(2.5f, 3.0f);
	sprite_nave.setSize(5.0f, 6.0f);
}
void NavePersonaje::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//gestion de direccion y animacion
	sprite_nave.setState(0);
	sprite_nave.draw();
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
	return num_bonus;
}
void NavePersonaje::setNumMisiles(int misiles)
{
	if (misiles <= 0)misiles = 0;
	else if (misiles >= MISILES_MAX)misiles = MISILES_MAX;
	num_misiles = misiles;
}
void NavePersonaje::setVida(float vida)
{
	Nave::setVida(vida);
	if ((this->vida) > VIDA_MAX)
		this->vida = VIDA_MAX;
}
#include "NavePersonaje.h"
#include "freeglut.h"

NavePersonaje::NavePersonaje():Nave(VIDA_MAX)//poner vida_max luego
{
	altura = 5.0f; 
	radio = 1.75f; 

	num_bonus = 0;//num_bonus para inicializarlo a 0 prueba
	num_misiles = 3;
	disparo_misiles = false;
	disparo_doble = true;
	sprite_nave.setCenter(radio, altura/2);
	sprite_nave.setSize(radio*2, altura);
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
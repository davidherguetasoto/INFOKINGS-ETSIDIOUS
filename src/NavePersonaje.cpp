#include "NavePersonaje.h"
#include "freeglut.h"

NavePersonaje::NavePersonaje():Nave(VIDA_MAX)//poner vida_max luego
{
	altura = 2.0f;
	radio = 0.5f;
	color.set(0, 0, 255);
	num_bonus = 0;//num_bonus para inicializarlo a 0 prueba
	num_misiles = 3;
	disparo_misiles = false;
	disparo_doble = false;
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
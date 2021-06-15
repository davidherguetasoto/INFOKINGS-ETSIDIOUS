#include "NavePersonaje.h"
#include "freeglut.h"

NavePersonaje::NavePersonaje():Nave(VIDA_MAX)//poner vida_max luego
{
	t_DisparoDoble = 0;
	altura = 2.5f; //5
	radio = 0.875f; //1.75

	num_bonus = 0;//num_bonus para inicializarlo a 0 prueba
	num_misiles = 3;
	disparo_misiles = false;
	disparo_doble = false;
	sprite_nave.setCenter(radio*2, altura);
	sprite_nave.setSize(radio*4, altura*2);
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
void NavePersonaje::set_t_DisparoDoble(float t)
{
	t_DisparoDoble = t;
	if (t_DisparoDoble < 0)
		t_DisparoDoble = 0;
}
#include "Mundo.h"
#include "freeglut.h"
Mundo::Mundo():x_ojo(0),y_ojo(0),z_ojo(0)
{

}
Mundo::~Mundo()
{
	
}
void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5f;
	z_ojo = 35.0f;
}
void Mundo::Dibuja()
{
	//PUNTO DE VISTA DE LA CÁMARA
	gluLookAt(x_ojo, y_ojo, z_ojo, // posicion del ojo
		0.0, y_ojo, 0.0, // hacia que punto mira
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Z)
	
	//DIBUJAR OBJETOS DE LA PANTALLA
	caja.Dibuja();

}
void Mundo::Mueve(float t)
{

}
void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{

	}
}
void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{

	}
}
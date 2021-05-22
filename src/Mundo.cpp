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
	x_ojo = x;
	y_ojo = y;
	z_ojo = z;
	
}
void Mundo::Dibuja()
{
	//PUNTO DE VISTA DE LA CÁMARA
	gluLookAt(x, y, z, // posicion del ojo
		0.0, 8, 0.0, // hacia que punto mira
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Z)
	
	//DIBUJAR OBJETOS DE LA PANTALLA
	caja.Dibuja();
	personaje.Dibuja();
	asteroide.Dibuja();
}
void Mundo::Mueve(float t)
{
	personaje.Mueve(t);
	asteroide.Mueve(t);
}
void Mundo::Tecla(unsigned char key)
{
	//TECLAS PARA CAMBIAR EL PUNTO DE VISTA DURANTE EL DESARROLLO
	switch (key)
	{
	case'z':
	{
		x++;
		break;
	}
	case'x':
	{
		x--;
		break;
	}
	case'c':
	{
		y++;
		break;
	}
	case'v':
	{
		y--;
		break;
	}
	case'b':
	{
		z++;
		break;
	}
	case'n':
	{
		z--;
		break;
	}
	case' ':
	{
		personaje.setVel(0.0, 0.0);
		break;
	}
	}
}
void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		personaje.setVel(-5.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		personaje.setVel(5.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		personaje.setVel(0.0f, 5.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		personaje.setVel(0.0f, -5.0f);
		break;
	}
}
}
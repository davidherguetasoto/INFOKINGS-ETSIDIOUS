#include "Pared.h"
#include"freeglut.h"
#include<math.h>
Pared::Pared()
{
	
}
Pared::~Pared()
{

}
void Pared::dibuja()
{
	glDisable(GL_LIGHTING);
	color.ponColor();
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y,0);
	glVertex3d(limite2.x, limite2.y,-1);
	glVertex3d(limite2.x, limite2.y,0);
	glVertex3d(limite1.x, limite1.y,-1);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	color.set(r, g, b);
}

void Pared::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
//Calculo de distancia de una pared a un punto
Vector2D Pared::distancia(Vector2D punto)
{
	Vector2D vpared(limite2 - limite1);
	Vector2D pos = punto - limite2; //Posición de la nave respecto un extremo de la pared
	Vector2D pos2 = punto - limite1;
	Vector2D distancia, proyeccion;
	float angulo; //angulo entre los vectores
	angulo = acos((pos * vpared) / (pos.modulo() * vpared.modulo()));
	proyeccion = vpared.unitario() * pos.modulo() * cos(angulo);
	distancia = proyeccion - pos; //Vector distancia entre la pared y la nave

	//Solo mide la distancia perpendicular a la pared
	if (pos.modulo() < vpared.modulo() && pos2.modulo() < vpared.modulo())
		return distancia;

	//Si el punto está fuera del plano prependicular a la pared, devuelve valor erróneo
	else
	{
		distancia.x = 1000;
		distancia.y = 1000;
		return(distancia);
	}

}
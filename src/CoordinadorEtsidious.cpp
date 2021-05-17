#include "CoordinadorEtsidious.h"
CoordinadorEtsidious::CoordinadorEtsidious()
{
	estado = Estado::INICIO;
}
CoordinadorEtsidious::~CoordinadorEtsidious()
{
	mundo.~Mundo();
}
void CoordinadorEtsidious::Dibuja()
{
	if (estado == Estado::INICIO)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
	}
	else if (estado == Estado::JUEGO)
	{
		mundo.Dibuja();
	}
	else if(estado==Estado::GAMEOVER)
	{

	}
	else if (estado == Estado::FIN)
	{

	}
	else if (estado == Estado::PAUSA)
	{

	}
	else if (estado == Estado::RANKING)
	{

	}
}
void CoordinadorEtsidious::Tecla(unsigned char key)
{
	if (estado == Estado::INICIO)
	{
		if (key == 'e')
		{
			mundo.Inicializa();
			estado = Estado::JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == Estado::JUEGO)
	{

	}
	else if (estado == Estado::GAMEOVER)
	{

	}
	else if (estado == Estado::FIN)
	{

	}
	else if (estado == Estado::PAUSA)
	{

	}
	else if (estado == Estado::RANKING)
	{

	}
}
void CoordinadorEtsidious::teclaEspecial(unsigned char key)
{

}
void CoordinadorEtsidious::Inicializa()
{
	mundo.Inicializa();
}
void CoordinadorEtsidious::Mueve(float t)
{
	if (estado == Estado::JUEGO)
	{
		mundo.Mueve(t);
	}
}
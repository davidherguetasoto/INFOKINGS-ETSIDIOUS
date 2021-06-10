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
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("infokings presenta...", -4, 12);
		ETSIDI::printxy("ETSIDIUOS", -2.2, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("Realizado por:", -2, 4);
		ETSIDI::printxy("Adrián Bedmar Juanas", -3, 3);
		ETSIDI::printxy("Luis Torres del Nuevo", -3, 2);
		ETSIDI::printxy("Natalia Borlaf Nieto", -3, 1);
		ETSIDI::printxy("David Hergueta Soto", -3, 0);
		ETSIDI::printxy("Guillermo Úbeda Romero", -3, -1);
	}
	else if (estado == Estado::NIVEL1)
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
		if (key == 'e'||key=='E')
		{
			mundo.Inicializa();
			estado = Estado::NIVEL1;
		}
		if (key == 's'||key=='S')
			exit(0);
	}
	else if (estado == Estado::NIVEL1)
	{
		mundo.Tecla(key);
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
	if (estado == Estado::NIVEL1)
	{
		mundo.teclaEspecial(key);
	}
}
void CoordinadorEtsidious::teclaEspecialUp(unsigned char key)
{
	if (estado == Estado::NIVEL1)
		mundo.teclaEspecialUp(key);
}
void CoordinadorEtsidious::Inicializa()
{
	mundo.Inicializa();
}
void CoordinadorEtsidious::Mueve(float t)
{
	if (estado == Estado::NIVEL1)
	{
		mundo.Mueve(t);
	}
}
#include "CoordinadorEtsidious.h"
CoordinadorEtsidious::CoordinadorEtsidious()
{
	estado = Estado::INICIO;
}
CoordinadorEtsidious::~CoordinadorEtsidious()
{
	mundo.~Mundo();
}
void CoordinadorEtsidious::dibuja()
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
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR LA AVENTURA", -8, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("Realizado por:", -1, 4);
		ETSIDI::printxy("Adrian Bedmar Juanas", -2, 3);
		ETSIDI::printxy("Luis Torres del Nuevo", -2, 2);
		ETSIDI::printxy("Natalia Borlaf Nieto", -2, 1);
		ETSIDI::printxy("David Hergueta Soto", -2, 0);
		ETSIDI::printxy("Guillermo Ubeda Romero", -2, -1);
	}
	else if (estado == Estado::JUEGO)
	{
		mundo.dibuja();
	}
	else if(estado==Estado::GAMEOVER)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 3);
	}
	else if (estado == Estado::FIN)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, has salvado el mundo", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
	else if (estado == Estado::PAUSA)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == Estado::RANKING)
	{

	}
}
void CoordinadorEtsidious::tecla(unsigned char key)
{
	if (estado == Estado::INICIO)
	{
		if (key == 'e'||key=='E')
		{
			mundo.inicializa();
			estado = Estado::JUEGO;
		}
		if (key == 's'||key=='S')
			exit(0);
	}
	else if (estado == Estado::JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p' || key=='P') {
			estado = Estado::PAUSA;
		}
	}
	else if (estado == Estado::GAMEOVER || estado == Estado::FIN)
	{
		if (key == 'c' || key == 'C')
			estado = Estado::INICIO;
	}
	else if (estado == Estado::PAUSA)
	{
		if (key == 'c' || key == 'C')
			estado = Estado::JUEGO;
	}
	else if (estado == Estado::RANKING)
	{

	}
}
void CoordinadorEtsidious::teclaEspecialUp(unsigned char key)
{
	if (estado == Estado::JUEGO)
		mundo.teclaEspecialUp(key);
}
void CoordinadorEtsidious::teclaEspecial(unsigned char key)
{
	if (estado == Estado::JUEGO)
	{
		mundo.teclaEspecial(key);
	}
}
void CoordinadorEtsidious::inicializa()
{
	mundo.inicializa();
}
void CoordinadorEtsidious::aleatorio()
{
	if (estado == Estado::JUEGO)
	{
		mundo.aleatorio();
	}
}
void CoordinadorEtsidious::mueve(float t)
{
	if (estado == Estado::JUEGO)
	{
		mundo.mueve();
		if (mundo.getNumEnemigos() == 0) {	//si los enemigos se reducen a 0
			if (!mundo.cargarNivel())		//se carga nivel
				estado = Estado::FIN;		//si nivel>3, WIN!
		}
		if (mundo.personaje.getVida() == 0) {
			estado = Estado::GAMEOVER;
		}
	}
}


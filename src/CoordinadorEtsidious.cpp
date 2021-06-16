#include "CoordinadorEtsidious.h"
#include<string>
#include<sstream>
using namespace std;
CoordinadorEtsidious::CoordinadorEtsidious()
{
	estado = Estado::INICIO;
	mundo = new Mundo;
	puntuacion = 0;
	flag_mundo = true;
}
CoordinadorEtsidious::~CoordinadorEtsidious()
{
	if(flag_mundo)
	delete mundo;
}
void CoordinadorEtsidious::dibuja()
{
	//PASO DE LA PUNTUACIÓN OBTENIDA A UN STRING, PARA PODERLA IMPRIMIR
	string puntos;
	stringstream sstr;
	sstr << puntuacion;
	sstr >> puntos;

	//DIBUJOS QUE APARECERÁN EN CADA ESTADO DEL JUEGO
	if (estado == Estado::INICIO)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("infokings presenta...", -4, 13);
		ETSIDI::printxy("ETSIDIUOS", -2.2, 11);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR LA AVENTURA", -8, 8);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA VER LOS CONTROLES", -8, 6);
		ETSIDI::printxy("Realizado por:", -1, 4);
		ETSIDI::printxy("Adrian Bedmar Juanas", -2, 3);
		ETSIDI::printxy("Luis Torres del Nuevo", -2, 2);
		ETSIDI::printxy("Natalia Borlaf Nieto", -2, 1);
		ETSIDI::printxy("David Hergueta Soto", -2, 0);
		ETSIDI::printxy("Guillermo Ubeda Romero", -2, -1);
	}
	else if (estado == Estado::JUEGO)
	{
		mundo->dibuja();
	}
	else if(estado==Estado::GAMEOVER)
	{
		mundo->dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -10, 10);
		ETSIDI::printxy("Tu puntuacion: ", -10, 7);
		ETSIDI::printxy(puntos.c_str(), -1, 7);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 3);
	}
	else if (estado == Estado::FIN)
	{
		mundo->dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, has salvado el mundo!", -10, 10);
		ETSIDI::printxy("Tu puntuacion: ", -10, 7);
		ETSIDI::printxy(puntos.c_str(), -1, 7);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 3);
	}
	else if (estado == Estado::PAUSA)
	{
		mundo->dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == Estado::CONTROLES)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		//EXPLICACIÓN DEL JUEGO
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SUMERGETE EN LA AVENTURA", -10, 17);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Los malvados alienigenas del planeta BEBEAWA han desplegado", -12, 15);
		ETSIDI::printxy("sus tropas para dominar la Tierra. Solo tu puedes salvar a la", -12, 14);
		ETSIDI::printxy("humanidad. Evita ser golpeado por los disparos enemigos y los", -12, 13);
		ETSIDI::printxy("asteroides, o tu vida se vera mermada.", -12, 12);
		ETSIDI::printxy("Solo podras destruir los asteroides con ayuda de tus misiles", -12, 11);
		ETSIDI::printxy(" Obten las diferentes bonificaciones y acaba con todos los enemigos", -12, 10);
		ETSIDI::printxy("para conseguir la mayor puntuacion posible.", -12, 9);
		ETSIDI::printxy("Te apuntas?", -12, 8);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Collage.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(6 , 0);
		glTexCoord2d(1, 1); glVertex2f(14, 0);
		glTexCoord2d(1, 0); glVertex2f(14 , 9);
		glTexCoord2d(0, 0); glVertex2f(6, 9);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("CONTROLES:", -10, 6);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Utilice las flechas para moverse", -12, 5);
		ETSIDI::printxy("Utilice la tecla espacio para disparar", -12, 4);
		ETSIDI::printxy("Utilice la tecla d para activar el disparo de misiles ", -12, 3);
		ETSIDI::printxy("Utilice la tecla p para poner en pausa el juego", -12, 2);
		ETSIDI::printxy("Pulsa -S- para volver al menu principal", -8, 0);
	}
}
void CoordinadorEtsidious::tecla(unsigned char key)
{
	if (estado == Estado::INICIO)
	{
		if (key == 'e'||key=='E')
		{
			if (!flag_mundo)
			{
				mundo = new Mundo;
				flag_mundo = true;
			}
			mundo->inicializa();
			estado = Estado::JUEGO;
		}
		if (key == 's' || key == 'S')
		{
			exit(0);
		}
		if (key == 'c' || key == 'C')
		{
			estado = Estado::CONTROLES;
		}
	}
	else if (estado == Estado::JUEGO)
	{
		mundo->tecla(key);
		if (key == 'p' || key=='P') {
			estado = Estado::PAUSA;
		}
	}
	else if (estado == Estado::GAMEOVER || estado == Estado::FIN)
	{
		if (key == 'c' || key == 'C')
		{
			estado = Estado::INICIO;
			if (flag_mundo)
			{
				delete mundo;
				flag_mundo = false;
				ETSIDI::playMusica("sonidos/Title_Screen_Them.mp3", true);
			}
		}
	}
	else if (estado == Estado::PAUSA)
	{
		if (key == 'c' || key == 'C')
			estado = Estado::JUEGO;
	}
	else if (estado == Estado::CONTROLES)
	{
		if (key == 's' || key == 'S')
			estado = Estado::INICIO;
	}
}
void CoordinadorEtsidious::teclaUp(unsigned char key)
{
	if (estado == Estado::JUEGO)
		mundo->teclaUp(key);
}
void CoordinadorEtsidious::teclaEspecialUp(int key)
{
	if (estado == Estado::JUEGO)
		mundo->teclaEspecialUp(key);
}
void CoordinadorEtsidious::teclaEspecial(int key)
{
	if (estado == Estado::JUEGO)
	{
		mundo->teclaEspecial(key);
	}
}
void CoordinadorEtsidious::inicializa()
{
	mundo->inicializa();
	if (estado == Estado::INICIO)
	{
		ETSIDI::playMusica("sonidos/Title_Screen_Them.mp3", true);
	}
}
void CoordinadorEtsidious::aleatorio()
{
	if (estado == Estado::JUEGO)
	{
		mundo->aleatorio();
	}
}
void CoordinadorEtsidious::mueve(float t)
{
	if (estado == Estado::JUEGO)
	{
		ETSIDI::stopMusica();
		mundo->mueve(t);
		if (mundo->getNumEnemigos() == 0) {	//si los enemigos se reducen a 0
			if (!mundo->cargarNivel())		//se carga nivel
				estado = Estado::FIN;		//si nivel>3, WIN!
			ETSIDI::play("sonidos/victoria.wav");
			puntuacion = mundo->getPuntos();
		}
		if (mundo->personaje.getVida() == 0) {
			estado = Estado::GAMEOVER;
			puntuacion = mundo->getPuntos();
			ETSIDI::play("sonidos/derrota.wav");
		}
	}
}


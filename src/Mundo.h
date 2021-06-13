/*La clase mundo es desde donde se llamarán a todos los objetos
que deban aparecer en pantalla para que sean creados, así como
de pedirles que se muevan, o tambiénde hacer otras acciones 
dependiendo de entradas del usuario por teclado*/

#pragma once
//#include "Bonus.h"
#include "Caja.h"
#include "Interaccion.h"
#include "ListaObstaculos.h"
#include "ListaEnemigos.h"
#include "NavePersonaje.h"
#include "Obstaculo.h"
#include "ListaDisparos.h"
#include"ListaBonus.h"
#include"ETSIDI.h"
using ETSIDI::SpriteSequence;

class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;

	//Bonus bonus;
	Caja caja;
	NavePersonaje personaje;
	ListaObstaculos asteroides;
	ListaEnemigos enemigos;
	ListaDisparos disparos;
	ListaBonus bonus;

	int nivel;
	float t_DisparoDoble;

public:
	Mundo();
	virtual ~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	void inicializa();
	void mueve(float t);
	void dibuja();
	void aleatorio();

	int getNumEnemigos();
	bool cargarNivel();

	friend class CoordinadorEtsidious;
};
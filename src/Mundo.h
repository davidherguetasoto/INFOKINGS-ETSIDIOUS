/*La clase mundo es desde donde se llamar�n a todos los objetos
que deban aparecer en pantalla para que sean creados, as� como
de pedirles que se muevan, o tambi�nde hacer otras acciones 
dependiendo de entradas del usuario por teclado*/

#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Interaccion.h"
#include "ListaObstaculos.h"
#include "ListaEnemigos.h"
#include "NavePersonaje.h"
#include "Obstaculo.h"

class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Bonus bonus;
	Caja caja;
	NavePersonaje personaje;
	ListaObstaculos asteroides;
	ListaEnemigos enemigos;

	int nivel;

public:
	Mundo();
	virtual ~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();

	int getNumEnemigos();
	bool cargarNivel();

	friend class CoordinadorEtsidious;
};
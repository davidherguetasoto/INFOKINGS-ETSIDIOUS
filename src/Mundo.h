/*La clase mundo es desde donde se llamarán a todos los objetos
que deban aparecer en pantalla para que sean creados, así como
de pedirles que se muevan, o tambiénde hacer otras acciones 
dependiendo de entradas del usuario por teclado*/

#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Interaccion.h"
#include "ListaObstaculos.h"
#include "ListaDisparosAliados.h"
#include "ListaEnemigos.h"
#include "ListaMisiles.h"
#include "NavePersonaje.h"
#include "Obstaculo.h" //se podría quitar?


//class Mundo
//{
//private:
//	float x_ojo;
//	float y_ojo;
//	float z_ojo;
//public:
//	float x = 0, y = 8, z = 40;
//	Caja caja;
//	NavePersonaje personaje;
//	ListaObstaculos asteroides;
//	ListaDisparos disparos;
//
//	Mundo();
//	virtual ~Mundo();
//	void Tecla(unsigned char key);
//	void Inicializa();
//	void Mueve(float t);
//	void Dibuja();
//	void teclaEspecial(unsigned char key);
//	void teclaEspecialUp(unsigned char key);
//	
//};

class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Bonus bonus;
	Caja caja;
	NavePersonaje personaje;
	ListaObstaculos asteroides;
	ListaDisparosAliados disparos;
	ListaEnemigos enemigos;
	ListaMisiles misiles;

	bool impacto;
	float nivel;

public:
	Mundo();
	virtual ~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key, bool& b);
	void teclaEspecialUp(unsigned char key, bool& b);
	void inicializa();
	void mueve();
	void dibuja();

	bool getImpacto();
	int getNumEnemigos();
	bool cargarNivel();
};
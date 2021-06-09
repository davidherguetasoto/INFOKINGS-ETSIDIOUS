/*La clase mundo es desde donde se llamarán a todos los objetos
que deban aparecer en pantalla para que sean creados, así como
de pedirles que se muevan, o tambiénde hacer otras acciones 
dependiendo de entradas del usuario por teclado*/

#pragma once
#include"Caja.h"
#include"NavePersonaje.h"
#include"Obstaculo.h"
#include "ListaObstaculos.h"
#include "ListaDisparos.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
public:
	float x = 0, y = 8, z = 40;
	Caja caja;
	NavePersonaje personaje;
	ListaObstaculos asteroides;
	ListaDisparos disparos;

	Mundo();
	virtual ~Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void Mueve(float t);
	void Dibuja();
	void teclaEspecial(unsigned char key);
	
};


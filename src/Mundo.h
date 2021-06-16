/*La clase mundo es desde donde se llamarán a todos los objetos
que deban aparecer en pantalla para que sean creados, así como
de pedirles que se muevan, o tambiénde hacer otras acciones 
dependiendo de entradas del usuario por teclado*/

#pragma once
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

	Caja caja;
	NavePersonaje personaje;
	ListaObstaculos asteroides;
	ListaEnemigos enemigos;
	ListaDisparos disparos;
	ListaBonus bonus;

	int nivel;
	int puntuacion; //Puntuación del jugador
	bool pressed_spacebar; //Variable auxiliar para gestionar flancos negativos en tecla espacio
	void incrementa(float p); //Método para incrementar la puntuación del jugador

public:
	Mundo();
	virtual ~Mundo();
	void tecla(unsigned char key);
	void teclaUp(unsigned char key);
	void teclaEspecial(int key);
	void teclaEspecialUp(int key);
	void inicializa();
	void mueve(float t);
	void dibuja();
	void aleatorio();
	void bonus_aleatorio(NaveEnemiga n,int limRand);
	void bonus_aleatorio(Obstaculo n, int limRand);
	int getNumEnemigos(){return enemigos.getNumero(); }
	bool cargarNivel();
	float getPuntos() { return puntuacion; }
	friend class CoordinadorEtsidious;
};
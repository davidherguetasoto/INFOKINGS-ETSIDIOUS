#pragma once
#include "Obstaculo.h"
#define MAX 20

class ListaObstaculos
{
	Obstaculo* lista[MAX];
	int num;

public:
	ListaObstaculos();

	void destruirContenido();
	void eliminar(int index); //elimina esfera por su posición en la lista
	void eliminar(Obstaculo* o); //elimina la esfera indica explícitamente

	bool agregar(Obstaculo* o);	//devuelve 1 si no se ha alcanzado max
								// y 0 si no se ha podido crear

	
	Obstaculo* operator[](int i);
	
	void mueve(float);
	void dibuja();

	int getNum() { return num; }
};


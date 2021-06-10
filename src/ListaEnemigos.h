#pragma once
#include "NaveEnemiga.h"
#define MAX_ENEMIGOS 20

class ListaEnemigos
{
	NaveEnemiga* lista[MAX_ENEMIGOS];
	int numero;
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();

	void destruirContenido();
	bool agregar(NaveEnemiga* n);	//devuelve 1 si no se ha alcanzado max
									//y 0 si no se ha podido crear
	void eliminar(int index);		//elimina enemigo por su posición en la lista
	void eliminar(NaveEnemiga* n);	//elimina enemigo indicada explícitamente

	void mueve(float t);
	void dibuja();

	NaveEnemiga* operator[](int i);
	int getNumero() { return numero; }
};

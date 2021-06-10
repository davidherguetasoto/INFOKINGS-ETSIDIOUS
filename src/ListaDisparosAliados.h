#pragma once
#include "disparo.h"
#define MAX_DISPAROS 50
class ListaDisparosAliados
{
public:
	ListaDisparosAliados();
	virtual ~ListaDisparosAliados();
	bool agregar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	

	void eliminar(int index); //elimina disparo por su posición en la lista
	void eliminar(Disparo* d); //elimina disparo indicada explícitamente
	Disparo* operator[](int i);
	int getNumero() { return numero; }

private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
};


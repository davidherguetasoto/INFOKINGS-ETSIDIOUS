#pragma once
#include "ListaDisparos.h"
#define MAX_DISPAROS 100
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos
{

private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
public:
	ListaDisparos();
	//virtual ~ListaDisparos();

	bool agregar(Disparo* d);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Disparo* d);

	void mueve(float t);
	void dibuja();

	//INTERACCIONES DE LOS DISPAROS
	void colision(Caja c);

	int getNumero() { return numero; }
	Disparo* operator [](int i);
};
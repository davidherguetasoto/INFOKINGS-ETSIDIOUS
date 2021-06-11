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

	bool Agregar(Disparo* d);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Disparo* d);

	void Mueve(float t);
	void Dibuja();

	//void colision(Pared p);
	//void colision(Caja c);

	int getNumero() { return numero; }
	Disparo* operator [](int i);
};
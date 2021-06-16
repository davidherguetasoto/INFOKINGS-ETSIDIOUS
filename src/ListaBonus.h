#pragma once
#include"Bonus.h"
#include"Interaccion.h"
#include"Vector2D.h"
#include"ETSIDI.h"



#define MAX_BONUS 100


class ListaBonus
{
	friend class Bonus;
private:
	Bonus *lista[MAX_BONUS];
	//BonusDisparoDoble* lista[MAX_BONUS];
	//BonusMisiles* lista[MAX_BONUS];
	//BonusPuntExtras* lista[MAX_BONUS];
	//BonusVidas* lista[MAX_BONUS];
	int numero;
public:
	ListaBonus(); 
	bool agregar(Bonus* b);
	int GetNumero();
	void Dibuja();
	void Mueve(float t);
	void eliminar(int index);
	void eliminar(Bonus* b);
	void colision(Pared p);
	void destruirContenido();
	Bonus* operator[](int i);
	int getNumero();
};


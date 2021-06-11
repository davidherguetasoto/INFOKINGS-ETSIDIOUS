#pragma once
#include "Nave.h"
#include "ColorRGB.h"
#define VELOCIDAD_PERSONAJE 15.0f //Macro para decidir el valor de la velocidad a la que irá el personaje
class NavePersonaje :public Nave
{
public:
	//prueba bonus
	void IncrementaNumBonus();
	void SetNumBonuns(int num);
	int GetNumBonus();
	//prueba bonus
protected:
	//PROVISIONAL PARA HACER DIBUJOS DE PRUEBA
	float altura;
	float radio;
	ColorRGB color;
	//prueba bonus
	int num_bonus;
	int num_misiles; //Contador de los misiles que podemos disparar
public:
	NavePersonaje();
	void dibuja(); //Define cómo se dibuja el personaje
	friend class Interaccion;
};
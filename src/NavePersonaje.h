#pragma once
#include "Nave.h"
#include "ColorRGB.h"
#define VELOCIDAD_PERSONAJE 15.0f //Macro para decidir el valor de la velocidad a la que irá el personaje
#define MISILES_MAX 10 //Número máximo de misiles que puede llevar la nave
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
	bool disparo_misiles; //Modo de disparo
	int num_misiles; //Contador de los misiles que podemos disparar
public:
	NavePersonaje();
	void dibuja(); //Define cómo se dibuja el personaje
	friend class Interaccion;
	float getRadio() { return radio; }
	float getAltura() { return altura; }
	int getNumMisiles() { return num_misiles; }
	void setNumMisiles(int misiles);

	//TRUE:= La nave dispara misil, FALSE:=Disparo normal
	void setDisparoMisiles(bool modo) { disparo_misiles = modo; }
	bool getModoDisparo() { return disparo_misiles; }
};
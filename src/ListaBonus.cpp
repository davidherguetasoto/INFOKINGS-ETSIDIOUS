#include "ListaBonus.h"

ListaBonus::ListaBonus()
{
	numero = 0;
	for (int i = 0; i < MAX_BONUS; i++)
		lista[i] = 0;
}

bool ListaBonus::agregar(Bonus* b)
{

	if (numero < MAX_BONUS)
		lista[numero++] = b;
	else
		return false;
	return true;
}

int ListaBonus::GetNumero()
{
	return numero;
}

void ListaBonus::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaBonus::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaBonus::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;

	//Recolocar los disparos después de borrar uno para que no haya huecos en la lista
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}


void ListaBonus::eliminar(Bonus* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b)
		{
			eliminar(i);
			return;
		}
}

void ListaBonus::colision(Pared p)
{
	for (int i = 0; i < numero; i++)
	{
		int tipo = lista[i]->getTipo();
		if (tipo == BONUS_DISPARO_DOBLE)
		{
			BonusDisparoDoble* b = (BonusDisparoDoble*)lista[i];
			if (Interaccion::colision(*b, p))eliminar(b);
		}
		if (tipo == BONUS_MISILES)
		{
			BonusMisiles* b = (BonusMisiles*)lista[i];
			if (Interaccion::colision(*b, p))eliminar(b);
		}
		if (tipo == BONUS_PUNT_EXTRAS)
		{
			BonusPuntExtras* b = (BonusPuntExtras*)lista[i];
			if (Interaccion::colision(*b, p))eliminar(b);
		}
		if (tipo == BONUS_VIDAS)
		{
			BonusVidas* b = (BonusVidas*)lista[i];
			if (Interaccion::colision(*b, p))eliminar(b);
		}
	}
}

void ListaBonus::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

Bonus* ListaBonus::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}


int ListaBonus::getNumero()
{
	return numero;
}

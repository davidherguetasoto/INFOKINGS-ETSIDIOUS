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

}


void ListaBonus::eliminar(Bonus* b)
{

}

Bonus* ListaBonus::colision(NavePersonaje& n)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*lista[i], n))
			return lista[i];
	}
	return 0;
}


void ListaBonus::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

Bonus* ListaBonus::operator[](int i)
{

}

int ListaBonus::getNumero()
{
	return numero;
}

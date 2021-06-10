#include "ListaEnemigos.h"
#include "Interaccion.h"

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos()
{
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de enemigos contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}

bool ListaEnemigos::agregar(NaveEnemiga* n)
{
	if (numero < MAX_ENEMIGOS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == n)
				return true;
		}
		lista[numero++] = n; // último puesto sin rellenar
							 // Después de añadir la NaveEnemiga, incrementa numero
	}
	else
		return false; // capacidad máxima alcanzada
	return true; //no se ha alcanzado la capacidad max
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::eliminar(NaveEnemiga* n)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == n)
		{
			eliminar(i); //reutilización del código anterior
			return;
		}
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

NaveEnemiga* ListaEnemigos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

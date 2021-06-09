#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

ListaDisparos::~ListaDisparos()
{

}

bool ListaDisparos::agregar(Disparo* d) {
	if (numero < MAX_DISPAROS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == d)
				return true; //no se ha alcanzado la capacidad max
		}
		lista[numero++] = d; // último puesto sin rellenar
							 // Después de añadir el disparo, incrementa numero
	}
	else
		return false; // capacidad máxima alcanzada
	return true; //no se ha alcanzado la capacidad max
}

void ListaDisparos::destruirContenido() {
	for (int i = 0; i < numero; i++) // destrucción de disparos contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaDisparos::Mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaDisparos::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(Disparo* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			eliminar(i); //reutilización del código anterior
			return;
		}
}

Disparo* ListaDisparos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

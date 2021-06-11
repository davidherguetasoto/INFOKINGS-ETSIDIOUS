#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos() :numero(0)
{
	for (int i = 0; i < MAX_DISPAROS; i++)lista[i] = 0;
}
bool ListaDisparos::Agregar(Disparo* d)
{
	if (numero < MAX_DISPAROS && lista[numero] != d) {
		lista[numero++] = d;

		//SONIDO A REPRODUCIR AL DISPARAR
		//SE PUEDEN PONER DISTINTOS SONIDOS PARA CADA DISPARO
		//ETSIDI::play("sonidos/disparo.wav");
	}
	else return FALSE;
	return TRUE;
}
void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++)delete lista[i];
	numero = 0;
}
void ListaDisparos::Mueve(float t)
{
	for (int i = 0; i < numero; i++)lista[i]->mueve(t);
}
void ListaDisparos::Dibuja()
{
	for (int i = 0; i < numero; i++)lista[i]->dibuja();
}

//DESTRUCCI�N DE UN DISPARO DE LA LISTA
void ListaDisparos::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	//Recolocar los disparos despu�s de borrar uno para que no haya huecos en la lista
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaDisparos::Eliminar(Disparo* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			Eliminar(i);
			return;
		}
}
//SOBRECARGA DEL OPERADOR [] PARA EVITAR ERRORES A LA HORA DE LLAMAR A CADA ELEMENTO DE LA LISTA
Disparo* ListaDisparos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
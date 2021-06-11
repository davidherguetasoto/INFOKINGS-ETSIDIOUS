#include "Factoria.h"
#include"Nave.h"
#include"NavePersonaje.h"
#include"disparo.h"
#include "DisparoAliado.h"
#include"DisparoTriple.h"
#include"Misil.h"

Disparo* Factoria::CrearDisparo(NavePersonaje h)
{
	Disparo* d = 0;
	if (h.GetNumBonus() == 1)
		d = new DisparoAliado;//esta mal falta de crear el disparlo misil, y disparo normal.
	else if (h.GetNumBonus() == 2)
		d = new DisparoTriple;//esta mal faltan cosas de la calse disparo
	else
		d = new Misil;//esta mal faltan cosas de la clase disparo
}
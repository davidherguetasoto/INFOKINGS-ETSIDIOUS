#include "Factoria.h"
#include"Nave.h"
#include"NavePersonaje.h"
#include"disparo.h"
#include "DisparoAliado.h"
#include"DisparoDoble.h"
#include"Misil.h"

Disparo* Factoria::CrearDisparo(NavePersonaje h)
{
	Disparo* d = 0;
	if (h.GetNumBonus() == 1)
		d = new DisparoAliado;//esta mal falta de crear el disparlo misil, y disparo normal.
	else if (h.GetNumBonus() == 2)
		d = new DisparoDoble;//esta mal faltan cosas de la calse disparo
	else
		d = new Misil;//esta mal faltan cosas de la clase disparo

	Vector2D pos = h.getPos();
	d->setPos(pos.x, pos.y);
	return d;
}
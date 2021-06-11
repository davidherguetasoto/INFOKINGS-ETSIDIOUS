#include "Interaccion.h"

bool Interaccion::rebote(NavePersonaje& nave, Pared pared)
{
	Vector2D distancia;
	distancia = pared.distancia(nave.getPos());

	if (distancia.modulo() <= 0.45f )
		return true;
	else return false;
}
void Interaccion::rebote(NavePersonaje& nave, Caja caja)
{
	bool flag_pared_izq, flag_pared_dcha, flag_techo, flag_suelo;
	flag_suelo = rebote(nave, caja.suelo);
	flag_pared_izq = rebote(nave, caja.pared_izq);
	flag_pared_dcha = rebote(nave, caja.pared_dcha);
	flag_techo = rebote(nave, caja.techo);
	if (flag_suelo)
	nave.setPos(nave.posicion.x, caja.suelo.limite1.y+0.45);
	else if (flag_pared_izq)
		nave.setPos(caja.pared_izq.limite1.x+0.45, nave.posicion.y);
	else if (flag_pared_dcha)
		nave.setPos(caja.pared_dcha.limite1.x-0.45, nave.posicion.y);
	else if (flag_techo)
		nave.setPos(nave.posicion.x, caja.techo.limite1.y-0.45);
}

bool Interaccion::rebote(NaveEnemiga& n, Caja c)
{
	return false;
}

bool Interaccion::colision(Obstaculo o, DisparoAliado d)
{
	if (o.getPos() == d.getPos()) {
		return true;
	}
	return false;
}

bool Interaccion::colision(Obstaculo o, Misil m)
{
	if (o.getPos() == m.getPos()) {
		return true;
	}
	return false;
}

//bool Interaccion::colision(Obstaculo o, Caja c)
//{
//	if (Interaccion::colision(o, c.pared_dcha)) return true;
//	else if (Interaccion::colision(o, c.pared_izq)) return true;
//	else if (Interaccion::colision(o, c.suelo)) return true;
//	else if (Interaccion::colision(o, c.techo)) return true;
//	else return false;
//}

bool Interaccion::colision(Obstaculo o, Pared p)
{
	if (o.getPos().y < p.getLim1().y) { return true; }
	return false;
}
//COLISIÓN DE UN DISPARO DE ALIADO CONTRA ENEMIGO
/*bool Interaccion::colision(DisparoAliado d, NaveEnemiga ne)
{
	return false;
}*/

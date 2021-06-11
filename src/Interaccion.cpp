#include "Interaccion.h"
#include<math.h>
bool Interaccion::rebote(NavePersonaje& nave, Pared pared)
{
	Vector2D vpared(pared.limite2 - pared.limite1);
	Vector2D pos = nave.getPos() - pared.limite2; //Posición de la nave respecto un extremo de la pared
	Vector2D pos2 = nave.getPos() - pared.limite1;
	Vector2D distancia,proyeccion;
	float angulo; //angulo entre los vectores
	angulo = acos((pos * vpared) / (pos.modulo() * vpared.modulo()));
	proyeccion = vpared.unitario() * pos.modulo() * cos(angulo);
	distancia = proyeccion - pos; //Vector distancia entre la pared y la nave

	if (distancia.modulo() <= 0.45f && pos.modulo() < vpared.modulo() && pos2.modulo() < vpared.modulo())
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
		//nave.setVel(0.0, 0.0);
	nave.setPos(nave.posicion.x, caja.suelo.limite1.y+0.45);
	else if (flag_pared_izq)
		//nave.setVel(0.0, 0.0);
		nave.setPos(caja.pared_izq.limite1.x+0.45, nave.posicion.y);
	else if (flag_pared_dcha)
		nave.setPos(caja.pared_dcha.limite1.x-0.45, nave.posicion.y);
	else if (flag_techo)
		nave.setPos(nave.posicion.x, caja.techo.limite1.y-0.45);
}

bool Interaccion::rebote(NaveEnemiga& n, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(n.posicion, &dir);
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = n.velocidad;
		n.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		n.posicion = n.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::rebote(NaveEnemiga& n, Caja c)
{
	return false;
}

bool Interaccion::colision(Obstaculo e, DisparoAliado d)
{
	Pared aux; //Creamos una pared auxiliar 
	Vector2D p1 = d.getPos();
	Vector2D p2 = d.getOrig();
	aux.setPos(p1.x, p1.y, p2.x, p2.y); //Que coincida con el disparo.
	float dist = aux.distancia(e.posicion); //para calcular su distancia
	if (dist < e.radio)
		return true;
	return false;
}

bool Interaccion::colision(Disparo d, Caja c)
{
	return false;
}

//COLISIÓN DE UN DISPARO DE ALIADO CONTRA ENEMIGO
/*bool Interaccion::colision(DisparoAliado d, NaveEnemiga ne)
{
	return false;
}*/

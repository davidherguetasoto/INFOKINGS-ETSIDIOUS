#pragma once
#include"Pared.h"
#include"Caja.h"
#include"NavePersonaje.h"
#include "NaveEnemiga.h"
#include "Obstaculo.h"
#include "Disparo.h"
#include "Bonus.h"
#include "DisparoAliado.h"
#include "DisparoEnemigo.h"
#include "Misil.h"

class Interaccion
{
public:
	static bool rebote(NavePersonaje& nave, Pared pared);
	static void rebote(NavePersonaje& nave, Caja caja);
	static bool rebote(NaveEnemiga& n, Pared p);
	static bool rebote(NaveEnemiga& n, Caja c);
	static bool colision(Obstaculo o, DisparoAliado d); //se destruye disparo si impacta con obstaculo
	static bool colision(Obstaculo o, Misil m); //se destruyen ambos al impactar
	//static bool colision(Obstaculo o, Caja c); //obstáculo desaparece al alcanzar límites
	static bool colision(Obstaculo o, Pared p);
	static bool colision(Obstaculo o, NavePersonaje n); //obstáculo merma salud de jugador
	static bool colision(Disparo d, Caja c); //disparo desaparece al llegar al límite de la caja
	static bool colision(DisparoAliado d, NaveEnemiga ne); //daño a enemigos
	static bool colision(DisparoEnemigo d, NavePersonaje n); //daño a jugador
	static bool colision(Bonus b, Caja c); //bonus desaparece al alcanzar caja
	static bool colision(Bonus b, NavePersonaje n); //recogida del bonus
	static bool colision(NaveEnemiga b, NavePersonaje n); //merma salud de personaje al tocarlo
};


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
	//COLISIÓN DE LA NAVE CON LAS PAREDES
	static bool rebote(NavePersonaje& nave, Pared pared);
	static void rebote(NavePersonaje& nave, Caja caja);

	//CHOQUE DE LOS DISPAROS CON LOS OBSTÁCULOS
	static bool colision(Obstaculo o, DisparoAliado d); //se destruye solo el disparo
	static bool colision(Obstaculo o, Misil m); //se destruyen ambos al impactar
	
	//COLISIÓN DEL OBSTÁCULO CON EL SUELO
	static bool colision(Obstaculo o, Pared p);

	//COLISIÓN DEL OBSTÁCULO CON LA NAVE DEL PERSONAJE
	static bool colision(Obstaculo o, NavePersonaje n); //obstáculo merma salud de jugador

	//COLISIÓN DE LOS DISPAROS CON LA CAJA
	static bool colision(DisparoAliado d, Pared p);
	static bool colision(DisparoEnemigo d, Pared p);
	static bool colision(DisparoAliado d, Caja c);
	static bool colision(DisparoEnemigo d, Caja c);
	
	//COLISIÓN DE LOS DISPAROS DE LA NAVE DEL PERSONAJE CON LOS ENEMIGOS
	static bool colision(DisparoAliado d, NaveEnemiga n); //daño a enemigos

	//COLISIÓN DE LOS DISPAROS ENEMIGOS CON LA NAVE DEL PERSONAJE
	static bool colision(DisparoEnemigo d, NavePersonaje n); //daño a jugador

	//CHOQUE DEL BONUS CON LA PARTE INFERIOR DE LA CAJA
	static bool colision(Bonus b, Caja c); //bonus desaparece al alcanzar caja

	//EL JUGADOR RECOGE EL BONUS
	static bool colision(Bonus b, NavePersonaje n); //recogida del bonus

	//CHOQUE DEL PESONAJE CON UNA NAVE ENEMIGA
	static void colision(NaveEnemiga b, NavePersonaje& n); //merma salud de personaje al tocarlo
};


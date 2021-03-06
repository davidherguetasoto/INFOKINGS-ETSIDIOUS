#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
#include <sstream>
#include<string>
#include<cstdlib>

using namespace std;
Mundo::Mundo() :x_ojo(0), y_ojo(0), z_ojo(0), nivel(1),puntuacion(0),pressed_spacebar(false)
{

}
Mundo::~Mundo()
{
	enemigos.destruirContenido();
	asteroides.destruirContenido();
	disparos.destruirContenido();
	bonus.destruirContenido();
}
void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 40;

	nivel = 0;
	cargarNivel();
}
void Mundo::dibuja()
{
	//PASO DEL VALOR DEL TIEMPO DEL DISPARO DOBLE
	//A STRING PARA PODERLO IMPRIMIR
	string tiempo_disparo_doble;
	stringstream sstr;
	sstr.str(std::string());
	sstr.clear();
	sstr<<static_cast<int>(personaje.get_t_DisparoDoble()*0.025);
	sstr >> tiempo_disparo_doble;


	//PUNTO DE VISTA DE LA CÁMARA
	gluLookAt(
		x_ojo, y_ojo, z_ojo, // posicion del ojo
		0.0, y_ojo, 0.0, // hacia que punto mira
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Z)

	//DIBUJAR OBJETOS DE LA PANTALLA
	caja.dibuja();
	personaje.dibuja();
	asteroides.dibuja();
	enemigos.dibuja();
	disparos.dibuja();
	bonus.Dibuja();

	//DIBUJO DEL LETRERO DEL JUEGO
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("ETSIDIOUS", -11, 21);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Infokings", 3.5, 21);

	//DIBUJO DEL NÚMERO DE MISILES DISPONIBLES
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("MISILES:", -3, -6);
	if (personaje.getNumMisiles() > 0)
	{
		for (int i = 0; i < personaje.getNumMisiles(); i++)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/misil_sin_disparar.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex2f(2 + i, -6);
			glTexCoord2d(1, 1); glVertex2f(3 + i, -6);
			glTexCoord2d(1, 0); glVertex2f(3 + i, -5);
			glTexCoord2d(0, 0); glVertex2f(2 + i, -5);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
	}
	//TEXTO MODO DE DISPARO
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("DISPARO:", 12, 18);
	if(personaje.getModoMisiles())
		ETSIDI::printxy("MISIL", 12, 17);
	else if (personaje.getModoDoble())
	{
		ETSIDI::printxy("DOBLE", 12, 17);
		ETSIDI::printxy("TIEMPO:", 12, 15);
		ETSIDI::printxy(tiempo_disparo_doble.c_str(), 12, 14);
	}
	else
		ETSIDI::printxy("NORMAL", 12, 17);
	
	//TEXTO PUNTUACIÓN
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("PUNTOS:", -18, 18);	

	//PASO DEL VALOR DE LA PUNTUACIÓN
	//A STRING PARA PODERLO IMPRIMIR
	string puntos_tot;
	sstr.str(std::string());
	sstr.clear();
	sstr << puntuacion;
	sstr >> puntos_tot;
	ETSIDI::printxy(puntos_tot.c_str(), -16, 17);

	//DIBUJO DE LA VIDA
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("VIDA:", -12, -6);
	for (int i = 0; i < 5; i++) {
		if (personaje.getVida() > 20 * i) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/corazonbueno.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex2f(-9 + i, -6);
			glTexCoord2d(1, 1); glVertex2f(-8 + i, -6);
			glTexCoord2d(1, 0); glVertex2f(-8 + i, -5);
			glTexCoord2d(0, 0); glVertex2f(-9 + i, -5);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
	}
}

void Mundo::mueve(float t)
{
	personaje.mueve(t);
	Interaccion::rebote(personaje, caja);

	asteroides.mueve(t);
	enemigos.mueve(t);

	disparos.mueve(t);
	disparos.colision(caja);

	bonus.Mueve(t);
	bonus.colision(caja.suelo);
	
	//Nivel 1 llegada mediante función matematica a modo de presentación
	if(nivel==1){
		for (int i = 0; i < enemigos.getNumero();i++) {
 			if (enemigos[i]->getPos().y <=(abs( enemigos[i]->getPos().x)+24)/2)
				enemigos[i]->setVel(0.0f, 0.0f);
		}
	}
	// Nivel 2 llegada en bloque como en Space Defenders
	if (nivel == 2) {
		for (int i = 0; i < 5; i++) {
			if (enemigos[i] != NULL && enemigos[i]->getPos().y <= 16)
					enemigos[i]->setVel(0.0f, 0.0f);
		}
		for (int i = 5; i < 10; i++) {
			if (enemigos[i] != NULL && enemigos[i]->getPos().y <= 13)
				enemigos[i]->setVel(0.0f, 0.0f);
		}
	}
	//Nivel 3 Secuencia en cuadrado
	if (nivel == 3) {
		
		for (int i = 0; i < enemigos.getNumero(); i++) {
		//	enemigos[i]->setVel(0.0,-8.0);
			if (enemigos[i] != NULL && enemigos[i]->getVel().y < 0.01 && enemigos[i]->getPos().y <= 2.0 ) //abajo a la derecha
				enemigos[i]->setVel(-10.0f, 0.0f);
			if (enemigos[i] != NULL && enemigos[i]->getVel().x < 0.01 && enemigos[i]->getPos().x <= -8.0 )//abajo a la izquierda
				enemigos[i]->setVel(0.0f, 10.0f);
			if (enemigos[i] != NULL && enemigos[i]->getVel().y > 0.01 && enemigos[i]->getPos().y >= 17.0) //arriba a la izquierda
				enemigos[i]->setVel(10.0f, 0.0f);
			if (enemigos[i] != NULL && enemigos[i]->getVel().x > 0.01 && enemigos[i]->getPos().x >= 8.0) //arriba a la derecha
				enemigos[i]->setVel(0.0f, -10.0);
		}
	}
	
	//GESTIÓN DEL TIEMPO DEL DISPARO DOBLE
	if (personaje.get_t_DisparoDoble() > 0)
	{
		personaje.setDisparoDoble(true);
		personaje.set_t_DisparoDoble(personaje.get_t_DisparoDoble()-1);
	}
	else
	{
		personaje.setDisparoDoble(false);
	}

	//COLISIÓN DE LOS DISPAROS CON LAS NAVES
	for (int i = 0; i < disparos.getNumero(); i++)
	{
		int tipo = disparos[i]->getTipo();
		if (tipo == DISPARO_ALIADO||tipo==DISPARO_DOBLE||tipo==MISIL)
		{
			for (int n = 0; n < enemigos.getNumero(); n++)
			{
				DisparoAliado* d = (DisparoAliado*)disparos[i];
				if (d != NULL)
				{
					if (Interaccion::colision(*d, *enemigos[n]))
					{
						ETSIDI::play("sonidos/impactodisparo.wav");
						enemigos[n]->setVida((enemigos[n]->getVida()) - (disparos[i]->getDano()));
						if (enemigos[n]->getVida() <= 0.0f)
						{
							incrementa(100);
							ETSIDI::play("sonidos/enemigomuere.wav");
							bonus_aleatorio(*enemigos[n],2);
							enemigos.eliminar(enemigos[n]);
						}
						disparos.eliminar(disparos[i]);
					}
				}
			}
		}
		if (tipo == DISPARO_ENEMIGO)
		{
			DisparoEnemigo* d = (DisparoEnemigo*)disparos[i];
			if (d != NULL)
			{
				if (Interaccion::colision(*d, personaje))
				{
					personaje.setVida(personaje.getVida() - disparos[i]->getDano());
					incrementa(-30);
					disparos.eliminar(disparos[i]);
				}
			}
		}
	}

	//COLISIÓN ASTEROIDES CON EL PERSONAJE
	for (int i = 0; i < asteroides.getNum(); i++)
	{
		Obstaculo* o = (Obstaculo*)asteroides[i];
		if (Interaccion::colision(*o, personaje))
		{
			personaje.setVida(personaje.getVida() - asteroides[i]->getDano());
			incrementa(-50);
			ETSIDI::play("sonidos/asteroidedestruido.wav");
			asteroides.eliminar(asteroides[i]);
		}
	}

	//PERSONAJE RECOGE BONUS
	for (int i = 0; i < bonus.getNumero(); i++)
	{
		int tipo = bonus[i]->getTipo();
		if (tipo == BONUS_DISPARO_DOBLE)
		{
			BonusDisparoDoble* b = (BonusDisparoDoble*)bonus[i];
			if (Interaccion::colision(*b, personaje))
			{
				personaje.set_t_DisparoDoble(bonus[i]->getExtra() / t);
				bonus.eliminar(bonus[i]);
			}
		}
		if (tipo == BONUS_VIDAS)
		{
			BonusVidas* b = (BonusVidas*)bonus[i];
			if (Interaccion::colision(*b, personaje))
			{
				personaje.setVida(personaje.getVida() + bonus[i]->getExtra());
				bonus.eliminar(bonus[i]);
			}
			
		}
		if (tipo == BONUS_MISILES)
		{
			BonusMisiles* b = (BonusMisiles*)bonus[i];
			if (Interaccion::colision(*b, personaje))
			{
				personaje.setNumMisiles(personaje.getNumMisiles() + bonus[i]->getExtra());
				bonus.eliminar(bonus[i]);
			}
		}
		if (tipo == BONUS_PUNT_EXTRAS)
		{
			BonusPuntExtras *b = (BonusPuntExtras*)bonus[i];
			if (Interaccion::colision(*b, personaje))
			{
				incrementa(bonus[i]->getExtra());
				bonus.eliminar(bonus[i]);
			}
		}
	}


	//INTERACCIÓN DE LOS DISPAROS CON LOS ASTEROIDES
	for (int i = 0; i < disparos.getNumero(); i++)
	{
		for (int n = 0; n < asteroides.getNum(); n++)
		{
			int tipo = disparos[i]->getTipo();
			if (tipo == DISPARO_ALIADO || tipo == DISPARO_DOBLE)
			{
				DisparoAliado* d = (DisparoAliado*)disparos[i];
				if (Interaccion::colision(*asteroides[n], *d))
				{
					disparos.eliminar(disparos[i]);
				}
			}
			if (tipo == MISIL)
			{
				Misil* m = (Misil*)disparos[i];
				if (Interaccion::colision(*asteroides[n], *m))
				{
					bonus_aleatorio(*asteroides[n], 1);
					asteroides.eliminar(asteroides[n]);
					disparos.eliminar(disparos[i]);
					ETSIDI::play("sonidos/asteroidedestruido.wav");

				}
			}
		}
	}

	//INTERACCION ASTEROIDES SUELO
	for (int i = asteroides.getNum(); i > 0; i--) {
		if (Interaccion::colision(*asteroides[i], caja.suelo)) {
			asteroides.eliminar(asteroides[i]);
		}
	}
}
void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	//DISPARAR
	case' ':
	{
		if (!pressed_spacebar)
		{
			if (disparos.getNumero() < MAX_DISPAROS)
			{
				if (personaje.getModoMisiles())
				{
					if (personaje.getNumMisiles() > 0)
					{
						Disparo* d = new Misil;
						d->setPos(personaje.getPos());
						disparos.agregar(d);
						personaje.setNumMisiles(personaje.getNumMisiles() - 1);
					}
					if (personaje.getNumMisiles() <= 0)personaje.setDisparoMisiles(false);
				}
 				else if (personaje.getModoDoble())
				{
					Disparo* d = new DisparoDoble;
					d->setPos(personaje.getPos().x + 0.5f, personaje.getPos().y);
					disparos.agregar(d);
					d = new DisparoDoble;
					d->setPos(personaje.getPos().x - 0.5f, personaje.getPos().y);
					disparos.agregar(d);
				}
				else
				{
					Disparo* d = new DisparoAliado;
					d->setPos(personaje.getPos());
					disparos.agregar(d);
				}
			}
		}
		pressed_spacebar = true;
 		break;
	}
	//MODO DISPARO
	case'd':
	{
		if (personaje.getModoMisiles())personaje.setDisparoMisiles(false);
		else if (personaje.getNumMisiles() > 0)personaje.setDisparoMisiles(true);
		break;
	}
	case'D':
	{
		if (personaje.getModoMisiles())personaje.setDisparoMisiles(false);
		else if (personaje.getNumMisiles() > 0)personaje.setDisparoMisiles(true);
		break;
	}
	}
 }
void Mundo::teclaUp(unsigned char key)
{
	switch (key)
	{
		//GESTIÓN DE FLANCOS NEGATIVOS DEL ESPACIO PARA EVITAR QUE EL USUARIO
		//DISPARE CONTINUAMENTE AL MANTENER PULSADO
	case' ':
		pressed_spacebar = false;

	}
}
void Mundo::teclaEspecialUp(int key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		if(personaje.getVel().x==-VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (personaje.getVel().x == VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		if (personaje.getVel().y == VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (personaje.getVel().y == -VELOCIDAD_PERSONAJE)
		personaje.setVel(0.0f, 0.0f);
		break;
	}
	}
}

void Mundo::teclaEspecial(int key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		if (personaje.getPos().x>(caja.pared_izq.getLim1().x+2.0f))
		{
			personaje.setVel(-VELOCIDAD_PERSONAJE, 0.0f);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if ((personaje.getPos().x) < (caja.pared_dcha.getLim1().x - 2.0f))
		{
			personaje.setVel(VELOCIDAD_PERSONAJE, 0.0f);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		if (personaje.getPos().y < (caja.techo.getLim1().y - 2.0f))
		{
			personaje.setVel(0.0f, VELOCIDAD_PERSONAJE);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if ((personaje.getPos().y) > (caja.suelo.getLim1().y + 2.0f))
		{
			personaje.setVel(0.0f, -VELOCIDAD_PERSONAJE);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}	
	}
}
bool Mundo::cargarNivel()
{
	nivel++;
	enemigos.destruirContenido();

	if (nivel == 1) {                        //Añadimos el número de enemigos del nivel
		for (int i = 0; i < 5; i++) {
		NaveEnemiga* n = new NaveEnemiga();
		enemigos.agregar(n);
		}
											 
		enemigos[0]->setPos(0.0f, 26.0f);   
		enemigos[1]->setPos(5.0f, 30.0f);   
		enemigos[2]->setPos(-5.0f, 30.0f);   
		enemigos[3]->setPos(-9.0f, 34.0f);    
		enemigos[4]->setPos(9.0f, 34.0f);   
	}
	if (nivel == 2) {

		for (int i = 0; i < 10; i++) {
			NaveEnemiga* n = new NaveEnemiga();
			enemigos.agregar(n);
		}
		//Añadimos el número de enemigos del nivel	
		enemigos[0]->setPos(0.0f, 32.0f);
		enemigos[1]->setPos(2.0f, 32.0f);
		enemigos[2]->setPos(4.0f, 32.0f);
		enemigos[3]->setPos(-2.0f, 32.0f);
		enemigos[4]->setPos(-4.0f, 32.0f);
		enemigos[5]->setPos(0.0f, 29.0f);
		enemigos[6]->setPos(2.0f, 29.0f);
		enemigos[7]->setPos(4.0f, 29.0f);
		enemigos[8]->setPos(-2.0f, 29.0f);
		enemigos[9]->setPos(-4.0f, 29.0f);
	}

	if (nivel == 3) {
		for (int i = 0; i < 7; i++) {
			NaveEnemiga* n = new NaveEnemiga();
			enemigos.agregar(n);
			enemigos[i]->setVel(0.0, -12.0);
		}
		enemigos[0]->setPos(8.0f, 46.0f);
		enemigos[1]->setPos(8.0f, 43.0f);
		enemigos[2]->setPos(8.0f, 40.0f);
		enemigos[3]->setPos(-1.0f, 40.0f);
		enemigos[4]->setPos(2.0f, 40.0f);
		enemigos[5]->setPos(5.0f, 40.0f);
		enemigos[6]->setPos(8.0f, 40.0f);
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::aleatorio()
{
	float lim1 = caja.pared_izq.getLim1().x;
	float lim2 = caja.pared_dcha.getLim1().x;
	int num= 1 + rand() % (11 - 1);
	if (num < 3+nivel)
	{
		float x = (lim1+0.05f) + rand() % (int)(lim2 - lim1);
		Obstaculo* o2 = new Obstaculo();
		o2->setPos(x, caja.techo.getLim1().y);
		asteroides.agregar(o2);
	}
	
	for (int i = 0; i < enemigos.getNumero(); i++)
	{
		int num2 = 1 + rand() % (11 - 1);
		if (num2 < 6)
		{
			Disparo* d = new DisparoEnemigo;
			d->setPos(enemigos[i]->getPos());
			disparos.agregar(d);
		}
	}
}

void Mundo::bonus_aleatorio(NaveEnemiga n,int lim)
{
	int nrandom1;
	int nrandom2;
	nrandom1 = 1 + rand() % lim;
	if (nrandom1 == 1)
	{
		nrandom2 = 1 + rand() % 4;
		if (nrandom2 == 1)
		{
			Bonus* d = new BonusMisiles;
			d->setPos(n.getPos());
			bonus.agregar(d);
		}
		else if (nrandom2 == 2)
		{
			Bonus* c = new BonusDisparoDoble;
			c->setPos(n.getPos());
			bonus.agregar(c);
		}
		else if (nrandom2 == 3)
		{
			Bonus* b = new BonusVidas;
			b->setPos(n.getPos());
			bonus.agregar(b);
		}
		else if (nrandom2 == 4)
		{
			Bonus* a = new BonusPuntExtras;
			a->setPos(n.getPos());
			bonus.agregar(a);
		}
	}
}


void Mundo::bonus_aleatorio(Obstaculo n, int limRand)
{
	int nrandom1;
	int nrandom2;
	nrandom1 = 1 + rand() % limRand;
	if (nrandom1 == 1)
	{
		nrandom2 = 1 + rand() % 4;
		if (nrandom2 == 1)
		{
			Bonus* d = new BonusMisiles;
			d->setPos(n.getPos());
			bonus.agregar(d);
		}
		else if (nrandom2 == 2)
		{
			Bonus* c = new BonusDisparoDoble;
			c->setPos(n.getPos());
			bonus.agregar(c);
		}
		else if (nrandom2 == 3)
		{
			Bonus* b = new BonusVidas;
			b->setPos(n.getPos());
			bonus.agregar(b);
		}
		else if (nrandom2 == 4)
		{
			Bonus* a = new BonusPuntExtras;
			a->setPos(n.getPos());
			bonus.agregar(a);
		}
	}
}

void Mundo::incrementa(float p)
{
	puntuacion += p;

	//GESTION DISPARO NEGATIVO
	if (puntuacion < 0)
		puntuacion = 0;
}
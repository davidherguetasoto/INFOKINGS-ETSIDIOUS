#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
#include <sstream>
#include<string>
using namespace std;
Mundo::Mundo() :x_ojo(0), y_ojo(0), z_ojo(0), nivel(1),t_DisparoDoble(0),puntuacion(0)
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
	Bonus* d = new BonusMisiles;
	d->setPos(6, 12);
	bonus.agregar(d);

	Bonus* b = new BonusVidas;
	b->setPos(6, 15);
	bonus.agregar(b);

	Bonus* c = new BonusDisparoDoble;
	c->setPos(-6, 16);
	bonus.agregar(c);
}
void Mundo::dibuja()
{
	//PASO DEL VALOR DEL TIEMPO DEL DISPARO DOBLE
	//A STRING PARA PODERLO IMPRIMIR
	int t_aux = 0; //variable auxiliar para convertir el tiempo a entero
	t_aux = t_DisparoDoble * 0.025f;
	string tiempo_disparo_doble;
	stringstream sstr;
	const char* c = tiempo_disparo_doble.c_str();
	sstr<<t_aux;
	sstr >> tiempo_disparo_doble;


	//PUNTO DE VISTA DE LA CÁMARA
	gluLookAt(/*x, y, z,*/
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
		ETSIDI::printxy(c, 12, 14);
	}
	else
		ETSIDI::printxy("NORMAL", 12, 17);
	

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

	//Gestion de tiempo de disparo doble
	if (t_DisparoDoble > 0)
	{
		personaje.setDisparoDoble(true);
		t_DisparoDoble -=1;
	}
	else
	{
		personaje.setDisparoDoble(false);
	}

	//Colision de los disparos con naves
	for (int i = 0; i < disparos.getNumero(); i++)
	{
		int tipo = disparos[i]->getTipo();
		if (tipo == DISPARO_ALIADO||tipo==DISPARO_DOBLE||tipo==MISIL)
		{
			for (int n = 0; n < enemigos.getNumero(); n++)
			{
				DisparoAliado* d = (DisparoAliado*)disparos[i];
				if (Interaccion::colision(*d, *enemigos[n]))
				{
					enemigos[n]->setVida((enemigos[n]->getVida()) - (disparos[i]->getDano()));
					if (enemigos[n]->getVida() <= 0.0f)
						enemigos.eliminar(enemigos[n]);
					disparos.eliminar(disparos[i]);
				}
			}
		}
		if (tipo == DISPARO_ENEMIGO)
		{
			DisparoEnemigo* d = (DisparoEnemigo*)disparos[i];
			if (Interaccion::colision(*d, personaje))
			{
				personaje.setVida(personaje.getVida() - disparos[i]->getDano());
				disparos.eliminar(disparos[i]);
			}
		}
	}

	//Colision de los asteroides con la nave aliada
	for (int i = 0; i < asteroides.getNum(); i++)
	{
		Obstaculo* o = (Obstaculo*)asteroides[i];
		if (Interaccion::colision(*o, personaje))
		{
			personaje.setVida(personaje.getVida() - asteroides[i]->getDano());
			asteroides.eliminar(asteroides[i]);
		}
	}

	//Colision del bonus con nave personaje
	for (int i = 0; i < bonus.getNumero(); i++)
	{
		int tipo = bonus[i]->getTipo();
		if (tipo == BONUS_DISPARO_DOBLE)
		{
			BonusDisparoDoble* b = (BonusDisparoDoble*)bonus[i];
			if (Interaccion::colision(*b, personaje))
			{
				t_DisparoDoble =bonus[i]->getExtra() / t;
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
					asteroides.eliminar(asteroides[n]);
					disparos.eliminar(disparos[i]);
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
	//TECLAS PARA CAMBIAR EL PUNTO DE VISTA DURANTE EL DESARROLLO
	case'z':
	{
		x_ojo++;
		break;
	}
	case'x':
	{
		x_ojo--;
		break;
	}
	case'c':
	{
		y_ojo++;
		break;
	}
	case'v':
	{
		y_ojo--;
		break;
	}
	case'b':
	{
		z_ojo++;
		break;
	}
	case'n':
	{
		z_ojo--;
		break;
	}
	//DISPARAR
	case' ':
	{
  		if (disparos.getNumero() < MAX_DISPAROS)
		{
  			 if (personaje.getModoMisiles())
			{
				if (personaje.getNumMisiles()>0)
				{
					Disparo* d = new Misil;
					d->setPos(personaje.getPos());
					disparos.agregar(d);
					personaje.setNumMisiles(personaje.getNumMisiles() - 1);
					d = NULL;
				}
				if (personaje.getNumMisiles() <= 0)personaje.setDisparoMisiles(false);
			}
			 else if (personaje.getModoDoble())
			 {
				 Disparo* d = new DisparoDoble;
				 d->setPos(personaje.getPos().x+0.35f,personaje.getPos().y);
				 disparos.agregar(d);
				d = new DisparoDoble;
				 d->setPos(personaje.getPos().x - 0.35f, personaje.getPos().y);
				 disparos.agregar(d);
			 }
			 else
			 {
				 Disparo* d = new DisparoAliado;
				 d->setPos(personaje.getPos());
				 disparos.agregar(d);
			 }
		}
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
void Mundo::teclaEspecialUp(unsigned char key)
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

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		if (personaje.getPos().x>(caja.pared_izq.getLim1().x+0.05))
		{
			personaje.setVel(-VELOCIDAD_PERSONAJE, 0.0f);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (personaje.getPos().x < (caja.pared_dcha.getLim1().x - 0.05))
		{
			personaje.setVel(VELOCIDAD_PERSONAJE, 0.0f);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		if (personaje.getPos().y < (caja.techo.getLim1().y - 0.05))
		{
			personaje.setVel(0.0f, VELOCIDAD_PERSONAJE);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (personaje.getPos().y > (caja.suelo.getLim1().y + 0.05))
		{
			personaje.setVel(0.0f, -VELOCIDAD_PERSONAJE);
		}
		else personaje.setVel(0.0f, 0.0f);
		break;
	}	
	}
}

int Mundo::getNumEnemigos()
{
	return enemigos.getNumero();
}

bool Mundo::cargarNivel()
{
	nivel++;
	personaje.setPos(0, 0);
	enemigos.destruirContenido();
	//disparos.destruirContenido();

	if (nivel == 1) {
		NaveEnemiga* n1 = new NaveEnemiga();
		enemigos.agregar(n1);
		enemigos[0]->setPos(0.0f, 16.0f);
	}
	if (nivel == 2) {
		for (int i = 0; i < 5; i++) {
			//agregar muchos enemigos
		}
	}
	if (nivel == 3) {
			//agregar el jefe
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::aleatorio()
{
	float lim1 = caja.pared_izq.getLim1().x;
	float lim2 = caja.pared_dcha.getLim1().x;
	float x = lim1 + rand() % (int)(lim2 - lim1);
	Obstaculo* o2 = new Obstaculo();
	o2->setPos(x, caja.techo.getLim1().y);
	asteroides.agregar(o2);
}
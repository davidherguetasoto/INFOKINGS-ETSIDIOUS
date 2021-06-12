#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
Mundo::Mundo():x_ojo(0),y_ojo(0),z_ojo(0),nivel(1)
{

}
Mundo::~Mundo()
{
	enemigos.destruirContenido();
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

	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("ETSIDIOUS", -11, 21);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Infokings", 3.5, 21);
}

void Mundo::mueve()
{
	personaje.mueve(0.025f);
	asteroides.mueve(0.025f);
	enemigos.mueve(0.025f);
	Interaccion::rebote(personaje, caja);

	//personaje.setVel(0.0, 0.0);


	for (int i = asteroides.getNum(); i > 0; i--) {
		if (Interaccion::colision(*asteroides[i], caja.suelo)) {
			asteroides.eliminar(asteroides[i]);
		}
		/*for (int j = 0; j < disparos.getNumero(); j++) {
			if (Interaccion::colision(*asteroides[i], *disparos[j])) {
				disparos.eliminar(disparos[j]);
			}
		}*/
		/*for (int k = 0; k < misiles.getNumero(); k++) {
			if (Interaccion::colision(*asteroides[i], *misiles[k])) {
				misiles.eliminar(misiles[k]);
			}
		}*/
	}
}
void Mundo::tecla(unsigned char key)
{
	//TECLAS PARA CAMBIAR EL PUNTO DE VISTA DURANTE EL DESARROLLO
	switch (key)
	{
	//case'z':
	//{
	//	x++;
	//	break;
	//}
	//case'x':
	//{
	//	x--;
	//	break;
	//}
	//case'c':
	//{
	//	y++;
	//	break;
	//}
	//case'v':
	//{
	//	y--;
	//	break;
	//}
	//case'b':
	//{
	//	z++;
	//	break;
	//}
	//case'n':
	//{
	//	z--;
	//	break;
	//}
	case' ':
	{
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
		if (!Interaccion::rebote(personaje, caja.pared_izq))
		{
			personaje.setVel(-VELOCIDAD_PERSONAJE, 0.0f);
		}
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (!Interaccion::rebote(personaje, caja.pared_dcha))
		{
			personaje.setVel(VELOCIDAD_PERSONAJE, 0.0f);
		}
		break;
	}
	case GLUT_KEY_UP:
	{
		if (!Interaccion::rebote(personaje, caja.techo))
		{
			personaje.setVel(0.0f, VELOCIDAD_PERSONAJE);
		}
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (!Interaccion::rebote(personaje, caja.suelo))
		{
			personaje.setVel(0.0f, -VELOCIDAD_PERSONAJE);
		}
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
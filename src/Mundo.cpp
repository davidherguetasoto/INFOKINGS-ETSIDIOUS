#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
Mundo::Mundo():x_ojo(0),y_ojo(0),z_ojo(0)
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

	Obstaculo* o1 = new Obstaculo();
	asteroides.agregar(o1);
	
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
	disparos.dibuja();
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
	disparos.mueve(0.025f);
	Interaccion::rebote(personaje, caja);

	//personaje.setVel(0.0, 0.0);


	/*for (int i = asteroides.getNum(); i > 0; i--) {
		for (int j = 0; j < disparos.getNumero(); j++) {
			if (Interaccion::colision(*asteroides[i], *disparos[j])) {
				disparos.eliminar(disparos[j]);
			}
		}
	}*/
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
		personaje.setVel(0.0, 0.0);
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
		if(!Interaccion::rebote(personaje,caja.pared_izq))
		personaje.setVel(-15.0f, 0.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		if (!Interaccion::rebote(personaje, caja.pared_dcha))
		personaje.setVel(15.0f, 0.0f);
		break;
	}
	case GLUT_KEY_UP:
	{
		if (!Interaccion::rebote(personaje, caja.techo))
		personaje.setVel(0.0f, 15.0f);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		if (!Interaccion::rebote(personaje, caja.suelo))
		personaje.setVel(0.0f, -15.0f);
		break;
	}	
	}
}
void Mundo::teclaEspecialUp(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		personaje.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		personaje.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		personaje.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_DOWN:
		personaje.setVel(0.0f, 0.0f);
		break;
	}
}



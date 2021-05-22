#include "NavePersonaje.h"
#include "freeglut.h"
NavePersonaje::NavePersonaje()
{

}
void NavePersonaje::Dibuja()
{
	glColor3f(color.r,color.g,color.b);
	Nave::Dibuja();
}
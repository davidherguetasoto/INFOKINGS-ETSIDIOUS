/*El coordinador será la clase encargada de gestionar las llamadas
a los métodos de la clase mundo por parte de la librería
GLUT. Se encargrá así de controlar los estados que pueda tener
el juego*/

#pragma once
#include"Mundo.h"
#include"ETSIDI.h"
class CoordinadorEtsidious
{
protected:
	Mundo mundo;
	enum class Estado{INICIO, NIVEL1, NIVEL2, NIVEL3, GAMEOVER, FIN, PAUSA, RANKING};
	Estado estado;
public:
	CoordinadorEtsidious();
	virtual ~CoordinadorEtsidious();
	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve(float t);
	void Dibuja();
	void Inicializa();
};


#include "freeglut.h"
#include"CoordinadorEtsidious.h"
CoordinadorEtsidious etsidious;

//CALLBACKS LIBRERÍA FREEGLUT
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y);//cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y); //Detección de flancos negativos de las teclas
void onSpecialKeyboardDown(int key, int x, int y); //Declaración funciones teclas especiales
void OnSpecialKeyboardUp(int key, int x, int y); //Detección flanco negativo teclas especiales
void OnTime(int t); //esta funcion sera llamada cuando transcurra una temporizacion

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(750, 650);
	glutInitWindowPosition(400, 50);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("ETSIDIOUS");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutSpecialUpFunc(OnSpecialKeyboardUp); //flancos negativos de las teclas especiales
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	glutTimerFunc(2500, OnTime, 0); //Cada dos segundos y medio llama a la funcion OnTime()

	etsidious.inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	etsidious.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	etsidious.tecla(key);
	glutPostRedisplay();
}
void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{
	etsidious.teclaUp(key);
	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	etsidious.teclaEspecial(key);
}
void OnSpecialKeyboardUp(int key, int x, int y)
{
	etsidious.teclaEspecialUp(key);
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	etsidious.mueve(0.025f);
	//etsidious.aleatorio();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void OnTime(int t)
{
	etsidious.aleatorio();

	//no borrar estas lineas
	glutTimerFunc(1000, OnTime, 0);
	glutPostRedisplay();
}
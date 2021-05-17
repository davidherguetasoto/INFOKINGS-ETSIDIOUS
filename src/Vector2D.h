#pragma once
class Vector2D
{
public:
	//ATRIBUTOS
	float x;
	float y;

	//METODOS
	Vector2D():x(0),y(0){} //Constructor por defecto
	Vector2D(float xv, float yv) :x(xv), y(yv) {} // (1)constructor
	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	Vector2D unitario(); // (4) devuelve un vector unitario
	Vector2D operator - (Vector2D v); // (5) resta de vectores
	Vector2D operator + (Vector2D v); // (6) suma de vectores
	float operator *(Vector2D v); // (7) producto escalar
	Vector2D operator *(float f); // (8) producto por un escalar
	void operator=(Vector2D v); //´Sobrecarga de asignación para vector2D
	bool operator==(const Vector2D& rhs); //Igualdad entre vectores
	bool operator!=(const Vector2D& rhs);//Desigualdad entre vectores
};
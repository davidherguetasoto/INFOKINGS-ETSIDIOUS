#include "Vector2D.h"
#include<math.h>
float Vector2D::modulo()
{
	return (float)sqrt(x * x + y * y);
}
float Vector2D::argumento()
{
	return (float)atan2(y, x);
}
Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}
Vector2D Vector2D::operator+(Vector2D v)
{
	Vector2D resultado;
	resultado.x = x + v.x;
	resultado.y = y + v.y;
	return resultado;
}
Vector2D Vector2D::operator-(Vector2D v)
{
	Vector2D resultado;
	resultado.x = x - v.x;
	resultado.y = y - v.y;
	return resultado;
}
float Vector2D:: operator*(Vector2D v)
{
	return (x * v.x + y * v.y);
}
Vector2D Vector2D::operator*(float f)
{
	Vector2D res;
	res.x = x * f;
	res.y = y * f;
	return res;
}
bool Vector2D::operator==(const Vector2D& rhs) 
{ 
	if (x == rhs.x && y == rhs.y)return true;
	else return false; 
}
bool Vector2D::operator!=(const Vector2D& rhs)
{
	return !operator == (rhs);
}
void Vector2D::operator=(Vector2D v)
{
	x = v.x;
	y = v.y;
}
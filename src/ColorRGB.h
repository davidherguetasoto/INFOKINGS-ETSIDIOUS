#pragma once
#include "freeglut.h"
typedef unsigned char Byte;
struct ColorRGB
{
	Byte r, g, b;
	ColorRGB(Byte red = 255, Byte green = 255, Byte blue = 255) {
		set(red, green, blue);
	};
	void set(Byte red = 255, Byte green = 255, Byte blue = 255) {
		r = red; g = green; b = blue;
	}
	void ponColor() {
		glColor3ub(r, g, b);
	};
};
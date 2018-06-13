#pragma once
#include <stdlib.h>
using namespace System::Drawing;
class Personaje
{
protected:
	int x, y, dx=3, dy=3;
	float t;
	int ancho, alto, indiceX, indiceY;
	bool danado;
	int vida=3;
public:
	int getVidaP() { return vida; }
	void VMenos() { vida = vida - 1; }
	Personaje();
	~Personaje();
	void dibujar(BufferedGraphics ^buffer, Bitmap ^bmp);
	//void MoverY(BufferedGraphics ^buffer, Bitmap ^bmp,int a);
	//void MoverX(BufferedGraphics ^buffer, Bitmap ^bmp,int a);
	Personaje(int px, int py);
	void setX(int a) { x = a; };
	int getX() { return x; };
	void setY(int a) { y = a; };
	int getY() { return y; };
	bool getDanado() { return danado; }
	int getAncho() { return ancho * 0.5; }
	int getAlto() { return alto * 0.5; }
	void Menos();
};



Personaje::Personaje()
{
	x = 10;
	y = 10;
}


Personaje::~Personaje()
{
}


inline void Personaje::dibujar(BufferedGraphics ^ buffer, Bitmap ^ bmp)
{
	ancho = bmp->Width;
	alto = bmp->Height;
	Rectangle area = Rectangle(0, 0, ancho, alto);
	Rectangle aum = Rectangle(x, y, ancho*0.5, alto*0.5);
	//Rectangle area = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
	//Rectangle aum = Rectangle(x, y, ancho*0.5, alto*0.5);
	buffer->Graphics->DrawImage(bmp, aum, area, GraphicsUnit::Pixel);
}

//inline void Personaje::MoverY(BufferedGraphics ^ buffer, Bitmap ^ bmp,int a)
//{
//	if (y + alto + a*dy < 600 && y + a*dy >= 0)
//		y += a*dy;
//	dibujar(buffer, bmp);
//}
//
//
//inline void Personaje::MoverX(BufferedGraphics ^ buffer, Bitmap ^ bmp,int a)
//{
//	if (x + ancho + a*dx < 800 && x + a*dx >= 0)//envez de 800 un fin del form
//		x += a*dx;
//	dibujar(buffer, bmp);
//}

inline Personaje::Personaje(int px, int py)
{
	x = px;
	y = py;
	vida = 3;
}

inline void Personaje::Menos()
{
}

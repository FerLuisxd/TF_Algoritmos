#pragma once
#include <stdlib.h>
using namespace System::Drawing;
class CPelota
{
private:
	int x, y, Width, Height, dx, dy;
	bool ded;
	int vida;
public:
	int getDx() { return dx; }
	int getDy() { return dy; }
	void setVida(int i) { vida = i; }
	void recibeD() { vida = vida - 1; }
	int getVida() { return vida; }
	CPelota();
	CPelota(int a, int b, int wi, int he, int dx, int dy) {//se le peude aumentar 3 parametros de rgb
		x = a;
		y = b;
		Width = wi;
		Height = he;
		this->dx = dx;
		this->dy = dy;
	}
	~CPelota();
	//bool select(int px, int py) {
	//	return px > x && px < x + Width && py > y && py < y + Height;
	//};
	bool getDed() { return ded; }
	void MoverP(Graphics ^g, int ancho, int largo) {
		if (x + dx < 0 || x + Width + dx > ancho) {
			dx = -1;
		}
		if (y + dy < 0 || y + Height + dy> largo) {
			dy = -1;
		}
		x += dx;
		y += dy;
		g->FillEllipse(gcnew SolidBrush(Color::WhiteSmoke), x, y, Width, Height);
	}
	void dibujarEne2(BufferedGraphics ^ buffer, Bitmap ^ bmp)
	{
		Width = bmp->Width;
		Height = bmp->Height;
		Rectangle area = Rectangle(0, 0, Width, Height);
		Rectangle aum = Rectangle(x, y, Width, Height);
		//Rectangle area = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		//Rectangle aum = Rectangle(x, y, ancho*0.5, alto*0.5);
		buffer->Graphics->DrawImage(bmp, aum, area, GraphicsUnit::Pixel);
	}
	void moverEne2(BufferedGraphics ^ buffer, Bitmap ^ bmp, int px, int py,int vel)//by hillary
	{
		//if (this->y + Height + vel * dy < 600 && this->y + vel* dy >= 0)
		//	y += a * dy;
		if (x < px) dx = vel;
		if (x > px) dx = -vel;
		if (y < py) dy = vel;
		if (y > py) dy = -vel;

		x = x + dx;
		y = y + dy;
		dibujarEne2(buffer, bmp);
	}


	
	void MoverEne(BufferedGraphics^buffer, int ancho, int largo) {
		if (x + dx < 0 || x + Width + dx > ancho) {
			dx *= -1;
			//ded = true;
		}
		if (y + dy < 0 || y + Height + dy> largo) {//fixear cuando y es menor a 0
			dy *= -1;
			//ded = true;
		}
		x += dx;
		y += dy;
		//buffer->Graphics->DrawEllipse(gcnew Pen(Color::White), x, y, Width, Height);
		buffer->Graphics->FillEllipse(Brushes::Red, x, y, Width, Height);
	}
	void MoverPe(BufferedGraphics^buffer, int ancho, int largo) {
		if (x + dx < 0 || x + Width + dx > ancho) {
			//dx *= -1;
			ded = true;
		}
		if (y + dy < 0 || y + Height + dy> largo) {//fixear cuando y es menor a 0
			//dy *= -1;
			ded = true;
		}
		x += dx;
		y += dy;
		//buffer->Graphics->DrawEllipse(gcnew Pen(Color::White), x, y, Width, Height);
		buffer->Graphics->FillEllipse(Brushes::White, x, y, Width, Height);
	}
	void setX(int a) { x = a; };
	int getX() { return x; };
	void setY(int a) { y = a; };
	int getY() { return y; };
	void setDx(int a) {		dx = a;	}
	void setDy(int a) { dy = a; }
	int getAncho() { return Width; }
	int getAlto() { return Height; }
};



CPelota::CPelota()
{
}


CPelota::~CPelota()
{
}



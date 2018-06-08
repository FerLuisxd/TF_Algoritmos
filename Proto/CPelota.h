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
	bool select(int px, int py) {
		return px > x && px < x + Width && py > y && py < y + Height;
	};
	bool getDed() { return ded; }
	void Dibujar(Graphics ^ g);
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
	void Mover(int ancho, int largo);
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

inline void CPelota::Dibujar(Graphics ^ g)
{
	g->FillEllipse(gcnew SolidBrush(Color::WhiteSmoke), x, y, Width, Height);
}

inline void CPelota::Mover(int ancho, int largo)
{
	if (x + dx < 0 || x + Width + dx > ancho) {
		dx = -1;
	}
	if (y + dy < 0 || y + Height + dy> largo) {
		dy = -1;
	}
	x += dx;
	y += dy;
}

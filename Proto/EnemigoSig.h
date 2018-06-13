#pragma once
#include "CPelota.h"

class EnemigoSig
{
private:
	CPelota **vec;
	int n = 0;
	int vel = 1;//velocidad de los enemigos
	int xi = 10;
	//int a = 2;
	//int c = 7;
	//int m = 600;
public:
	int rng() {//random
		xi = (2 * xi + 7) % 400;
		return xi;
	}
	int getN() { return n; }
	CPelota * getPelota(int i) { return vec[i]; }
	void Dano(int a) {
		if (a != -1) {
			vec[a]->recibeD();
			if (vec[a]->getVida() <= 0) {
				//Divir(vec[a]->getX(), vec[a]->getY(), vec[a]->getVida(), a);
				EliminarEnemigo(a);
			}
			
		}

	}
	void EliminarEnemigo(int a) {
		if (a >= 0) {
			CPelota** aux = new CPelota*[n - 1];

			for (int i = 0; i < a; i++)
			{
				aux[i] = vec[i];
			}
			for (int i = a; i < n - 1; i++)
			{
				aux[i] = vec[i + 1];
			}
			delete vec;
			vec = aux;
			n = n - 1;
		}

	}
	EnemigoSig();
	EnemigoSig(int cant) {
		vec = new CPelota*[n];

		for (size_t i = 0; i < cant; i++)
		{
			AgregarEnemigo(rng(), rng());
		}
	}
	void MoverE(BufferedGraphics^buffer,Bitmap ^ ene2, int AnchoF, int LargoF) {
		for (int i = 0; i < n; i++)
		{
			vec[i]->moverEne2(buffer, ene2,AnchoF, LargoF,vel);
		}
	}
	void AgregarEnemigo(int x, int y) {
		CPelota * *aux = new CPelota *[n + 1];
		for (size_t i = 0; i < n; i++)
		{
			aux[i] = vec[i];
		}
		aux[n] = new CPelota(x, y, 50, 50, vel, vel);
		delete vec;
		vec = aux;
		vec[n]->setVida(30);
		n = n + 1;
	}
	~EnemigoSig();

};
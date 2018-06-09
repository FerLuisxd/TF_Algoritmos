#pragma once

#include "CPelota.h"

class EnemigoReb
{
	CPelota **vec;
	int n=0;
	int vel = 3;//velocidad de pelotas
	int xi = 5;
	//int a = 2;
	//int c = 7;
	//int m = 600;
public:
	int rng() {//random
		xi = (2*xi+ 7) % 600;
		return xi;
	}

	CPelota * getPelota(int i) { return vec[i]; }
	int getN() { return n; }
	EnemigoReb(int cant) {
		//n = cant;
		vec = new CPelota*[n];
		
		for (size_t i = 0; i < cant; i++)
		{
			AgregarPelota(rng(),rng() );
		}

	}
	EnemigoReb();
	void AgregarPelota(int AnchoF, int LargoF) {
			CPelota * *aux = new CPelota *[n + 1];
			for (size_t i = 0; i < n; i++)
			{
				aux[i] = vec[i];
			}
			aux[n] = new CPelota(AnchoF, LargoF, 50, 50, vel, vel);
			delete vec;
			vec = aux;
			vec[n]->setVida(3);
			n = n + 1;
			
	
	}
	void Divir(int AnchoF, int LargoF, int lv,int a) {
		if (lv == 2) {
			CPelota * *aux = new CPelota *[n + 2];
			for (size_t i = 0; i < n; i++)
			{
				aux[i] = vec[i];
			}
			aux[n] = new CPelota(AnchoF, LargoF, 30, 30, vec[a]->getDx() *1.2, vec[a]->getDy()*-1.2);
			aux[n + 1] = new CPelota(AnchoF, LargoF, 30, 30, vec[a]->getDx() *-1.2, vec[a]->getDy()*1.2);
			delete vec;
			vec = aux;
			vec[n]->setVida(2);
			vec[n + 1]->setVida(2);
			n = n + 2;

		}
		if (lv == 1) {
			CPelota * *aux = new CPelota *[n + 2];
			for (size_t i = 0; i < n; i++)
			{
				aux[i] = vec[i];
			}
			aux[n] = new CPelota(AnchoF, LargoF, 20, 20, vec[a]->getDx() *1.7, vec[a]->getDy()*-1.7);
			aux[n + 1] = new CPelota(AnchoF, LargoF, 20, 20, vec[a]->getDx() *-1.7, vec[a]->getDy()*1.7);
			delete vec;
			vec = aux;
			vec[n]->setVida(1);
			vec[n + 1]->setVida(1);
			n = n + 2;

		}
	}
	void Dano(int a) {
		if (a != -1) {
			vec[a]->recibeD();
			if (vec[a]->getVida() > 0) {
				Divir(vec[a]->getX(), vec[a]->getY(), vec[a]->getVida(), a);
			}
			EliminarPelota(a);
		}

	}
	void MoverP(BufferedGraphics^buffer, int AnchoF, int LargoF) {
		for (int i = 0; i < n; i++)
		{
			vec[i]->MoverEne(buffer, AnchoF, LargoF);
		}
	}
	

	void EliminarPelota() {
		int it = -1;
		for (int i = 0; i < n; i++)
		{
			if (vec[i]->getDed() == true)
				it = i;
		}
		if (it != -1) {
			CPelota** aux = new CPelota*[n - 1];

			for (int i = 0; i < it; i++)
			{
				aux[i] = vec[i];
			}
			for (int i = it; i < n - 1; i++)
			{
				aux[i] = vec[i + 1];
			}
			delete vec;
			vec = aux;
			n = n - 1;
		}

	}
	void EliminarPelota(int a) {
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
};



EnemigoReb::EnemigoReb()
{
	n = 0;
	vec = new CPelota*[n];
}

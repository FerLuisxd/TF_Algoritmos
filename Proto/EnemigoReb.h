#pragma once
#include "CPelota.h"	
class EnemigoReb
{
	CPelota * *vec;
	int n;
	int vel = 4;//velocidad de pelotas
public:
	CPelota * getPelota(int i) { return vec[i]; }
	int getN() { return n; }
	EnemigoReb(int cant) {
		n = cant;
		vec = new CPelota*[n];

	}
	EnemigoReb();
	void AgregarPelota(int AnchoF, int LargoF) {
		CPelota * *aux = new CPelota *[n + 1];
		for (size_t i = 0; i < n; i++)
		{
			aux[i] = vec[i];
		}
		aux[n] = new CPelota(AnchoF, LargoF, 30, 30, vel, vel);
		delete vec;
		vec = aux;
		n = n + 1;
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

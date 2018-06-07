#pragma once
#include "CPelota.h"
class CVecPelota
{
private:
	CPelota * *vec;
	int n;
	int vel = 7;//velocidad de pelotas
public:
	CPelota * getPelota(int i) { return vec[i]; }
	int getN() { return n; }
	CVecPelota() {
		n = 0;
		vec = new CPelota*[n];
	}
	~CVecPelota();
	void AgregarPelota2(int AnchoF, int LargoF, int a) {

		CPelota * *aux = new CPelota *[n + 1];
		for (size_t i = 0; i < n; i++)
		{
			aux[i] = vec[i];
		}
		if (a == 0) {//arriba
			aux[n] = new CPelota(AnchoF, LargoF, 15, 15, 0, vel);
		}
		if (a == 1) {//derecha
			aux[n] = new CPelota(AnchoF, LargoF, 15, 15, vel, 0);
		}
		if (a == 2) {//abajo
			aux[n] = new CPelota(AnchoF, LargoF, 15, 15, 0, -vel);
		}
		if (a == 3) {//izq
			aux[n] = new CPelota(AnchoF, LargoF, 15, 15, -vel, 0);
		}
		
		delete vec;
		vec = aux;
		n = n + 1;
	}
	void AgregarPelota(int AnchoF, int LargoF) {//no se usa
		CPelota * *aux = new CPelota *[n + 1];
		for (size_t i = 0; i < n; i++)
		{
			aux[i] = vec[i];
		}
		aux[n] = new CPelota(AnchoF, LargoF, 10, 10, 10, 10);
		delete vec;
		vec = aux;
		n = n + 1;
	}
	void DibujarPelotas(Graphics ^g) {
		for (int i = 0; i < n; i++)
		{
			vec[i]->Dibujar(g);
		}
	}
	void MoverP(BufferedGraphics^buffer, int AnchoF, int LargoF) {
		for (int i = 0; i < n; i++)
		{
			vec[i]->MoverPe(buffer,AnchoF, LargoF);
		}
	}
	void MoverPelotas(int AnchoF, int LargoF) {
		for (int i = 0; i < n; i++)
		{
			vec[i]->Mover(AnchoF, LargoF);
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
			CPelota** aux = new CPelota*[n-1];

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
};




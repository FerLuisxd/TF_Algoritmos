#pragma once
#include "CPelota.h"
class CVecPelota
{
private:
	CPelota * *vec;
	int n;
public:
	CVecPelota() {
		n = 0;
		vec = new CPelota*[n];
	}
	~CVecPelota();
	void AgregarPelota(int AnchoF, int LargoF) {
		CPelota * *aux = new CPelota *[n + 1];
		for (size_t i = 0; i < n; i++)
		{
			aux[i] = vec[i];
		}
		aux[n] = new CPelota(AnchoF, LargoF, 10, 10, 2, 2);
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
	void EliminarPelota(int Px, int Py) {
		int it = -1;
		for (int i = 0; i < n; i++)
		{
			//if(vec[i]->)
			it = i;

		}
		CPelota** aux = new CPelota *[n - 1];
	}
};




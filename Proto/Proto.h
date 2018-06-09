#pragma once
#include "Personaje.h"
#include "CVecPelota.h"
#include "EnemigoReb.h"
namespace Proto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//jugador
	bool mov[8] = { false };
	int vel = 4;
	bool ata = false;
	int contA = 0;
	bool ele = false;
	int it = -1;
	int delay = 0;
	//jugador
	/// <summary>
	/// Resumen de Proto
	/// </summary>
	public ref class Proto : public System::Windows::Forms::Form
	{
	private:
		Personaje * pj = new Personaje();
		CVecPelota* vectorP = new CVecPelota();
		Bitmap ^ personaje = gcnew Bitmap("Link.png");
		EnemigoReb * ene; //= new EnemigoReb();
		System::Drawing::Font ^fuente = gcnew System::Drawing::Font("Comics Sans MS", 18, FontStyle::Bold);
		System::Drawing::SolidBrush ^solid = gcnew System::Drawing::SolidBrush(Color::Red);
	public:
		Proto(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	public: System::Windows::Forms::Timer^  timer;
	private:
	private: System::ComponentModel::IContainer^  components;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Proto()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 16;
			this->timer->Tick += gcnew System::EventHandler(this, &Proto::timer_tick);
			// 
			// Proto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 457);
			this->Name = L"Proto";
			this->Text = L"Proto";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Proto::Proto_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Proto::Proto_KeyUp);
			this->ResumeLayout(false);
			ene = new EnemigoReb(5);

		}
#pragma endregion
	private:template<class T> bool IntersectByEne(T * a, T * b)//rectangle
	{
		System::Drawing::Rectangle pig;
		pig.X = a->getX();
		pig.Y = a->getY();
		pig.Width = a->getAncho();
		pig.Height = a->getAlto();
		System::Drawing::Rectangle pajaro;
		pajaro.X = b->getX();
		pajaro.Y = b->getY();
		pajaro.Width = b->getAncho();
		pajaro.Height = b->getAlto();


		return pajaro.IntersectsWith(pig);
	}
	private:template<class T> bool IntersectByEne(Personaje * a, T * b)//rectangle
	{
		System::Drawing::Rectangle pig;
		pig.X = a->getX();
		pig.Y = a->getY();
		pig.Width = a->getAncho();
		pig.Height = a->getAlto();
		System::Drawing::Rectangle pajaro;
		pajaro.X = b->getX();
		pajaro.Y = b->getY();
		pajaro.Width = b->getAncho();
		pajaro.Height = b->getAlto();


		return pajaro.IntersectsWith(pig);
	}
	private: void Verificar() {
		if (delay <= 100) {
			delay++;
		}
	
		//balas y enemigosrebotantes
		if (ene->getN() > 0)
		{
			for (size_t i = 0; i < vectorP->getN(); i++)
			{
				it = -1;
				if (vectorP->getPelota(i) != nullptr) {
					CPelota * a = vectorP->getPelota(i);
					for (int i = 0; i < ene->getN(); i++) {
						if (ene->getPelota(i) != nullptr) {
							CPelota * b = ene->getPelota(i);
							if (IntersectByEne(a, b))
							{
								it = i;
								break;
							}
						}
					}
					ene->Dano(it);
				}
			}
			for (int i = 0; i < ene->getN(); i++) {
				if (ene->getPelota(i) != nullptr) {
					CPelota * b = ene->getPelota(i);
					if (IntersectByEne(pj, b)) {
						if (delay >=100) {
							pj->VMenos();
							delay = 0;

						}
					}
				}
			}

			
		}
		//jugador y enemigos
	}
	private: System::Void timer_tick(System::Object^  sender, System::EventArgs^  e) {
		_DoMovement();	
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		pj->dibujar(buffer, personaje);
		vectorP->MoverP(buffer, this->ClientRectangle.Width, this->ClientRectangle.Height);
		ene->MoverP(buffer, this->ClientRectangle.Width, this->ClientRectangle.Height);
		//UI
		//buffer->Graphics->DrawString("Vida: ", fuente, solid, 10, 10);
		buffer->Graphics->DrawString(pj->getVidaP().ToString(), fuente, solid, delay, 10);
		//
		Verificar();
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: void _DoMovement() 
	{
		vectorP->EliminarPelota();
		if (mov[0] == true)pj->setY(pj->getY() + vel);
		if (mov[1] == true)pj->setX(pj->getX() - vel);
		if (mov[2] == true)pj->setX(pj->getX() + vel);
		if (mov[3] == true)pj->setY(pj->getY() - vel);
		if (mov[4]) {
			contA++;			
			mov[5] = false; mov[6] = false; mov[7] = false;
		}
		if (mov[5]) {
			contA++;
			mov[4] = false; mov[6] = false; mov[7] = false;
		}
		if (mov[6]) {
			contA++;
			mov[5] = false; mov[4] = false; mov[7] = false;
		}
		if (mov[7]) {
			contA++;
			mov[5] = false; mov[6] = false; mov[4] = false;
		}
		if (contA > 25) {
			ele = true;
			if (mov[4]) {
				vectorP->AgregarPelota2(pj->getX() + pj->getAncho()/2, pj->getY() + pj->getAlto()/4, 0);
			}
			if (mov[5]) {
				vectorP->AgregarPelota2(pj->getX() + pj->getAncho() / 2, pj->getY() + pj->getAlto() / 4, 3);
			}
			if (mov[6]) {
				vectorP->AgregarPelota2(pj->getX() + pj->getAncho() / 2, pj->getY() + pj->getAlto() / 4, 1);
			}
			if (mov[7]) {
				vectorP->AgregarPelota2(pj->getX() + pj->getAncho() / 2, pj->getY() + pj->getAlto() / 4, 2);

			}
			contA = 0;
		}
		
	}
	private: System::Void Proto_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::T:
		{
			ene->AgregarPelota(100, 100);
			break;
		}
		case Keys::S://abajo
		{
			mov[0] = true;
			break;
		}
		case Keys::A://izq
		{
			mov[1] = true;
			break;
		}
		case Keys::D://derecha
		{
			mov[2] = true;
			break;
		}
		case Keys::W://arriba
		{
			mov[3] = true;
			break;
		}
		case Keys::Down://abajo
		{
			mov[4] = true;
			break;
		}
		case Keys::Left://izq
		{
			mov[5] = true;
			break;
		}
		case Keys::Right://derecha
		{
			mov[6] = true;
			break;
		}
		case Keys::Up://arriba
		{
			mov[7] = true;
			break;
		}
		}


	}
	private: System::Void Proto_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::S://abajo
		{
			mov[0] = false;
			break;
		}
		case Keys::A://izq
		{
			mov[1] = false;
			break;
		}
		case Keys::D://derecha
		{
			mov[2] = false;
			break;
		}
		case Keys::W://arriba
		{
			mov[3] = false;
			break;
		}
		case Keys::Down://abajo
		{
			mov[4] = false;
			break;
		}
		case Keys::Left://izq
		{
			mov[5] = false;
			break;
		}
		case Keys::Right://derecha
		{
			mov[6] = false;
			break;
		}
		case Keys::Up://arriba
		{
			mov[7] = false;
			break;
		}
		}

	};


};
}

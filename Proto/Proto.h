#pragma once
#include "Personaje.h"
#include "CVecPelota.h"
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
			this->timer->Interval = 33;
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

		}
#pragma endregion
	private: System::Void timer_tick(System::Object^  sender, System::EventArgs^  e) {
		_DoMovement();	
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		pj->dibujar(buffer, personaje);
		vectorP->MoverP(buffer, this->ClientRectangle.Width, this->ClientRectangle.Height);


		//_DoMovement();
		//pj->MoverX(buffer, personaje, 1);
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: void _DoMovement() 
	{
		if (mov[0] == true)pj->setY(pj->getY() + vel);
		if (mov[1] == true)pj->setX(pj->getX() - vel);
		if (mov[2] == true)pj->setX(pj->getX() + vel);
		if (mov[3] == true)pj->setY(pj->getY() - vel);
		
	}
	private: System::Void Proto_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
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
			vectorP->AgregarPelota(pj->getX() + 10, pj->getY() + 10);
			break;
		}
		case Keys::Left://izq
		{
			vectorP->AgregarPelota(pj->getX() + 10, pj->getY() + 10);
			break;
		}
		case Keys::Right://derecha
		{
			vectorP->AgregarPelota(pj->getX() + 10, pj->getY() + 10);
			break;
		}
		case Keys::Up://arriba
		{
			vectorP->AgregarPelota(pj->getX() + 10, pj->getY() + 10);
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

			break;
		}
		case Keys::Left://izq
		{

			break;
		}
		case Keys::Right://derecha
		{

			break;
		}
		case Keys::Up://arriba
		{

			break;
		}
		}

	};

};
}

#pragma once

#include "Controlador2.h"
#include "Fondo.h"
#include "YouLose.h"
#include "YouWin.h"
#include "FinalSecret.h"

namespace JuegoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Nivel2
	/// </summary>
	public ref class Nivel2 : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		//Bitmap
		Bitmap^ bmTyron;
		Bitmap^ bmPobreza;
		Bitmap^ bmSubdito;
		Bitmap^ bmPoblador;
		Bitmap^ bmFondo2;
		//Objetos
		Fondo* fondo2;
		//Musica
		SoundPlayer^ musiclvl2;
		SoundPlayer^ musicWin2;
		SoundPlayer^ musicLose2;
		SoundPlayer^ musicFS;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ lblVida;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblPoblRescue;







	private: System::Windows::Forms::Timer^ timerSpawn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblPoblMurder;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Timer^ timer2;




		   Controlador2* controlador2;
	public:
		Nivel2(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			//Bitmap
			bmTyron = gcnew Bitmap("Tyron.png");
			bmPobreza = gcnew Bitmap("Pobreza1.0.png");
			bmFondo2 = gcnew Bitmap("Lvl2.png");
			bmSubdito = gcnew Bitmap("Subdito.png");
			bmPoblador = gcnew Bitmap("Poblador.png");
			//Objetos
			fondo2 = new Fondo(bmFondo2);
			controlador2 = new Controlador2(buffer->Graphics, bmTyron, bmSubdito, bmPoblador, bmPobreza);
			//Musica
			musiclvl2 = gcnew SoundPlayer("MusicLvl2.wav");
			musicWin2 = gcnew SoundPlayer("YouWin2.wav");
			musicLose2 = gcnew SoundPlayer("YouLose2.wav");
			musicFS = gcnew SoundPlayer("FinalSecret.wav");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblVida = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPoblRescue = (gcnew System::Windows::Forms::Label());
			this->timerSpawn = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblPoblMurder = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1191, 722);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(29, 725);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Vida :";
			// 
			// lblVida
			// 
			this->lblVida->AutoSize = true;
			this->lblVida->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVida->Location = System::Drawing::Point(85, 725);
			this->lblVida->Name = L"lblVida";
			this->lblVida->Size = System::Drawing::Size(27, 19);
			this->lblVida->TabIndex = 2;
			this->lblVida->Text = L"Hp";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(223, 728);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 19);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Pobladores Salvados :";
			// 
			// lblPoblRescue
			// 
			this->lblPoblRescue->AutoSize = true;
			this->lblPoblRescue->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoblRescue->Location = System::Drawing::Point(413, 728);
			this->lblPoblRescue->Name = L"lblPoblRescue";
			this->lblPoblRescue->Size = System::Drawing::Size(52, 19);
			this->lblPoblRescue->TabIndex = 4;
			this->lblPoblRescue->Text = L"Rescue";
			// 
			// timerSpawn
			// 
			this->timerSpawn->Enabled = true;
			this->timerSpawn->Interval = 5000;
			this->timerSpawn->Tick += gcnew System::EventHandler(this, &Nivel2::timer2_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(521, 729);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(170, 19);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Pobladores Eliminados :";
			// 
			// lblPoblMurder
			// 
			this->lblPoblMurder->AutoSize = true;
			this->lblPoblMurder->Location = System::Drawing::Point(721, 730);
			this->lblPoblMurder->Name = L"lblPoblMurder";
			this->lblPoblMurder->Size = System::Drawing::Size(65, 16);
			this->lblPoblMurder->TabIndex = 6;
			this->lblPoblMurder->Text = L"Murdered";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(884, 727);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 19);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Tiempo :";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(971, 728);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(38, 16);
			this->lblTime->TabIndex = 8;
			this->lblTime->Text = L"Time";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Nivel2::timer2_Tick_1);
			// 
			// Nivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1188, 750);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblPoblMurder);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblPoblRescue);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblVida);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Nivel2";
			this->Text = L"Nivel2";
			this->Load += gcnew System::EventHandler(this, &Nivel2::Nivel2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Nivel2_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Colision
		controlador2->Colision1();
		controlador2->Colision3();
		controlador2->Colision4();
		controlador2->Colision5();
		//Move
		fondo2->Mover(buffer->Graphics);
		controlador2->MoverTodoLvl2(buffer->Graphics);
		//Draw
		lblVida->Text = Convert::ToString(controlador2->getTyron()->getHp());
		lblPoblRescue->Text = Convert::ToString(controlador2->getTyron()->getContPoblSal());
		lblPoblMurder->Text = Convert::ToString(controlador2->getPobreza()->getContMurder());
		lblTime->Text = Convert::ToString(controlador2->getTyron()->getGameTime());
		fondo2->Dibujar(buffer->Graphics, bmFondo2);
		controlador2->DibujarTodoLvl2(buffer->Graphics, bmTyron, bmSubdito, bmPoblador, bmPobreza);
		//Render
		buffer->Render(g);
		//Win&&Lose
		if (controlador2->getTyron()->getHp() == 0) {
			timer1->Enabled = false;
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicLose2->PlayLooping();
			YouLose^ formLose = gcnew YouLose();
			formLose->ShowDialog();
			Close();
		}
		else if (controlador2->getTyron()->getContPoblSal() == 12) {
			timer1->Enabled = false;
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicWin2->PlayLooping();
			YouWin^ formWin = gcnew YouWin();
			formWin->ShowDialog();//Hasta que se cierre
			Close();//Que se cierre el programa
		}
		else if (controlador2->getPobreza()->getContMurder() == 6) {
			timer1->Enabled = false;
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicFS->PlayLooping();
			FinalSecret^ formFinalSecret = gcnew FinalSecret();
			formFinalSecret->ShowDialog();
			Close();
		}
		else if (controlador2->getTyron()->getGameTime() == 0) {
			timer1->Enabled = false;
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicLose2->PlayLooping();
			YouLose^ formLose = gcnew YouLose();
			formLose->ShowDialog();
			Close();
		}
	}
	private: System::Void Nivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			controlador2->getTyron()->Mover(buffer->Graphics, 'A'); break;
		case Keys::D:
			controlador2->getTyron()->Mover(buffer->Graphics, 'D'); break;
		case Keys::W:
			controlador2->getTyron()->Mover(buffer->Graphics, 'W'); break;
		case Keys::S:
			controlador2->getTyron()->Mover(buffer->Graphics, 'S'); break;
		case Keys::T:
			controlador2->Colision2();

		}
	}
	private: System::Void Nivel2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controlador2->getTyron()->Stop();
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		controlador2->AgregarPoblador(bmPoblador);
		controlador2->AgregarPoblador(bmPoblador);
		controlador2->AgregarSubdito(bmSubdito);

	}
	private: System::Void Nivel2_Load(System::Object^ sender, System::EventArgs^ e) {
		musiclvl2->Play();
	}
	private: System::Void timer2_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		controlador2->getTyron()->ReducirGameTime();
	}
};
}


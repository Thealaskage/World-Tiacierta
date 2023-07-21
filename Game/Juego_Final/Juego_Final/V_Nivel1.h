#pragma once

#pragma once
#include "Fondo.h"
#include "Controlador.h"
#include "YouWin.h"
#include "YouLose.h"
//Lvl1
namespace JuegoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class V_Nivel1 : public System::Windows::Forms::Form
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
		Bitmap^ bmFondo1;
		Bitmap^ bmObstaculo;
		//Musica
		SoundPlayer^ musiclvl1;
		SoundPlayer^ musicWin;
		SoundPlayer^ musicLose;

	private: System::Windows::Forms::Panel^ panel1;
		   //Objetos
		   Fondo* fondo1;
		   Controlador* controlador;
	private: System::Windows::Forms::Label^ lblVida;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timerSpawn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lbltime;
	private: System::Windows::Forms::Timer^ timer2;

	private: System::Windows::Forms::Label^ lblPoblRescue;
	public:
		V_Nivel1(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			//Bitmap
			bmTyron = gcnew Bitmap("Tyron.png");
			bmPobreza = gcnew Bitmap("Pobreza.png");
			bmFondo1 = gcnew Bitmap("Lvl1.png");
			bmSubdito = gcnew Bitmap("Subdito.png");
			bmPoblador = gcnew Bitmap("Poblador.png");
			bmObstaculo = gcnew Bitmap("imagenL.png");
			//Objetos
			fondo1 = new Fondo(bmFondo1);
			controlador = new Controlador(buffer->Graphics, bmTyron, bmSubdito, bmPoblador, bmObstaculo);
			//Musica
			musiclvl1 = gcnew SoundPlayer("MusicLvl1.wav");
			musicWin = gcnew SoundPlayer("YouWin.wav");
			musicLose = gcnew SoundPlayer("YouLose.wav");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~V_Nivel1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblVida = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerSpawn = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPoblRescue = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbltime = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &V_Nivel1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-1, -1);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(893, 563);
			this->panel1->TabIndex = 0;
			// 
			// lblVida
			// 
			this->lblVida->AutoSize = true;
			this->lblVida->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVida->Location = System::Drawing::Point(72, 585);
			this->lblVida->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblVida->Name = L"lblVida";
			this->lblVida->Size = System::Drawing::Size(31, 20);
			this->lblVida->TabIndex = 1;
			this->lblVida->Text = L"Hp";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Stencil", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(11, 586);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas : ";
			// 
			// timerSpawn
			// 
			this->timerSpawn->Enabled = true;
			this->timerSpawn->Interval = 10000;
			this->timerSpawn->Tick += gcnew System::EventHandler(this, &V_Nivel1::timerSpawn_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Stencil", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(441, 586);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(198, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Pobladores Salvados :";
			// 
			// lblPoblRescue
			// 
			this->lblPoblRescue->AutoSize = true;
			this->lblPoblRescue->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoblRescue->Location = System::Drawing::Point(643, 585);
			this->lblPoblRescue->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPoblRescue->Name = L"lblPoblRescue";
			this->lblPoblRescue->Size = System::Drawing::Size(61, 20);
			this->lblPoblRescue->TabIndex = 3;
			this->lblPoblRescue->Text = L"Rescue";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Stencil", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(214, 586);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 19);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Time :";
			// 
			// lbltime
			// 
			this->lbltime->AutoSize = true;
			this->lbltime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltime->Location = System::Drawing::Point(274, 586);
			this->lbltime->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbltime->Name = L"lbltime";
			this->lbltime->Size = System::Drawing::Size(16, 18);
			this->lbltime->TabIndex = 5;
			this->lbltime->Text = L"0";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &V_Nivel1::timer2_Tick);
			// 
			// V_Nivel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(891, 609);
			this->Controls->Add(this->lbltime);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblPoblRescue);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblVida);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"V_Nivel1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &V_Nivel1::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &V_Nivel1::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &V_Nivel1::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Erase
		/*buffer->Graphics->Clear(Color::WhiteSmoke);*/
		//Colision
		controlador->Colision1();
		controlador->Colision3();
		controlador->Colision4();
		//Move
		fondo1->Mover(buffer->Graphics);
		controlador->MoverTodoLvl1(buffer->Graphics);
		//Draw
		lblVida->Text = Convert::ToString(controlador->getTyron()->getHp());//Mostrar vidas de Tyron
		lblPoblRescue->Text = Convert::ToString(controlador->getTyron()->getContPoblSal());//Mostrar cantidad de pobladores salvados
		lbltime->Text = Convert::ToString(controlador->getTyron()->getGameTime());
		fondo1->Dibujar(buffer->Graphics, bmFondo1);
		controlador->DibujarTodoLvl1(buffer->Graphics, bmTyron, bmSubdito, bmPoblador, bmObstaculo);
		//Render
		buffer->Render(g);
		//Win&&Lose
		if (controlador->getTyron()->getHp() == 0) { //Si la vida de Tyron llega a 0
			timer1->Enabled = false;//Desactivar Timers
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicLose->PlayLooping(); //Reproducir musica
			YouLose^ formLose = gcnew YouLose();
			formLose->ShowDialog();
			Close();
		}
		else if (controlador->getTyron()->getContPoblSal() == 8) {
			timer1->Enabled = false;
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicWin->PlayLooping(); //Reproducir musica
			YouWin^ formWin = gcnew YouWin();
			formWin->ShowDialog();
			Close();
		}
		else if (controlador->getTyron()->getGameTime() == 0) {
			timer1->Enabled = false;
			timerSpawn->Enabled = false;
			timer2->Enabled = false;
			musicLose->PlayLooping();
			YouLose^ formLose = gcnew YouLose();
			formLose->ShowDialog();
			Close();
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A://Mov hacia la iz
			controlador->getTyron()->Mover(buffer->Graphics, 'A'); break;
		case Keys::D://Mov hacia la der
			controlador->getTyron()->Mover(buffer->Graphics, 'D'); break;
		case Keys::W://Mov hacia arriba
			controlador->getTyron()->Mover(buffer->Graphics, 'W'); break;
		case Keys::S://Mov hacia abajo
			controlador->getTyron()->Mover(buffer->Graphics, 'S'); break;
		case Keys::T://Tecla para rescatar aliados
			controlador->Colision2();

		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controlador->getTyron()->Stop();//Si no presionamos nada que se quede quieto Tyron
	}


	private: System::Void timerSpawn_Tick(System::Object^ sender, System::EventArgs^ e) {
		controlador->AgregarSubdito(bmSubdito);//Cada 5 segundos se agrega un subdito en una posicion random
	}



	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		musiclvl1->Play();
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		controlador->getTyron()->ReducirGameTime();
	}
	};
}
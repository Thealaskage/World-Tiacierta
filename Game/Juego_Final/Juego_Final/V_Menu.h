#pragma once
#pragma comment(lib, "Winmm.lib") // Enlaza con la biblioteca Winmm.lib
#include"V_Creditos.h"
#include"V_Instrucciones.h"
#include"V_Jugar.h"
#include <Windows.h>
#include <mmsystem.h>

namespace JuegoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de V_Menu
	/// </summary>
	public ref class V_Menu : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ musicInt;
	public:
		V_Menu(void)
		{
			InitializeComponent();
			musicInt = gcnew SoundPlayer("Introduccion.wav");
			SetSystemVolume(50); // Establecer el volumen al 50%
			//
			//TODO: agregar código de constructor aquí
			//
		}
		void SetSystemVolume(int volume)
		{
			int newVolume = volume * 65535 / 100; // Convertir el volumen (0-100) a rango de 0 a 65535
			DWORD dwVolume = newVolume;

			if (newVolume > 65535)
				dwVolume = 65535;
			else if (newVolume < 0)
				dwVolume = 0;

			// Obtener el dispositivo de audio predeterminado (master)
			UINT numDevices = waveOutGetNumDevs();
			if (numDevices == 0)
			{
				MessageBox::Show("No se encontraron dispositivos de audio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			HWAVEOUT hWaveOut;
			MMRESULT result = waveOutOpen(&hWaveOut, WAVE_MAPPER, NULL, NULL, NULL, CALLBACK_NULL);
			if (result != MMSYSERR_NOERROR)
			{
				MessageBox::Show("Error al abrir el dispositivo de audio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Obtener el volumen actual del dispositivo
			DWORD dwCurrentVolume;
			result = waveOutGetVolume(hWaveOut, &dwCurrentVolume);
			if (result != MMSYSERR_NOERROR)
			{
				MessageBox::Show("Error al obtener el volumen del dispositivo de audio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				waveOutClose(hWaveOut);
				return;
			}

			// Establecer el volumen deseado
			dwCurrentVolume = (dwCurrentVolume & 0xFFFF0000) | dwVolume;
			result = waveOutSetVolume(hWaveOut, dwCurrentVolume);
			if (result != MMSYSERR_NOERROR)
			{
				MessageBox::Show("Error al establecer el volumen del dispositivo de audio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			waveOutClose(hWaveOut);
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~V_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ b_jugar;
	private: System::Windows::Forms::Button^ b_instrucciones;
	protected:

	private: System::Windows::Forms::Button^ b_creditos;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(V_Menu::typeid));
			this->b_jugar = (gcnew System::Windows::Forms::Button());
			this->b_instrucciones = (gcnew System::Windows::Forms::Button());
			this->b_creditos = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// b_jugar
			// 
			this->b_jugar->BackColor = System::Drawing::Color::Transparent;
			this->b_jugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->b_jugar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->b_jugar->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_jugar->Location = System::Drawing::Point(79, 205);
			this->b_jugar->Name = L"b_jugar";
			this->b_jugar->Size = System::Drawing::Size(63, 30);
			this->b_jugar->TabIndex = 0;
			this->b_jugar->Text = L"JUGAR";
			this->b_jugar->UseVisualStyleBackColor = false;
			this->b_jugar->Click += gcnew System::EventHandler(this, &V_Menu::b_jugar_Click);
			// 
			// b_instrucciones
			// 
			this->b_instrucciones->BackColor = System::Drawing::Color::Transparent;
			this->b_instrucciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->b_instrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->b_instrucciones->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_instrucciones->Location = System::Drawing::Point(54, 354);
			this->b_instrucciones->Name = L"b_instrucciones";
			this->b_instrucciones->Size = System::Drawing::Size(139, 29);
			this->b_instrucciones->TabIndex = 1;
			this->b_instrucciones->Text = L"INSTRUCCIONES";
			this->b_instrucciones->UseVisualStyleBackColor = false;
			this->b_instrucciones->Click += gcnew System::EventHandler(this, &V_Menu::b_instrucciones_Click);
			// 
			// b_creditos
			// 
			this->b_creditos->BackColor = System::Drawing::Color::Transparent;
			this->b_creditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->b_creditos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->b_creditos->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_creditos->Location = System::Drawing::Point(69, 285);
			this->b_creditos->Name = L"b_creditos";
			this->b_creditos->Size = System::Drawing::Size(97, 30);
			this->b_creditos->TabIndex = 2;
			this->b_creditos->Text = L"CREDITOS";
			this->b_creditos->UseVisualStyleBackColor = false;
			this->b_creditos->Click += gcnew System::EventHandler(this, &V_Menu::b_creditos_Click);
			// 
			// V_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 461);
			this->Controls->Add(this->b_creditos);
			this->Controls->Add(this->b_instrucciones);
			this->Controls->Add(this->b_jugar);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"V_Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &V_Menu::V_Menu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void b_creditos_Click(System::Object^ sender, System::EventArgs^ e) {
		JuegoFinal::V_Creditos^ creditos = gcnew JuegoFinal::V_Creditos();
		this->Visible = false;
		creditos->ShowDialog();
		this->Visible = true;
	}
	private: System::Void b_instrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		JuegoFinal::V_Instrucciones^ instrucciones = gcnew JuegoFinal::V_Instrucciones();
		this->Visible = false;
		instrucciones->ShowDialog();
		this->Visible = true;
	}
	private: System::Void b_jugar_Click(System::Object^ sender, System::EventArgs^ e) {
		JuegoFinal::V_Jugar^ jugar = gcnew JuegoFinal::V_Jugar();
		this->Visible = false;
		jugar->ShowDialog();
		this->Visible = true;
	}
	private: System::Void V_Menu_Load(System::Object^ sender, System::EventArgs^ e) {
		musicInt->Play();
	}
	};
}

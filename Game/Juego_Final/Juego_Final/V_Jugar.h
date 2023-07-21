#pragma once
#include"Nivel2.h"
#include"V_Nivel1.h"
namespace JuegoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de V_Jugar
	/// </summary>
	public ref class V_Jugar : public System::Windows::Forms::Form
	{
	public:
		V_Jugar(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~V_Jugar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ b_nivel1;
	protected:
	private: System::Windows::Forms::Button^ b_nivel2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(V_Jugar::typeid));
			this->b_nivel1 = (gcnew System::Windows::Forms::Button());
			this->b_nivel2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// b_nivel1
			// 
			this->b_nivel1->BackColor = System::Drawing::Color::Transparent;
			this->b_nivel1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->b_nivel1->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_nivel1->ForeColor = System::Drawing::Color::Black;
			this->b_nivel1->Location = System::Drawing::Point(361, 231);
			this->b_nivel1->Name = L"b_nivel1";
			this->b_nivel1->Size = System::Drawing::Size(109, 29);
			this->b_nivel1->TabIndex = 0;
			this->b_nivel1->Text = L"NIVEL 1";
			this->b_nivel1->UseVisualStyleBackColor = false;
			this->b_nivel1->Click += gcnew System::EventHandler(this, &V_Jugar::b_nivel1_Click);
			// 
			// b_nivel2
			// 
			this->b_nivel2->BackColor = System::Drawing::Color::Transparent;
			this->b_nivel2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->b_nivel2->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_nivel2->ForeColor = System::Drawing::Color::Black;
			this->b_nivel2->Location = System::Drawing::Point(664, 240);
			this->b_nivel2->Name = L"b_nivel2";
			this->b_nivel2->Size = System::Drawing::Size(106, 30);
			this->b_nivel2->TabIndex = 1;
			this->b_nivel2->Text = L"NIVEL 2";
			this->b_nivel2->UseVisualStyleBackColor = false;
			this->b_nivel2->Click += gcnew System::EventHandler(this, &V_Jugar::b_nivel2_Click);
			// 
			// V_Jugar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 461);
			this->Controls->Add(this->b_nivel2);
			this->Controls->Add(this->b_nivel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"V_Jugar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void b_nivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		JuegoFinal::Nivel2^ nivel2 = gcnew JuegoFinal::Nivel2();
		this->Visible = false;
		nivel2->ShowDialog();
		this->Visible = true;
	}
	private: System::Void b_nivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		JuegoFinal::V_Nivel1^ nivel1 = gcnew JuegoFinal::V_Nivel1();
		this->Visible = false;
		nivel1->ShowDialog();
		this->Visible = true;
	}
	};
}

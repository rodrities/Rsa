#pragma once
#include "Rsa.h"
#include <sstream>

namespace RSA {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	private:
		Rsa* rsa = new Rsa();
		List<unsigned long long> PrimeArray;
		unsigned long long d;
		unsigned long long e;
		unsigned long long n;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	public:
		MyForm(void) {
			InitializeComponent();
			GeneratePrimesNumber();
			FullCombobox();
			this->EncriptButton->Enabled = true;

		//	generateKeys();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm() {
			if (components) 
				delete components;	
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^ EncriptButton;

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->EncriptButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 45, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(194, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(551, 87);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Encriptación RSA";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(539, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Números Primos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(602, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"p:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(765, 192);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"q:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(34, 117);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Texto:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(22, 428);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(182, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Clave pública(n, e):\r\n";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(242, 428);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(184, 25);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Clave privada(n, d):\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label9->Location = System::Drawing::Point(34, 469);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 20);
			this->label9->TabIndex = 8;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label10->Location = System::Drawing::Point(242, 469);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 20);
			this->label10->TabIndex = 9;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(450, 378);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(125, 25);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Encriptación:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(27, 151);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(421, 209);
			this->textBox1->TabIndex = 11;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(455, 406);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(472, 254);
			this->textBox2->TabIndex = 12;
			// 
			// EncriptButton
			// 
			this->EncriptButton->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->EncriptButton->Location = System::Drawing::Point(129, 111);
			this->EncriptButton->Name = L"EncriptButton";
			this->EncriptButton->Size = System::Drawing::Size(105, 31);
			this->EncriptButton->TabIndex = 13;
			this->EncriptButton->Text = L"Encriptar";
			this->EncriptButton->UseVisualStyleBackColor = true;
			this->EncriptButton->Click += gcnew System::EventHandler(this, &MyForm::Encript_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(717, 212);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 14;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"53437" });
			this->comboBox2->Location = System::Drawing::Point(544, 212);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 15;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(581, 378);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Desencriptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(876, 111);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 23);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Generar llaves";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 706);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->EncriptButton);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void GeneratePrimesNumber() {
	bool* primo = new bool[50000];
	for (unsigned i = 0; i < 50000; i++)
		primo[i] = true;
	for (unsigned i = 2; i < 50000; i++) {
		for (unsigned j = 2; i * j < 50000; j++)
			primo[i * j] = false;
	}
	for (unsigned i = 0; i < 50000; i++) {
		if (primo[i])
			PrimeArray.Add(i);
	}
	delete primo;
}
private: void FullCombobox() {
	for (int i = 100;i < PrimeArray.Count;i++) {
		this->comboBox1->Items->Add(PrimeArray[i]);
		this->comboBox2->Items->Add(PrimeArray[i]);
	}

	// seleccionamos uno al azar
	Random r;
	int indexR;
	int indexR2;
	do {
		indexR = r.Next(0, PrimeArray.Count - 100);
		indexR2 = r.Next(0, PrimeArray.Count - 100);

	} while (indexR == indexR2);
		this->comboBox1->SelectedIndex = indexR;
		this->comboBox2->SelectedIndex = indexR2;
	

}
private: void MarshalString(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  f) {
		
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}


	private: System::Void generateKeys() {

		// Asignamos 'p' segun el combobox2
		std::string NumberPStandard = "";
		MarshalString(this->comboBox2->Text, NumberPStandard);
		rsa->SetMyPrivateKeyP(NumberPStandard); // lo pasamos como string, y en rsa.h usamos std::stoll

		// Asignamos 'q' segun el combobox1
		std::string NumberQStandard = "";
		MarshalString(this->comboBox1->Text, NumberQStandard);
		rsa->SetMyPrivateKeyQ(NumberQStandard);

		Random r2;
		int Dindex = r2.Next(250, PrimeArray.Count - 250);
		long long d = PrimeArray[Dindex];
		rsa->CreateKey(d);


		// seteamos los labels de PublicKey y PrivateKey
		label9->Text = "(" + rsa->GetPublicKey().n + "," + rsa->GetPublicKey().e + ")";
		label10->Text = "(" + rsa->GetPublicKey().n + "," + rsa->GetPrivateKey().d + ")";

	}

private: System::Void Encript_Click(System::Object^ sender, System::EventArgs^ e) {
	

	// Con esto agarramos lo que se haya inscrito en el textbox1 y lo seteamos a rsa.h
	std::string MensajeEncryp = "";
	MarshalString(this->textBox1->Text, MensajeEncryp);
	rsa->SetMessage(MensajeEncryp);
	
    

	// Intentamos hacer que se visulice el texto encriptado en la otra caja de texto
	vector<unsigned long long> aux = rsa->EncryptationMetodRSA();


	this->textBox2->Text = "";
	for (int i = 0; i < aux.size(); i++)
	{
		
		System::String^ visualiza = aux[i].ToString() + " ";
		this->textBox2->Text += visualiza;
	}



	
}

	private:  std::vector<std::string> split(const std::string& s, char delim) {

		std::stringstream ss(s);
		std::string item;
		std::vector<std::string> elems;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
			// elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
		}
		return elems;
		 
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


	System::String^ tc = this->textBox2->Text;

	std::string textoCifrado = "";
	MarshalString(this->textBox2->Text, textoCifrado);


	std::vector<std::string> stringCodes = split(textoCifrado, ' ');

	vector<unsigned long long> codes;
	for (int i = 0; i < stringCodes.size(); i++)
	{
		codes.push_back(std::stoll(stringCodes[i]));
	}

	std::string textoOriginal=  rsa->DecryptationMethod(codes);

	System::String^ visualiza = gcnew System::String(textoOriginal.c_str());

	this->textBox1->Text = visualiza;

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	generateKeys();

}
};
}

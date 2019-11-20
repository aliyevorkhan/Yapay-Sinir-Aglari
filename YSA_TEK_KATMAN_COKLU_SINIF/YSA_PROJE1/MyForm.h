#pragma once
#include "Noktalar.h"
#include "Matris.h"
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int pictureBoxBoyutu = 375;
int pictureBoxBoyutununYarisi = 175;
int zoom = 66;
double epsilon = 0.1;
int bias = 1;
int yazmaFrekansi = 100;
double perceptronOgrenmeOrani = 0.2;
double deltaOgrenmeOrani = 0.8;
int ilkCagrim = 1;
int sinifBirSayac = 0, sinifIkiSayac = 0, sinifUcSayac = 0, sinifDortSayac = 0, sinifBesSayac = 0, SinifAltiSayac = 0;
int sinifBoyutu;

namespace YSAPROJE1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::RadioButton^  rb_sinif1;
	private: System::Windows::Forms::RadioButton^  rb_sinif2;
	private: System::Windows::Forms::RadioButton^  rb_sinif3;
	private: System::Windows::Forms::RadioButton^  rb_sinif4;
	private: System::Windows::Forms::RadioButton^  rb_sinif5;
	private: System::Windows::Forms::RadioButton^  rb_sinif6;
	private: System::Windows::Forms::RadioButton^  radioButtonPerceptron;
	private: System::Windows::Forms::RadioButton^  radioButtonDelta;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  cb_normalize;
	private: System::Windows::Forms::Button^  btn_temizle;
	private: System::Windows::Forms::Button^  btn_uygula;
	private: System::Windows::Forms::Label^  label1;
	private: Noktalar^ referansNoktalar = gcnew Noktalar();
			 Matris^ w;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  ls5;
	private: System::Windows::Forms::Label^  ls6;
	private: System::Windows::Forms::Label^  ls4;
	private: System::Windows::Forms::Label^  ls3;
	private: System::Windows::Forms::Label^  ls2;
	private: System::Windows::Forms::Label^  ls1;
	private: System::Windows::Forms::RichTextBox^  rtbAgirliklar;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->rb_sinif1 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_sinif2 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_sinif3 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_sinif4 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_sinif5 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_sinif6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPerceptron = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonDelta = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ls5 = (gcnew System::Windows::Forms::Label());
			this->ls6 = (gcnew System::Windows::Forms::Label());
			this->ls4 = (gcnew System::Windows::Forms::Label());
			this->ls3 = (gcnew System::Windows::Forms::Label());
			this->ls2 = (gcnew System::Windows::Forms::Label());
			this->ls1 = (gcnew System::Windows::Forms::Label());
			this->cb_normalize = (gcnew System::Windows::Forms::CheckBox());
			this->btn_temizle = (gcnew System::Windows::Forms::Button());
			this->btn_uygula = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->rtbAgirliklar = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(6, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(375, 375);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// rb_sinif1
			// 
			this->rb_sinif1->AutoSize = true;
			this->rb_sinif1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->rb_sinif1->Checked = true;
			this->rb_sinif1->ForeColor = System::Drawing::Color::Blue;
			this->rb_sinif1->Location = System::Drawing::Point(6, 17);
			this->rb_sinif1->Name = L"rb_sinif1";
			this->rb_sinif1->Size = System::Drawing::Size(57, 17);
			this->rb_sinif1->TabIndex = 1;
			this->rb_sinif1->TabStop = true;
			this->rb_sinif1->Text = L"Sinif1";
			this->rb_sinif1->UseVisualStyleBackColor = false;
			// 
			// rb_sinif2
			// 
			this->rb_sinif2->AutoSize = true;
			this->rb_sinif2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->rb_sinif2->ForeColor = System::Drawing::Color::Red;
			this->rb_sinif2->Location = System::Drawing::Point(6, 33);
			this->rb_sinif2->Name = L"rb_sinif2";
			this->rb_sinif2->Size = System::Drawing::Size(57, 17);
			this->rb_sinif2->TabIndex = 2;
			this->rb_sinif2->Text = L"Sinif2";
			this->rb_sinif2->UseVisualStyleBackColor = false;
			// 
			// rb_sinif3
			// 
			this->rb_sinif3->AutoSize = true;
			this->rb_sinif3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->rb_sinif3->ForeColor = System::Drawing::Color::Yellow;
			this->rb_sinif3->Location = System::Drawing::Point(6, 50);
			this->rb_sinif3->Name = L"rb_sinif3";
			this->rb_sinif3->Size = System::Drawing::Size(57, 17);
			this->rb_sinif3->TabIndex = 3;
			this->rb_sinif3->Text = L"Sinif3";
			this->rb_sinif3->UseVisualStyleBackColor = false;
			// 
			// rb_sinif4
			// 
			this->rb_sinif4->AutoSize = true;
			this->rb_sinif4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->rb_sinif4->ForeColor = System::Drawing::Color::Green;
			this->rb_sinif4->Location = System::Drawing::Point(6, 67);
			this->rb_sinif4->Name = L"rb_sinif4";
			this->rb_sinif4->Size = System::Drawing::Size(57, 17);
			this->rb_sinif4->TabIndex = 4;
			this->rb_sinif4->Text = L"Sinif4";
			this->rb_sinif4->UseVisualStyleBackColor = false;
			// 
			// rb_sinif5
			// 
			this->rb_sinif5->AutoSize = true;
			this->rb_sinif5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->rb_sinif5->ForeColor = System::Drawing::Color::Purple;
			this->rb_sinif5->Location = System::Drawing::Point(6, 84);
			this->rb_sinif5->Name = L"rb_sinif5";
			this->rb_sinif5->Size = System::Drawing::Size(57, 17);
			this->rb_sinif5->TabIndex = 5;
			this->rb_sinif5->Text = L"Sinif5";
			this->rb_sinif5->UseVisualStyleBackColor = false;
			// 
			// rb_sinif6
			// 
			this->rb_sinif6->AutoSize = true;
			this->rb_sinif6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->rb_sinif6->ForeColor = System::Drawing::Color::Cyan;
			this->rb_sinif6->Location = System::Drawing::Point(6, 101);
			this->rb_sinif6->Name = L"rb_sinif6";
			this->rb_sinif6->Size = System::Drawing::Size(57, 17);
			this->rb_sinif6->TabIndex = 6;
			this->rb_sinif6->Text = L"Sinif6";
			this->rb_sinif6->UseVisualStyleBackColor = false;
			// 
			// radioButtonPerceptron
			// 
			this->radioButtonPerceptron->AutoSize = true;
			this->radioButtonPerceptron->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->radioButtonPerceptron->Checked = true;
			this->radioButtonPerceptron->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->radioButtonPerceptron->ForeColor = System::Drawing::Color::White;
			this->radioButtonPerceptron->Location = System::Drawing::Point(482, 23);
			this->radioButtonPerceptron->Name = L"radioButtonPerceptron";
			this->radioButtonPerceptron->Size = System::Drawing::Size(87, 17);
			this->radioButtonPerceptron->TabIndex = 7;
			this->radioButtonPerceptron->TabStop = true;
			this->radioButtonPerceptron->Text = L"Perceptron";
			this->radioButtonPerceptron->UseVisualStyleBackColor = false;
			// 
			// radioButtonDelta
			// 
			this->radioButtonDelta->AutoSize = true;
			this->radioButtonDelta->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->radioButtonDelta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonDelta->ForeColor = System::Drawing::Color::White;
			this->radioButtonDelta->Location = System::Drawing::Point(482, 40);
			this->radioButtonDelta->Name = L"radioButtonDelta";
			this->radioButtonDelta->Size = System::Drawing::Size(55, 17);
			this->radioButtonDelta->TabIndex = 8;
			this->radioButtonDelta->Text = L"Delta";
			this->radioButtonDelta->UseVisualStyleBackColor = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->groupBox1->Controls->Add(this->ls5);
			this->groupBox1->Controls->Add(this->ls6);
			this->groupBox1->Controls->Add(this->ls4);
			this->groupBox1->Controls->Add(this->ls3);
			this->groupBox1->Controls->Add(this->ls2);
			this->groupBox1->Controls->Add(this->ls1);
			this->groupBox1->Controls->Add(this->rb_sinif4);
			this->groupBox1->Controls->Add(this->rb_sinif1);
			this->groupBox1->Controls->Add(this->rb_sinif2);
			this->groupBox1->Controls->Add(this->rb_sinif6);
			this->groupBox1->Controls->Add(this->rb_sinif3);
			this->groupBox1->Controls->Add(this->rb_sinif5);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(387, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(89, 124);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sınıflar:";
			// 
			// ls5
			// 
			this->ls5->AutoSize = true;
			this->ls5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ls5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ls5->ForeColor = System::Drawing::Color::Purple;
			this->ls5->Location = System::Drawing::Point(62, 86);
			this->ls5->Name = L"ls5";
			this->ls5->Size = System::Drawing::Size(16, 15);
			this->ls5->TabIndex = 17;
			this->ls5->Text = L"0";
			// 
			// ls6
			// 
			this->ls6->AutoSize = true;
			this->ls6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ls6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ls6->ForeColor = System::Drawing::Color::Cyan;
			this->ls6->Location = System::Drawing::Point(62, 103);
			this->ls6->Name = L"ls6";
			this->ls6->Size = System::Drawing::Size(16, 15);
			this->ls6->TabIndex = 11;
			this->ls6->Text = L"0";
			// 
			// ls4
			// 
			this->ls4->AutoSize = true;
			this->ls4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ls4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ls4->ForeColor = System::Drawing::Color::Green;
			this->ls4->Location = System::Drawing::Point(62, 69);
			this->ls4->Name = L"ls4";
			this->ls4->Size = System::Drawing::Size(16, 15);
			this->ls4->TabIndex = 10;
			this->ls4->Text = L"0";
			// 
			// ls3
			// 
			this->ls3->AutoSize = true;
			this->ls3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ls3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ls3->ForeColor = System::Drawing::Color::Yellow;
			this->ls3->Location = System::Drawing::Point(62, 52);
			this->ls3->Name = L"ls3";
			this->ls3->Size = System::Drawing::Size(16, 15);
			this->ls3->TabIndex = 9;
			this->ls3->Text = L"0";
			// 
			// ls2
			// 
			this->ls2->AutoSize = true;
			this->ls2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ls2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ls2->ForeColor = System::Drawing::Color::Red;
			this->ls2->Location = System::Drawing::Point(62, 35);
			this->ls2->Name = L"ls2";
			this->ls2->Size = System::Drawing::Size(16, 15);
			this->ls2->TabIndex = 8;
			this->ls2->Text = L"0";
			// 
			// ls1
			// 
			this->ls1->AutoSize = true;
			this->ls1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ls1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ls1->ForeColor = System::Drawing::Color::Blue;
			this->ls1->Location = System::Drawing::Point(62, 17);
			this->ls1->Name = L"ls1";
			this->ls1->Size = System::Drawing::Size(16, 15);
			this->ls1->TabIndex = 7;
			this->ls1->Text = L"0";
			// 
			// cb_normalize
			// 
			this->cb_normalize->AutoSize = true;
			this->cb_normalize->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->cb_normalize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_normalize->ForeColor = System::Drawing::Color::White;
			this->cb_normalize->Location = System::Drawing::Point(482, 63);
			this->cb_normalize->Name = L"cb_normalize";
			this->cb_normalize->Size = System::Drawing::Size(81, 17);
			this->cb_normalize->TabIndex = 11;
			this->cb_normalize->Text = L"Normalize";
			this->cb_normalize->UseVisualStyleBackColor = false;
			// 
			// btn_temizle
			// 
			this->btn_temizle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->btn_temizle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_temizle->ForeColor = System::Drawing::Color::White;
			this->btn_temizle->Location = System::Drawing::Point(523, 116);
			this->btn_temizle->Name = L"btn_temizle";
			this->btn_temizle->Size = System::Drawing::Size(90, 37);
			this->btn_temizle->TabIndex = 12;
			this->btn_temizle->Text = L"Temizle";
			this->btn_temizle->UseVisualStyleBackColor = false;
			this->btn_temizle->Click += gcnew System::EventHandler(this, &MyForm::btn_temizle_Click);
			// 
			// btn_uygula
			// 
			this->btn_uygula->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->btn_uygula->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_uygula->ForeColor = System::Drawing::Color::White;
			this->btn_uygula->Location = System::Drawing::Point(617, 116);
			this->btn_uygula->Name = L"btn_uygula";
			this->btn_uygula->Size = System::Drawing::Size(90, 37);
			this->btn_uygula->TabIndex = 13;
			this->btn_uygula->Text = L"Uygula";
			this->btn_uygula->UseVisualStyleBackColor = false;
			this->btn_uygula->Click += gcnew System::EventHandler(this, &MyForm::btn_uygula_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(387, 342);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 15);
			this->label1->TabIndex = 14;
			this->label1->Text = L"*****";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown1->ForeColor = System::Drawing::Color::White;
			this->numericUpDown1->Location = System::Drawing::Point(462, 133);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(33, 20);
			this->numericUpDown1->TabIndex = 15;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(387, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 15);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Sinif sayisi";
			// 
			// rtbAgirliklar
			// 
			this->rtbAgirliklar->BackColor = System::Drawing::Color::White;
			this->rtbAgirliklar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtbAgirliklar->Location = System::Drawing::Point(387, 159);
			this->rtbAgirliklar->Name = L"rtbAgirliklar";
			this->rtbAgirliklar->Size = System::Drawing::Size(355, 180);
			this->rtbAgirliklar->TabIndex = 18;
			this->rtbAgirliklar->Text = L"";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Red;
			this->button2->Location = System::Drawing::Point(737, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 20;
			this->button2->Text = L"X";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(12, 50);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(755, 426);
			this->tabControl1->TabIndex = 21;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->radioButtonPerceptron);
			this->tabPage1->Controls->Add(this->rtbAgirliklar);
			this->tabPage1->Controls->Add(this->radioButtonDelta);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->numericUpDown1);
			this->tabPage1->Controls->Add(this->cb_normalize);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->btn_temizle);
			this->tabPage1->Controls->Add(this->btn_uygula);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(747, 400);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L" Tek Katman Çok Sınıf";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(298, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(194, 20);
			this->label3->TabIndex = 22;
			this->label3->Text = L"YAPAY SİNİR AĞLARI";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(701, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 30);
			this->button3->TabIndex = 24;
			this->button3->Text = L"_";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(779, 488);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button2);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"YSA ÇOKLU SINIF";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btn_uygula_Click(System::Object^  sender, System::EventArgs^  e) {
		if ((numericUpDown1->Value == 2 && rb_sinif3->Checked) || (numericUpDown1->Value == 2 && rb_sinif4->Checked) || (numericUpDown1->Value == 2 && rb_sinif5->Checked) || (numericUpDown1->Value == 2 && rb_sinif6->Checked)) {
			MessageBox::Show("Sinif boyutu hatasi!!!", "Uyari!");
		}
		else if (radioButtonDelta->Checked && !cb_normalize->Checked) {
			MessageBox::Show("Normalize etmeden Delta ögrenme kurali ile ögrenme yapilamaz", "Uyari!");
		}
		else {

			sinifBoyutu = (int)numericUpDown1->Value;
			Nokta* p = referansNoktalar->getNoktalar();
			srand(time(NULL));
			int i, j;
			double c = perceptronOgrenmeOrani;
			if (radioButtonDelta->Checked) {
				c = deltaOgrenmeOrani;
			}
			w = gcnew Matris(sinifBoyutu, 3);
			double *matris = w->getMatris();
			for (i = 0; i < sinifBoyutu; i++) {
				for (j = 0; j < 3; j++) {
					matris[i * 3 + j] = ((double)rand() / RAND_MAX);
				}
			}

			int** dBeklenen = new int*[sinifBoyutu];

			for (i = 0; i < sinifBoyutu; i++) {
				dBeklenen[i] = new int[sinifBoyutu];
			}

			for (i = 0; i < sinifBoyutu; i++) {
				for (j = 0; j < sinifBoyutu; j++) {
					if (i == j) {
						dBeklenen[i][j] = 1;
					}
					else {
						dBeklenen[i][j] = -1;
					}
				}
			}
			if (cb_normalize->Checked && ilkCagrim) {
				ilkCagrim = 0;

				int x2Toplam = 0;
				int y2Toplam = 0;

				double varyansX;
				double varyansY;

				double totalX = 0, totalY = 0;
				int noktaNumarasi;

				Nokta* p = referansNoktalar->getNoktalar();
				while ((p = p->getSonraki()) != nullptr) {
					int x = p->getX();
					int y = p->getY();

					totalX += x;
					totalY += y;

					x2Toplam += (x * x);
					y2Toplam += (y * y);

					noktaNumarasi++;
				}

				totalX /= noktaNumarasi;
				totalY /= noktaNumarasi;

				varyansX = (x2Toplam / noktaNumarasi) - (totalX * totalX);
				varyansY = (y2Toplam / noktaNumarasi) - (totalY * totalY);

				// Set points
				p = referansNoktalar->getNoktalar();
				while ((p = p->getSonraki()) != nullptr) {
					p->setX((p->getX() - totalX) / sqrt(varyansX));
					p->setY((p->getY() - totalY) / sqrt(varyansY));
				}
			}

			int yazmaSayaci = 0;
			int tamamlandiMi = 0;

			int sayac = 0;
			double E = 1;
			while (true) {//TODO
				p = p->getSonraki();
				if (p == nullptr) {
					p = referansNoktalar->getNoktalar();
					sayac++;
					if (tamamlandiMi || E < epsilon) {
						break;
					}
					E = 0;
					tamamlandiMi = 1;
					continue;
				}

				Matris^ y = gcnew Matris(3, 1);
				double* ptr = y->getMatris();
				ptr[0] = p->getX();
				ptr[1] = p->getY();
				ptr[2] = bias;

				Matris^ d = w * y;
				double* dBulunan = d->getMatris();
				for (i = 0; i < sinifBoyutu; i++) {
					double fTnet;
					double dMinusO = dBeklenen[i][p->getSinifNo()] - fNet(radioButtonPerceptron->Checked, dBulunan[i], &fTnet);

					if (dMinusO > epsilon || dMinusO < -epsilon) { 
						E += 0.5 * dMinusO * dMinusO;

						Matris^ wSatir = w->getSatirVektor(i);
						Matris^ wSatirTranspoz = wSatir->transpoz();

						wSatirTranspoz += (y * (c * dMinusO * fTnet));
						w->satirGuncelle(i, wSatirTranspoz);

						tamamlandiMi = 0;

						wSatir->~Matris();
						wSatirTranspoz->~Matris();
					}
				}
				y->~Matris();
				d->~Matris();

				if ((yazmaSayaci % yazmaFrekansi) == 0) {
					pictureBox1->Refresh();
				}

				yazmaSayaci++;
			}
			pictureBox1->Refresh();

			label1->Text = sayac + " dongude tamamlandi";
			
			rtbAgirliklar->Clear();
			int temp;
			for (i = 0; i < sinifBoyutu; i++) {
				temp = i;
				temp++;
				rtbAgirliklar->AppendText("Sinif" + temp + ":   " + (floor(100 * (w->getMatris()[i * 3])) / 100) + "\t" + (floor(100 * (w->getMatris()[i * 3 + 1])) / 100) + "\t" + (floor(100 * (w->getMatris()[i * 3 + 2])) / 100) + "\n");
			}
			pictureBox1->Refresh();
			w->~Matris();
			w = nullptr;
		}
	}

private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	Graphics^ g = e->Graphics;
	Pen^ kalem = gcnew Pen(Color::Black, 2);
	g->DrawLine(kalem, pictureBoxBoyutununYarisi, 0, pictureBoxBoyutununYarisi, pictureBoxBoyutu);
	g->DrawLine(kalem, 0, pictureBoxBoyutununYarisi, pictureBoxBoyutu, pictureBoxBoyutununYarisi);

	// ilk nokta geçersiz
	Nokta* p = referansNoktalar->getNoktalar()->getSonraki();

	while (p != nullptr) {
		if (p->getSinifNo() == 0) {
			kalem->Color = Color::Blue;
		}
		else if (p->getSinifNo() == 1) {
			kalem->Color = Color::Red;
		}
		else if (p->getSinifNo() == 2) {
			kalem->Color = Color::Yellow;
		}
		else if (p->getSinifNo() == 3) {
			kalem->Color = Color::Green;
		}
		else if (p->getSinifNo() == 4) {
			kalem->Color = Color::Purple;
		}
		else if (p->getSinifNo() == 5) {
			kalem->Color = Color::Cyan;
		}

		int x, y;
		if (cb_normalize->Checked) {
			x = pictureBoxBoyutununYarisi + p->getX() * zoom;
			y = pictureBoxBoyutununYarisi - p->getY() * zoom;
		}
		else {
			x = pictureBoxBoyutununYarisi + p->getX();
			y = pictureBoxBoyutununYarisi - p->getY();
		}

		g->DrawLine(kalem, x - 2, y - 2, x + 2, y + 2);
		g->DrawLine(kalem, x - 2, y + 2, x + 2, y - 2);
		
		p = p->getSonraki();

		if (w != nullptr) {
			double* ptr = w->getMatris();

			int pad = 1;
			if (cb_normalize->Checked) {
				pad = zoom;
			}
			for (int i = 0; i < sinifBoyutu; i++) {
				if (ptr[i * 3 + 1] == 0) {
					ptr[i * 3 + 1] = 0.00001;
				}

				int px1 = 0;
				int py1 = ((px1 - pictureBoxBoyutununYarisi) * ptr[i * 3] + pictureBoxBoyutununYarisi * ptr[i * 3 + 1] + ptr[i * 3 + 2] * pad) / (ptr[i * 3 + 1]);

				int px2 = 375;
				int py2 = ((px2 - pictureBoxBoyutununYarisi) * ptr[i * 3] + pictureBoxBoyutununYarisi * ptr[i * 3 + 1] + ptr[i * 3 + 2] * pad) / (ptr[i * 3 + 1]);

				if (i == 0) {
					kalem->Color = Color::Blue;
				}
				else if (i == 1) {
					kalem->Color = Color::Red;
				}
				else if (i == 2) {
					kalem->Color = Color::Yellow;
				}
				else if (i == 3) {
					kalem->Color = Color::Green;
				}
				else if (i == 4) {
					kalem->Color = Color::Purple;
				}
				else if (i == 5) {
					kalem->Color = Color::Cyan;
				}
				g->DrawLine(kalem, px1, py1, px2, py2);
			}
		}
	}
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	MouseEventArgs ^ms = (MouseEventArgs^)e;
	label1->Text = "*****";

	if (rb_sinif1->Checked) {
		sinifBirSayac++;
		ls1->Text = sinifBirSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), 0);
	}
	else if (rb_sinif2->Checked) {
		sinifIkiSayac++;
		ls2->Text = sinifIkiSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), 1);
	}
	else if (rb_sinif3->Checked) {
		sinifUcSayac++;
		ls3->Text = sinifUcSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), 2);
	}
	else if (rb_sinif4->Checked) {
		sinifDortSayac++;
		ls4->Text = sinifDortSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), 3);
	}
	else if (rb_sinif5->Checked) {
		sinifBesSayac++;
		ls5->Text = sinifBesSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), 4);
	}
	else if (rb_sinif6->Checked) {
		SinifAltiSayac++;
		ls6->Text = SinifAltiSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), 5);
	}

	pictureBox1->Invalidate();
}

private: System::Void btn_temizle_Click(System::Object^  sender, System::EventArgs^  e) {
	referansNoktalar->~Noktalar();
	referansNoktalar = gcnew Noktalar();

	label1->Text = "*****";
	ilkCagrim = 1;
	pictureBox1->Refresh();
	ls1->Text = "0";
	ls2->Text = "0";
	ls3->Text = "0";
	ls4->Text = "0";
	ls5->Text = "0";
	ls6->Text = "0";
	sinifBirSayac = 0;
	sinifIkiSayac = 0;
	sinifUcSayac = 0;
	sinifDortSayac = 0;
	sinifBesSayac = 0;
	SinifAltiSayac = 0;
	rb_sinif1->Checked = true;
	numericUpDown1->Value = 2;
	rtbAgirliklar->Clear();
}
private: double fNet(System::Boolean simpleAlg, double net, double *fTnet) {
	if (simpleAlg) {
		*fTnet = 1;
		return ((net >= 0 ? 1 : -1));
	}
	else {
		double temp = exp(-net) + 1;
		if (temp == 0) {
			temp = 0.0000001;
		}
		double fNet = (2.0 / (temp)-1.0);

		*fTnet = 0.5 * (1 - (fNet * fNet));
		return fNet;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState= FormWindowState::Minimized;
}
};
}

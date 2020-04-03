#pragma once
#include "Noktalar.h"
#include "Matris.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

#define PICTURE_BOX_SIZE 351
#define PICTURE_BOX_SIZE_DIV_TWO 175
double E = 1;

#define DEBUG 0
#define PRINT_ERROR 0
#define PRINT_FREQ 1000
double *initialMatris;
int K, J, I = 2; // input size (x, y);
#define ZOOM 50

#define BIAS 1
#define EPSILON 0.5


#define LEARNING_RATE_DELTA 0.8

vector<int> ornekler;
vector<double> normalizeOrnekler;

namespace YSACOKKATMAN {
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
	private: System::Windows::Forms::PictureBox^  pictureBoxCoordinate;
	private: System::Windows::Forms::GroupBox^  groupBoxClass;
	private: System::Windows::Forms::RadioButton^  radioButtonSinifBir;

	private: System::Windows::Forms::RadioButton^  radioButtonClassTwo;
	private: System::Windows::Forms::RadioButton^  radioButtonClassThree;
	private: System::Windows::Forms::RadioButton^  radioButtonClassFour;
	private: System::Windows::Forms::RadioButton^  radioButtonClassFive;
	private: System::Windows::Forms::RadioButton^  radioButtonClassSix;


	private: System::Windows::Forms::RadioButton^  radioButtonFnet1;
	private: System::Windows::Forms::CheckBox^  checkBoxNormalization;
	private: System::Windows::Forms::Button^  buttonResetPoint;


	private: System::Windows::Forms::Button^  buttonStorePointReset;
	private: System::Windows::Forms::Label^  labelInfo;



	private: System::Windows::Forms::Label^  labelCycleError;
	private: System::Windows::Forms::PrintDialog^  printDialog1;


	protected:

	protected:

	private:

		Noktalar^ refAnnPoints = gcnew Noktalar();
		Noktalar^ refAnnNormilizedPoints = nullptr;
		Matris^ W;
		Matris^ V;

		int counterHolder = 0;
		double totalX, totalY;
		double standartDevX, standartDevY;

		int classSize = 2;
		int hiddenLayerSize = 4;
		int firstCall = 1;
		int isDone = 0;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownKatman;

	private: System::Windows::Forms::NumericUpDown^  numericUpDownSinif;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  secimlerToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  egitimToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  surekliOgrenmeToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  verileriKaydetToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  checkBox1;


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
				 this->pictureBoxCoordinate = (gcnew System::Windows::Forms::PictureBox());
				 this->groupBoxClass = (gcnew System::Windows::Forms::GroupBox());
				 this->radioButtonClassSix = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonClassFive = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonClassFour = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonClassThree = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonClassTwo = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonSinifBir = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonFnet1 = (gcnew System::Windows::Forms::RadioButton());
				 this->checkBoxNormalization = (gcnew System::Windows::Forms::CheckBox());
				 this->buttonResetPoint = (gcnew System::Windows::Forms::Button());
				 this->buttonStorePointReset = (gcnew System::Windows::Forms::Button());
				 this->labelInfo = (gcnew System::Windows::Forms::Label());
				 this->labelCycleError = (gcnew System::Windows::Forms::Label());
				 this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
				 this->numericUpDownKatman = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDownSinif = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->secimlerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->egitimToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->surekliOgrenmeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->verileriKaydetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCoordinate))->BeginInit();
				 this->groupBoxClass->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownKatman))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSinif))->BeginInit();
				 this->groupBox1->SuspendLayout();
				 this->menuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // pictureBoxCoordinate
				 // 
				 this->pictureBoxCoordinate->BackColor = System::Drawing::SystemColors::Control;
				 this->pictureBoxCoordinate->Location = System::Drawing::Point(16, 76);
				 this->pictureBoxCoordinate->Name = L"pictureBoxCoordinate";
				 this->pictureBoxCoordinate->Size = System::Drawing::Size(351, 351);
				 this->pictureBoxCoordinate->TabIndex = 0;
				 this->pictureBoxCoordinate->TabStop = false;
				 this->pictureBoxCoordinate->Click += gcnew System::EventHandler(this, &MyForm::pictureBoxCoordinate_Click);
				 this->pictureBoxCoordinate->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBoxCoordinate_Paint);
				 // 
				 // groupBoxClass
				 // 
				 this->groupBoxClass->Controls->Add(this->radioButtonClassSix);
				 this->groupBoxClass->Controls->Add(this->radioButtonClassFive);
				 this->groupBoxClass->Controls->Add(this->radioButtonClassFour);
				 this->groupBoxClass->Controls->Add(this->radioButtonClassThree);
				 this->groupBoxClass->Controls->Add(this->radioButtonClassTwo);
				 this->groupBoxClass->Controls->Add(this->radioButtonSinifBir);
				 this->groupBoxClass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->groupBoxClass->ForeColor = System::Drawing::Color::White;
				 this->groupBoxClass->Location = System::Drawing::Point(373, 76);
				 this->groupBoxClass->Name = L"groupBoxClass";
				 this->groupBoxClass->Size = System::Drawing::Size(89, 144);
				 this->groupBoxClass->TabIndex = 8;
				 this->groupBoxClass->TabStop = false;
				 // 
				 // radioButtonClassSix
				 // 
				 this->radioButtonClassSix->AutoSize = true;
				 this->radioButtonClassSix->ForeColor = System::Drawing::Color::Cyan;
				 this->radioButtonClassSix->Location = System::Drawing::Point(6, 121);
				 this->radioButtonClassSix->Name = L"radioButtonClassSix";
				 this->radioButtonClassSix->Size = System::Drawing::Size(61, 17);
				 this->radioButtonClassSix->TabIndex = 5;
				 this->radioButtonClassSix->Text = L"Sinif 6";
				 this->radioButtonClassSix->UseVisualStyleBackColor = true;
				 // 
				 // radioButtonClassFive
				 // 
				 this->radioButtonClassFive->AutoSize = true;
				 this->radioButtonClassFive->ForeColor = System::Drawing::Color::Purple;
				 this->radioButtonClassFive->Location = System::Drawing::Point(6, 102);
				 this->radioButtonClassFive->Name = L"radioButtonClassFive";
				 this->radioButtonClassFive->Size = System::Drawing::Size(61, 17);
				 this->radioButtonClassFive->TabIndex = 4;
				 this->radioButtonClassFive->Text = L"Sinif 5";
				 this->radioButtonClassFive->UseVisualStyleBackColor = true;
				 // 
				 // radioButtonClassFour
				 // 
				 this->radioButtonClassFour->AutoSize = true;
				 this->radioButtonClassFour->ForeColor = System::Drawing::Color::Green;
				 this->radioButtonClassFour->Location = System::Drawing::Point(6, 79);
				 this->radioButtonClassFour->Name = L"radioButtonClassFour";
				 this->radioButtonClassFour->Size = System::Drawing::Size(61, 17);
				 this->radioButtonClassFour->TabIndex = 3;
				 this->radioButtonClassFour->Text = L"Sinif 4";
				 this->radioButtonClassFour->UseVisualStyleBackColor = true;
				 // 
				 // radioButtonClassThree
				 // 
				 this->radioButtonClassThree->AutoSize = true;
				 this->radioButtonClassThree->ForeColor = System::Drawing::Color::Yellow;
				 this->radioButtonClassThree->Location = System::Drawing::Point(6, 56);
				 this->radioButtonClassThree->Name = L"radioButtonClassThree";
				 this->radioButtonClassThree->Size = System::Drawing::Size(61, 17);
				 this->radioButtonClassThree->TabIndex = 2;
				 this->radioButtonClassThree->Text = L"Sinif 3";
				 this->radioButtonClassThree->UseVisualStyleBackColor = true;
				 // 
				 // radioButtonClassTwo
				 // 
				 this->radioButtonClassTwo->AutoSize = true;
				 this->radioButtonClassTwo->ForeColor = System::Drawing::Color::Red;
				 this->radioButtonClassTwo->Location = System::Drawing::Point(6, 33);
				 this->radioButtonClassTwo->Name = L"radioButtonClassTwo";
				 this->radioButtonClassTwo->Size = System::Drawing::Size(61, 17);
				 this->radioButtonClassTwo->TabIndex = 1;
				 this->radioButtonClassTwo->Text = L"Sinif 2";
				 this->radioButtonClassTwo->UseVisualStyleBackColor = true;
				 // 
				 // radioButtonSinifBir
				 // 
				 this->radioButtonSinifBir->AutoSize = true;
				 this->radioButtonSinifBir->Checked = true;
				 this->radioButtonSinifBir->ForeColor = System::Drawing::Color::Blue;
				 this->radioButtonSinifBir->Location = System::Drawing::Point(7, 10);
				 this->radioButtonSinifBir->Name = L"radioButtonSinifBir";
				 this->radioButtonSinifBir->Size = System::Drawing::Size(61, 17);
				 this->radioButtonSinifBir->TabIndex = 0;
				 this->radioButtonSinifBir->TabStop = true;
				 this->radioButtonSinifBir->Text = L"Sinif 1";
				 this->radioButtonSinifBir->UseVisualStyleBackColor = true;
				 // 
				 // radioButtonFnet1
				 // 
				 this->radioButtonFnet1->AutoSize = true;
				 this->radioButtonFnet1->Checked = true;
				 this->radioButtonFnet1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->radioButtonFnet1->ForeColor = System::Drawing::Color::White;
				 this->radioButtonFnet1->Location = System::Drawing::Point(373, 226);
				 this->radioButtonFnet1->Name = L"radioButtonFnet1";
				 this->radioButtonFnet1->Size = System::Drawing::Size(55, 17);
				 this->radioButtonFnet1->TabIndex = 6;
				 this->radioButtonFnet1->TabStop = true;
				 this->radioButtonFnet1->Text = L"Delta";
				 this->radioButtonFnet1->UseVisualStyleBackColor = true;
				 // 
				 // checkBoxNormalization
				 // 
				 this->checkBoxNormalization->AutoSize = true;
				 this->checkBoxNormalization->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->checkBoxNormalization->ForeColor = System::Drawing::Color::White;
				 this->checkBoxNormalization->Location = System::Drawing::Point(373, 242);
				 this->checkBoxNormalization->Name = L"checkBoxNormalization";
				 this->checkBoxNormalization->Size = System::Drawing::Size(81, 17);
				 this->checkBoxNormalization->TabIndex = 1;
				 this->checkBoxNormalization->Text = L"Normalize";
				 this->checkBoxNormalization->UseVisualStyleBackColor = true;
				 // 
				 // buttonResetPoint
				 // 
				 this->buttonResetPoint->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
					 static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->buttonResetPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->buttonResetPoint->ForeColor = System::Drawing::Color::White;
				 this->buttonResetPoint->Location = System::Drawing::Point(468, 141);
				 this->buttonResetPoint->Name = L"buttonResetPoint";
				 this->buttonResetPoint->Size = System::Drawing::Size(186, 40);
				 this->buttonResetPoint->TabIndex = 3;
				 this->buttonResetPoint->Text = L"Herseyi Temizle";
				 this->buttonResetPoint->UseVisualStyleBackColor = false;
				 this->buttonResetPoint->Click += gcnew System::EventHandler(this, &MyForm::buttonResetPoint_Click);
				 // 
				 // buttonStorePointReset
				 // 
				 this->buttonStorePointReset->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
					 static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->buttonStorePointReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->buttonStorePointReset->ForeColor = System::Drawing::Color::White;
				 this->buttonStorePointReset->Location = System::Drawing::Point(468, 187);
				 this->buttonStorePointReset->Name = L"buttonStorePointReset";
				 this->buttonStorePointReset->Size = System::Drawing::Size(186, 33);
				 this->buttonStorePointReset->TabIndex = 3;
				 this->buttonStorePointReset->Text = L"Ekrani Temizle";
				 this->buttonStorePointReset->UseVisualStyleBackColor = false;
				 this->buttonStorePointReset->Click += gcnew System::EventHandler(this, &MyForm::buttonStorePointReset_Click);
				 // 
				 // labelInfo
				 // 
				 this->labelInfo->AutoSize = true;
				 this->labelInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelInfo->ForeColor = System::Drawing::Color::White;
				 this->labelInfo->Location = System::Drawing::Point(6, 16);
				 this->labelInfo->Name = L"labelInfo";
				 this->labelInfo->Size = System::Drawing::Size(86, 13);
				 this->labelInfo->TabIndex = 5;
				 this->labelInfo->Text = L"Ara Katman J:";
				 // 
				 // labelCycleError
				 // 
				 this->labelCycleError->AutoSize = true;
				 this->labelCycleError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelCycleError->ForeColor = System::Drawing::Color::White;
				 this->labelCycleError->Location = System::Drawing::Point(386, 395);
				 this->labelCycleError->Name = L"labelCycleError";
				 this->labelCycleError->Size = System::Drawing::Size(92, 13);
				 this->labelCycleError->TabIndex = 5;
				 this->labelCycleError->Text = L"labelCycleError\n";
				 // 
				 // printDialog1
				 // 
				 this->printDialog1->UseEXDialog = true;
				 // 
				 // numericUpDownKatman
				 // 
				 this->numericUpDownKatman->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->numericUpDownKatman->ForeColor = System::Drawing::Color::Black;
				 this->numericUpDownKatman->Location = System::Drawing::Point(124, 16);
				 this->numericUpDownKatman->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
				 this->numericUpDownKatman->Name = L"numericUpDownKatman";
				 this->numericUpDownKatman->Size = System::Drawing::Size(53, 20);
				 this->numericUpDownKatman->TabIndex = 10;
				 this->numericUpDownKatman->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
				 this->numericUpDownKatman->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
				 // 
				 // numericUpDownSinif
				 // 
				 this->numericUpDownSinif->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->numericUpDownSinif->ForeColor = System::Drawing::Color::Black;
				 this->numericUpDownSinif->Location = System::Drawing::Point(124, 36);
				 this->numericUpDownSinif->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
				 this->numericUpDownSinif->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
				 this->numericUpDownSinif->Name = L"numericUpDownSinif";
				 this->numericUpDownSinif->Size = System::Drawing::Size(53, 20);
				 this->numericUpDownSinif->TabIndex = 11;
				 this->numericUpDownSinif->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
				 this->numericUpDownSinif->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownSinif_ValueChanged);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->ForeColor = System::Drawing::Color::White;
				 this->label1->Location = System::Drawing::Point(6, 41);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(85, 13);
				 this->label1->TabIndex = 12;
				 this->label1->Text = L"Sinif Sayisi K:";
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->labelInfo);
				 this->groupBox1->Controls->Add(this->label1);
				 this->groupBox1->Controls->Add(this->numericUpDownKatman);
				 this->groupBox1->Controls->Add(this->numericUpDownSinif);
				 this->groupBox1->ForeColor = System::Drawing::Color::White;
				 this->groupBox1->Location = System::Drawing::Point(468, 76);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(186, 59);
				 this->groupBox1->TabIndex = 13;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"groupBox1";
				 // 
				 // button3
				 // 
				 this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
					 static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button3->ForeColor = System::Drawing::Color::White;
				 this->button3->Location = System::Drawing::Point(588, 38);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(30, 30);
				 this->button3->TabIndex = 27;
				 this->button3->Text = L"_";
				 this->button3->UseVisualStyleBackColor = false;
				 this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->ForeColor = System::Drawing::Color::White;
				 this->label3->Location = System::Drawing::Point(284, 38);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(194, 20);
				 this->label3->TabIndex = 26;
				 this->label3->Text = L"YAPAY SİNİR AĞLARI";
				 // 
				 // button2
				 // 
				 this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
					 static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button2->ForeColor = System::Drawing::Color::Red;
				 this->button2->Location = System::Drawing::Point(624, 38);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(30, 30);
				 this->button2->TabIndex = 25;
				 this->button2->Text = L"X";
				 this->button2->UseVisualStyleBackColor = false;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
				 // 
				 // richTextBox1
				 // 
				 this->richTextBox1->Location = System::Drawing::Point(373, 265);
				 this->richTextBox1->Name = L"richTextBox1";
				 this->richTextBox1->Size = System::Drawing::Size(281, 117);
				 this->richTextBox1->TabIndex = 28;
				 this->richTextBox1->Text = L"";
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->secimlerToolStripMenuItem });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(666, 24);
				 this->menuStrip1->TabIndex = 29;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // secimlerToolStripMenuItem
				 // 
				 this->secimlerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->egitimToolStripMenuItem,
						 this->verileriKaydetToolStripMenuItem
				 });
				 this->secimlerToolStripMenuItem->Name = L"secimlerToolStripMenuItem";
				 this->secimlerToolStripMenuItem->Size = System::Drawing::Size(64, 20);
				 this->secimlerToolStripMenuItem->Text = L"Secimler";
				 // 
				 // egitimToolStripMenuItem
				 // 
				 this->egitimToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->surekliOgrenmeToolStripMenuItem });
				 this->egitimToolStripMenuItem->Name = L"egitimToolStripMenuItem";
				 this->egitimToolStripMenuItem->Size = System::Drawing::Size(147, 22);
				 this->egitimToolStripMenuItem->Text = L"Egitim";
				 // 
				 // surekliOgrenmeToolStripMenuItem
				 // 
				 this->surekliOgrenmeToolStripMenuItem->Name = L"surekliOgrenmeToolStripMenuItem";
				 this->surekliOgrenmeToolStripMenuItem->Size = System::Drawing::Size(162, 22);
				 this->surekliOgrenmeToolStripMenuItem->Text = L"Surekli Ogrenme";
				 this->surekliOgrenmeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::surekliOgrenmeToolStripMenuItem_Click);
				 // 
				 // verileriKaydetToolStripMenuItem
				 // 
				 this->verileriKaydetToolStripMenuItem->Name = L"verileriKaydetToolStripMenuItem";
				 this->verileriKaydetToolStripMenuItem->Size = System::Drawing::Size(147, 22);
				 this->verileriKaydetToolStripMenuItem->Text = L"Verileri kaydet";
				 this->verileriKaydetToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::verileriKaydetToolStripMenuItem_Click);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
				 this->checkBox1->Location = System::Drawing::Point(468, 227);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(120, 17);
				 this->checkBox1->TabIndex = 30;
				 this->checkBox1->Text = L"Verileri Dosyadan Al";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
					 static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->ClientSize = System::Drawing::Size(666, 434);
				 this->Controls->Add(this->checkBox1);
				 this->Controls->Add(this->richTextBox1);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->labelCycleError);
				 this->Controls->Add(this->buttonStorePointReset);
				 this->Controls->Add(this->buttonResetPoint);
				 this->Controls->Add(this->groupBoxClass);
				 this->Controls->Add(this->radioButtonFnet1);
				 this->Controls->Add(this->checkBoxNormalization);
				 this->Controls->Add(this->pictureBoxCoordinate);
				 this->Controls->Add(this->menuStrip1);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCoordinate))->EndInit();
				 this->groupBoxClass->ResumeLayout(false);
				 this->groupBoxClass->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownKatman))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSinif))->EndInit();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void buttonProcess_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void buttonStorePointReset_Click(System::Object^  sender, System::EventArgs^  e) {
	

		checkBoxNormalization->Checked = false;
		counterHolder = 0;
		isDone = 0;
		firstCall = 1;
		pictureBoxCoordinate->Refresh();
	}

	private: System::Void buttonDeleteLastPoint_Click(System::Object^  sender, System::EventArgs^  e) {
		if (refAnnPoints != nullptr) {
			Nokta* p = refAnnPoints->getNoktalar();
			if (p->getSonraki() == nullptr) { //empty
				return;
			}
			while (p->getSonraki()->getSonraki() != nullptr) {
				p = p->getSonraki();
			}
			delete p->getSonraki();
			p->setSonraki(nullptr);
		}
		pictureBoxCoordinate->Refresh();
	}

	private: System::Void pictureBoxCoordinate_Click(System::Object^  sender, System::EventArgs^  e) {
		MouseEventArgs ^ms = (MouseEventArgs^)e;
		int xKonumu = (ms->X - PICTURE_BOX_SIZE_DIV_TWO);
		int yKonumu = (PICTURE_BOX_SIZE_DIV_TWO - ms->Y);
		if (radioButtonSinifBir->Checked) {
			richTextBox1->AppendText("Sinif 1 : ");

			refAnnPoints->setNoktalar(xKonumu, yKonumu, 0);
		}
		else if (radioButtonClassTwo->Checked) {
			richTextBox1->AppendText("Sinif 2 : ");
			refAnnPoints->setNoktalar(xKonumu,yKonumu, 1);
		}
		else if (radioButtonClassThree->Checked) {
			richTextBox1->AppendText("Sinif 3 : ");
			refAnnPoints->setNoktalar(xKonumu, yKonumu, 2);
		
		}
		else if (radioButtonClassFour->Checked) {
			richTextBox1->AppendText("Sinif 4 : ");
			refAnnPoints->setNoktalar(xKonumu, yKonumu, 3);
		
		}
		else if (radioButtonClassFive->Checked) {
			richTextBox1->AppendText("Sinif 5 : ");
			refAnnPoints->setNoktalar(xKonumu, yKonumu, 4);
			
		}
		else if (radioButtonClassSix->Checked) {
			richTextBox1->AppendText("Sinif 6 : ");
			refAnnPoints->setNoktalar(xKonumu, yKonumu, 5);
			
		}

		richTextBox1->AppendText("X: " + xKonumu + "y: " + yKonumu + "\n");
		pictureBoxCoordinate->Invalidate();
	}

	private: System::Void MyForm::pictureBoxCoordinate_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		Pen^ myPen = gcnew Pen(Color::Black, 2);

		g->DrawLine(myPen, PICTURE_BOX_SIZE_DIV_TWO, 0, PICTURE_BOX_SIZE_DIV_TWO, PICTURE_BOX_SIZE);
		g->DrawLine(myPen, 0, PICTURE_BOX_SIZE_DIV_TWO, PICTURE_BOX_SIZE, PICTURE_BOX_SIZE_DIV_TWO);

		int plusSize = 2;

		// ilk nokta geçersiz
		Nokta* p = refAnnPoints->getNoktalar()->getSonraki();

		if (isDone) {
			for (int i = -PICTURE_BOX_SIZE_DIV_TWO; i < PICTURE_BOX_SIZE_DIV_TWO; i += 3) {
				for (int j = PICTURE_BOX_SIZE_DIV_TWO; j > -PICTURE_BOX_SIZE_DIV_TWO; j -= 3) {
					Matris^ x = gcnew Matris(3, 1);
					x->matris[0] = (i - totalX) / standartDevX;
					x->matris[1] = (j - totalY) / standartDevY;
					x->matris[2] = BIAS;

					Matris^ temp_y = (V * x)->fnet(1);
					Matris^ y = gcnew Matris(temp_y->getSatir() + 1, temp_y->getSutun());

					for (int i = 0; i < temp_y->getSatir(); i++) {
						y->matris[i] = temp_y->matris[i];
					}
					y->matris[temp_y->getSatir()] = BIAS;

					Matris^ o = (W * y)->fnet(1);

					int classId = o->maksimumSecici();
					if (classId == 0) {
						myPen->Color = Color::Blue;
					}
					else if (classId == 1) {
						myPen->Color = Color::Red;
					}
					else if (classId == 2) {
						myPen->Color = Color::Orange;
					}
					else if (classId == 3) {
						myPen->Color = Color::Green;
					}
					else if (classId == 4) {
						myPen->Color = Color::Purple;
					}
					else if (classId == 5) {
						myPen->Color = Color::Cyan;
					}
					else {
						myPen->Color = Color::Black;
					}
					int coor_x = i + 175;
					int coor_y = 175 - j;

					g->DrawLine(myPen, coor_x, coor_y, coor_x + 1, coor_y);

					delete x;
					delete temp_y;
					delete y;
					delete o;
				}
			}

			while (p != nullptr) {
				if (p->getSinifNo() == 0) {
					myPen->Color = Color::Blue;
				}
				else if (p->getSinifNo() == 1) {
					myPen->Color = Color::Red;
				}
				else if (p->getSinifNo() == 2) {
					myPen->Color = Color::Orange;
				}
				else if (p->getSinifNo() == 3) {
					myPen->Color = Color::Green;
				}
				else if (p->getSinifNo() == 4) {
					myPen->Color = Color::Purple;
				}
				else if (p->getSinifNo() == 5) {
					myPen->Color = Color::Cyan;
				}

				int x, y;
				x = PICTURE_BOX_SIZE_DIV_TWO + p->getX();
				y = PICTURE_BOX_SIZE_DIV_TWO - p->getY();

				g->DrawLine(myPen, x - plusSize, y, x + plusSize, y);
				g->DrawLine(myPen, x, y - plusSize, x, y + plusSize);
				p = p->getSonraki();
			}
		}
		else {
			if (checkBoxNormalization->Checked) {
				p = refAnnNormilizedPoints->getNoktalar()->getSonraki();
			}
			while (p != nullptr) {
				if (p->getSinifNo() == 0) {
					myPen->Color = Color::Blue;
				}
				else if (p->getSinifNo() == 1) {
					myPen->Color = Color::Red;
				}
				else if (p->getSinifNo() == 2) {
					myPen->Color = Color::Orange;
				}
				else if (p->getSinifNo() == 3) {
					myPen->Color = Color::Green;
				}
				else if (p->getSinifNo() == 4) {
					myPen->Color = Color::Purple;
				}
				else if (p->getSinifNo() == 5) {
					myPen->Color = Color::Cyan;
				}

				int x, y;
				if (checkBoxNormalization->Checked) {
					x = PICTURE_BOX_SIZE_DIV_TWO + p->getX() * ZOOM;
					y = PICTURE_BOX_SIZE_DIV_TWO - p->getY() * ZOOM;
				}
				else {
					x = PICTURE_BOX_SIZE_DIV_TWO + p->getX();
					y = PICTURE_BOX_SIZE_DIV_TWO - p->getY();
				}

				g->DrawLine(myPen, x - plusSize, y, x + plusSize, y);
				g->DrawLine(myPen, x, y - plusSize, x, y + plusSize);
				p = p->getSonraki();
			}
		}
	}

	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		hiddenLayerSize = (int)numericUpDownKatman->Value;
	}
	private: System::Void numericUpDownSinif_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		classSize = (int)numericUpDownSinif->Value;
	}
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
private: System::Void surekliOgrenmeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	int i, j;
	double c = LEARNING_RATE_DELTA;

	checkBoxNormalization->Checked = true;
	isDone = 0;

	K = classSize;
	J = hiddenLayerSize;
	srand(time(NULL));

	V = gcnew Matris(J, I + 1);
	W = gcnew Matris(K, J + 1);

	if (checkBox1->Checked) {
		firstCall = 0;
		fstream V_Agirliklar;
		fstream W_Agirliklar;
		fstream ornekler;
		initialMatris = V->getMatris();
		V_Agirliklar.open("V_Agirliklar.txt", ios::in);
		W_Agirliklar.open("W_Agirliklar.txt", ios::in);
		ornekler.open("ornekler.txt", ios::in);


		richTextBox1->AppendText("V agirliklar");
		for (int i = 0; i < V->getSatir(); i++) {
			for (int j = 0; j < V->getSutun(); j++) {
				V_Agirliklar >> initialMatris[i*V->getSutun() + j];
				richTextBox1->AppendText(initialMatris[i*V->getSutun() + j].ToString() + "  ");
			}
		}

		richTextBox1->AppendText("W agirliklar");
		for (int i = 0; i < W->getSatir(); i++) {
			for (int j = 0; j < W->getSutun(); j++) {
				W_Agirliklar >> initialMatris[i*W->getSutun() + j];
				richTextBox1->AppendText(initialMatris[i*W->getSutun() + j].ToString() + "  ");
			}
		}
		int x, y, sinifNo;
		richTextBox1->AppendText("ornekler");
		while (ornekler) {
			ornekler >> x;
			ornekler >> y;
			ornekler >> sinifNo;
			richTextBox1->AppendText(x + " " + y + " " + sinifNo);
			refAnnPoints->setNoktalar(x, y, sinifNo);
		}
		ornekler.close();
		
	}


	if (firstCall) {
		double *matrix = V->getMatris();
		for (i = 0; i < V->getSatir(); i++) {
			for (j = 0; j < V->getSutun(); j++) {
				matrix[i * V->getSutun() + j] = ((double)rand() / RAND_MAX);
			}
		}

		matrix = W->getMatris();
		for (i = 0; i < W->getSatir(); i++) {
			for (j = 0; j < W->getSutun(); j++) {
				matrix[i * W->getSutun() + j] = ((double)rand() / RAND_MAX);
			}
		}
		firstCall = 0;
	}


	if (checkBoxNormalization->Checked) {
		if (refAnnNormilizedPoints != nullptr) {
			// TODO: deconstructer duzenlenicek
			delete refAnnNormilizedPoints;
		}
		refAnnNormilizedPoints = gcnew Noktalar();

		double x2sum = 0;
		double y2sum = 0;

		double varianceX;
		double varianceY;

		totalX = 0;
		totalY = 0;
		int pointNumber;

		Nokta* p = refAnnPoints->getNoktalar();
		while ((p = p->getSonraki()) != nullptr) {
			int x = p->getX();
			int y = p->getY();

			totalX += x;
			totalY += y;

			x2sum += (x * x);
			y2sum += (y * y);

			pointNumber++;
		}

		totalX /= pointNumber;
		totalY /= pointNumber;

		varianceX = (x2sum / pointNumber) - (totalX * totalX);
		varianceY = (y2sum / pointNumber) - (totalY * totalY);

		standartDevX = sqrt(varianceX);
		standartDevY = sqrt(varianceY);

		// Set points
		p = refAnnPoints->getNoktalar();
		while ((p = p->getSonraki()) != nullptr) {
			refAnnNormilizedPoints->setNoktalar((p->getX() - totalX) / standartDevX,
				(p->getY() - totalY) / standartDevY,
				p->getSinifNo());
		}
	}
	// paint normilized dataset
	//pictureBoxCoordinate->Refresh();

	Nokta* p = refAnnNormilizedPoints->getNoktalar();
	int counter = 0;

	clock_t start = clock();
	while (true) {
		p = p->getSonraki();
		if (p == nullptr) {
			p = refAnnNormilizedPoints->getNoktalar();

			if (E < EPSILON) {
				break;
			}
			counter++;
			E = 0;
			continue;
		}
		//richTextBox1->AppendText("Hata: ");
		//richTextBox1->AppendText(E.ToString());
		//richTextBox1->AppendText("\n");
		//richTextBox1->ScrollToCaret();
		Matris^ z = gcnew Matris(I + 1, 1);
		z->matris[0] = p->getX();
		z->matris[1] = p->getY();
		z->matris[2] = BIAS;
		// Jx1
		Matris^ temp_y = (V * z)->fnet(1); // J x 1

		// y ye bias ekle J+1 x 1
		Matris^ y = gcnew Matris(temp_y->getSatir() + 1, temp_y->getSutun());

		for (int i = 0; i < temp_y->getSatir(); i++) {
			y->matris[i] = temp_y->matris[i];
		}
		y->matris[temp_y->getSatir()] = BIAS;

		// W: K x (J+1) y: J+1 x 1
		Matris^ o = (W * y)->fnet(1); // K x 1
		Matris^ d = gcnew Matris(K, 1);

		for (int i = 0; i < K; i++) {
			if (p->getSinifNo() == i) {
				d->matris[i] = 1;
			}
			else {
				d->matris[i] = -1;
			}
		}
		// K x 1
		Matris^ dMinusO = d - o;
		//hata toplaniyor
		for (int i = 0; i < K; i++) {
			E += 0.5 * (dMinusO->matris[i] * dMinusO->matris[i]);  // 
		}
		
		// K x 1
		Matris^ fTnetK = gcnew Matris(K, 1);
		for (int i = 0; i < K; i++) {
			fTnetK->matris[i] = 0.5 * (1 - (o->matris[i] * o->matris[i])); 
		}

		// K x 1
		Matris^ delta_o = dMinusO * fTnetK;

		double _m = 1; //mü
		
		// y			yTranspoz
		// (J+1) x 1 .. 1 x (J+1)
		Matris^ yTranspoz = y->transpoz();

		// W update
		Matris^ product_temp = (delta_o * yTranspoz);
		W += (product_temp * _m);
		delete product_temp;

		delete yTranspoz;

		// J x 1
		Matris^ fTnetJ = gcnew Matris(J, 1);

		for (int i = 0; i < J; i++) {
			fTnetJ->matris[i] = 0.5 * (1 - (temp_y->matris[i] * temp_y->matris[i]));
		}

		// J x 1
		Matris^ delta_y = gcnew Matris(J, 1);

		for (int j = 0; j < J; j++) {
			double sum = 0;
			for (int k = 0; k < K; k++) {
				sum += delta_o->matris[k] * W->matris[k * W->getSutun() + j];
			}
			delta_y->matris[j] = fTnetJ->matris[j] * sum;
		}

		Matris^ zTranspoz = z->transpoz();

		// V update
		product_temp = (delta_y * zTranspoz);
		V += (product_temp * _m);

		delete product_temp;
		delete zTranspoz;
		delete z;
		delete temp_y;
		delete y;
		delete o;
		delete d;
		delete dMinusO;
		delete delta_o;
		delete delta_y;
		delete fTnetJ;
		delete fTnetK;
	}
	clock_t end = clock();
	isDone = 1;

	counterHolder += counter;
	labelCycleError->Text = "" + counterHolder + "(" + counter + ") dongude tamamlandi. " + "Egitim suresi: " + ((double)(end - start) / (CLOCKS_PER_SEC)) + " Son hata degeri: " + E + "\n";
	labelCycleError->Refresh();
	pictureBoxCoordinate->Refresh();
}

	private: System::Void buttonResetPoint_Click(System::Object^  sender, System::EventArgs^  e) {
		delete refAnnPoints;
		delete refAnnNormilizedPoints;
		refAnnPoints = gcnew Noktalar();
		refAnnNormilizedPoints = gcnew Noktalar();


		checkBoxNormalization->Checked = false;
		counterHolder = 0;
		isDone = 0;
		firstCall = 1;
		pictureBoxCoordinate->Refresh();
}
private: System::Void verileriKaydetToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	fstream V_Agirliklar;
	V_Agirliklar.open("V_Agirliklar.txt", ios::out);
	double *matris = V->getMatris();
	for (int i = 0; i < V->getSatir(); i++) {
		for (int j = 0; j < V->getSutun(); j++) {
			V_Agirliklar << matris[i * V->getSutun() + j]<<"\n";
		}
	}	
	V_Agirliklar.close();

	fstream W_Agirliklar;
	W_Agirliklar.open("W_Agirliklar.txt", ios::out);
	matris = W->getMatris();
	for (int i = 0; i < W->getSatir(); i++) {
		for (int j = 0; j < W->getSutun(); j++) {
			W_Agirliklar << matris[i * W->getSutun() + j] << "\n";
		}
	}
	W_Agirliklar.close();

	fstream Ornekler;
	Ornekler.open("ornekler.txt", ios::out);
	Nokta* p = refAnnPoints->getNoktalar();
	while ((p = p->getSonraki()) != nullptr) {
		int x = p->getX();
		int y = p->getY();
		Ornekler << x << " " << y << " " << p->getSinifNo()<<endl;
	}
	Ornekler.close();

	MessageBox::Show("Veriler dosyaya kaydedildi");
}
};
}

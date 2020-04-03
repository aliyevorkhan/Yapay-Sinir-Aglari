#pragma once
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;
#define SINIF_MAVI 1
#define SINIF_KIRMIZI -1
double biasKatsayisi = 1;
double cKatsayisi = 1;
double perceptronOgrenmeOrani = 0.2;
double deltaOgrenmeOrani = 0.8;
double lamdaKatsayisi = 1;
double hataPayiDegeri = 0.01;
double *ornekler;
double *agirliklar;
double *normalizeEdilmisDegerler;
int ornekSayisi = 0;
int maviOrnekSayisi = 0;
int kirmiziOrnekSayisi = 0;
bool cizildi = false;
bool ogrenildiMi = false;
int ilkCagirim = 1;
int sinifSayisi = 1;
int secilenSinif = 1;
int *renkDegeri;

namespace PerceptronDeltaSingleCatogory {
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
	private: System::Windows::Forms::TabPage^  tekKatman;
	private: System::Windows::Forms::Button^  buttonTemizle;
	private: System::Windows::Forms::Button^  buttonUygula;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::CheckBox^  checkBoxNormalizasyon;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButtonKirmiziSinif;
	private: System::Windows::Forms::RadioButton^  radioButtonMaviSinif;
	private: System::Windows::Forms::RadioButton^  radioButtonDelta;
	private: System::Windows::Forms::RadioButton^  radioButtonPerceptron;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  labelKirmizi;
	private: System::Windows::Forms::Label^  labelMavi;
	private: System::Windows::Forms::Label^  labelDonguSayisi;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private:
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
			this->tekKatman = (gcnew System::Windows::Forms::TabPage());
			this->labelDonguSayisi = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->buttonTemizle = (gcnew System::Windows::Forms::Button());
			this->buttonUygula = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->checkBoxNormalizasyon = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->labelKirmizi = (gcnew System::Windows::Forms::Label());
			this->labelMavi = (gcnew System::Windows::Forms::Label());
			this->radioButtonKirmiziSinif = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMaviSinif = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonDelta = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPerceptron = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tekKatman->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tekKatman
			// 
			this->tekKatman->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->tekKatman->Controls->Add(this->label3);
			this->tekKatman->Controls->Add(this->labelDonguSayisi);
			this->tekKatman->Controls->Add(this->label1);
			this->tekKatman->Controls->Add(this->trackBar1);
			this->tekKatman->Controls->Add(this->buttonTemizle);
			this->tekKatman->Controls->Add(this->buttonUygula);
			this->tekKatman->Controls->Add(this->richTextBox1);
			this->tekKatman->Controls->Add(this->checkBoxNormalizasyon);
			this->tekKatman->Controls->Add(this->groupBox1);
			this->tekKatman->Controls->Add(this->radioButtonDelta);
			this->tekKatman->Controls->Add(this->radioButtonPerceptron);
			this->tekKatman->Controls->Add(this->pictureBox1);
			this->tekKatman->Location = System::Drawing::Point(4, 21);
			this->tekKatman->Name = L"tekKatman";
			this->tekKatman->Padding = System::Windows::Forms::Padding(3);
			this->tekKatman->Size = System::Drawing::Size(747, 402);
			this->tekKatman->TabIndex = 0;
			this->tekKatman->Text = L"Tek Katman İki Sınıf";
			// 
			// labelDonguSayisi
			// 
			this->labelDonguSayisi->AutoSize = true;
			this->labelDonguSayisi->ForeColor = System::Drawing::Color::White;
			this->labelDonguSayisi->Location = System::Drawing::Point(482, 339);
			this->labelDonguSayisi->Name = L"labelDonguSayisi";
			this->labelDonguSayisi->Size = System::Drawing::Size(14, 13);
			this->labelDonguSayisi->TabIndex = 22;
			this->labelDonguSayisi->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(389, 339);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Döngü sayısı: ";
			// 
			// trackBar1
			// 
			this->trackBar1->AutoSize = false;
			this->trackBar1->Location = System::Drawing::Point(386, 369);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(355, 23);
			this->trackBar1->TabIndex = 20;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// buttonTemizle
			// 
			this->buttonTemizle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->buttonTemizle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTemizle->ForeColor = System::Drawing::Color::White;
			this->buttonTemizle->Location = System::Drawing::Point(524, 111);
			this->buttonTemizle->Name = L"buttonTemizle";
			this->buttonTemizle->Size = System::Drawing::Size(100, 30);
			this->buttonTemizle->TabIndex = 19;
			this->buttonTemizle->Text = L"Temizle";
			this->buttonTemizle->UseVisualStyleBackColor = false;
			this->buttonTemizle->Click += gcnew System::EventHandler(this, &MyForm::buttonTemizle_Click);
			// 
			// buttonUygula
			// 
			this->buttonUygula->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->buttonUygula->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonUygula->ForeColor = System::Drawing::Color::White;
			this->buttonUygula->Location = System::Drawing::Point(641, 111);
			this->buttonUygula->Name = L"buttonUygula";
			this->buttonUygula->Size = System::Drawing::Size(100, 30);
			this->buttonUygula->TabIndex = 18;
			this->buttonUygula->Text = L"Uygula";
			this->buttonUygula->UseVisualStyleBackColor = false;
			this->buttonUygula->Click += gcnew System::EventHandler(this, &MyForm::buttonUygula_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(386, 147);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(355, 180);
			this->richTextBox1->TabIndex = 17;
			this->richTextBox1->Text = L"";
			// 
			// checkBoxNormalizasyon
			// 
			this->checkBoxNormalizasyon->AutoSize = true;
			this->checkBoxNormalizasyon->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->checkBoxNormalizasyon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBoxNormalizasyon->ForeColor = System::Drawing::Color::White;
			this->checkBoxNormalizasyon->Location = System::Drawing::Point(392, 124);
			this->checkBoxNormalizasyon->Name = L"checkBoxNormalizasyon";
			this->checkBoxNormalizasyon->Size = System::Drawing::Size(106, 17);
			this->checkBoxNormalizasyon->TabIndex = 16;
			this->checkBoxNormalizasyon->Text = L"Normalizasyon";
			this->checkBoxNormalizasyon->UseVisualStyleBackColor = false;
			this->checkBoxNormalizasyon->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxNormalizasyon_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->groupBox1->Controls->Add(this->labelKirmizi);
			this->groupBox1->Controls->Add(this->labelMavi);
			this->groupBox1->Controls->Add(this->radioButtonKirmiziSinif);
			this->groupBox1->Controls->Add(this->radioButtonMaviSinif);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(386, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(136, 65);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sınıflar";
			// 
			// labelKirmizi
			// 
			this->labelKirmizi->AutoSize = true;
			this->labelKirmizi->ForeColor = System::Drawing::Color::Red;
			this->labelKirmizi->Location = System::Drawing::Point(102, 44);
			this->labelKirmizi->Name = L"labelKirmizi";
			this->labelKirmizi->Size = System::Drawing::Size(14, 13);
			this->labelKirmizi->TabIndex = 4;
			this->labelKirmizi->Text = L"0";
			// 
			// labelMavi
			// 
			this->labelMavi->AutoSize = true;
			this->labelMavi->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->labelMavi->Location = System::Drawing::Point(102, 19);
			this->labelMavi->Name = L"labelMavi";
			this->labelMavi->Size = System::Drawing::Size(14, 13);
			this->labelMavi->TabIndex = 3;
			this->labelMavi->Text = L"0";
			// 
			// radioButtonKirmiziSinif
			// 
			this->radioButtonKirmiziSinif->AutoSize = true;
			this->radioButtonKirmiziSinif->ForeColor = System::Drawing::Color::Red;
			this->radioButtonKirmiziSinif->Location = System::Drawing::Point(6, 42);
			this->radioButtonKirmiziSinif->Name = L"radioButtonKirmiziSinif";
			this->radioButtonKirmiziSinif->Size = System::Drawing::Size(90, 17);
			this->radioButtonKirmiziSinif->TabIndex = 1;
			this->radioButtonKirmiziSinif->Text = L"Kırmızı Sınıf";
			this->radioButtonKirmiziSinif->UseVisualStyleBackColor = true;
			// 
			// radioButtonMaviSinif
			// 
			this->radioButtonMaviSinif->AutoSize = true;
			this->radioButtonMaviSinif->Checked = true;
			this->radioButtonMaviSinif->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->radioButtonMaviSinif->Location = System::Drawing::Point(6, 17);
			this->radioButtonMaviSinif->Name = L"radioButtonMaviSinif";
			this->radioButtonMaviSinif->Size = System::Drawing::Size(81, 17);
			this->radioButtonMaviSinif->TabIndex = 2;
			this->radioButtonMaviSinif->TabStop = true;
			this->radioButtonMaviSinif->Text = L"Mavi Sınıf";
			this->radioButtonMaviSinif->UseVisualStyleBackColor = true;
			// 
			// radioButtonDelta
			// 
			this->radioButtonDelta->AutoSize = true;
			this->radioButtonDelta->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->radioButtonDelta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonDelta->ForeColor = System::Drawing::Color::White;
			this->radioButtonDelta->Location = System::Drawing::Point(392, 101);
			this->radioButtonDelta->Name = L"radioButtonDelta";
			this->radioButtonDelta->Size = System::Drawing::Size(55, 17);
			this->radioButtonDelta->TabIndex = 14;
			this->radioButtonDelta->Text = L"Delta";
			this->radioButtonDelta->UseVisualStyleBackColor = false;
			// 
			// radioButtonPerceptron
			// 
			this->radioButtonPerceptron->AutoSize = true;
			this->radioButtonPerceptron->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->radioButtonPerceptron->Checked = true;
			this->radioButtonPerceptron->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonPerceptron->ForeColor = System::Drawing::Color::White;
			this->radioButtonPerceptron->Location = System::Drawing::Point(392, 78);
			this->radioButtonPerceptron->Name = L"radioButtonPerceptron";
			this->radioButtonPerceptron->Size = System::Drawing::Size(86, 17);
			this->radioButtonPerceptron->TabIndex = 13;
			this->radioButtonPerceptron->TabStop = true;
			this->radioButtonPerceptron->Text = L"Perceptron";
			this->radioButtonPerceptron->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(6, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(375, 385);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tekKatman);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(12, 48);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(755, 427);
			this->tabControl1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(737, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(295, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(194, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"YAPAY SİNİR AĞLARI";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(541, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ClientSize = System::Drawing::Size(779, 488);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tekKatman->ResumeLayout(false);
			this->tekKatman->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	Graphics^ g = e->Graphics;
	Pen^ siyah = gcnew Pen(Color::Black, 2);
	g->DrawLine(siyah, pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
	g->DrawLine(siyah, 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
}
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	ornekSayisi++;
	double alinanOrnek[3];
	Pen^ kalem;
	alinanOrnek[0] = e->X - (pictureBox1->Width / 2);
	alinanOrnek[1] = ((pictureBox1->Height / 2) - e->Y);

	label3->Text += alinanOrnek[0].ToString() + " ";
	label3->Text += alinanOrnek[1].ToString();

	if (radioButtonMaviSinif->Checked) {
		kalem = gcnew Pen(Color::Blue, 2);
		alinanOrnek[2] = SINIF_MAVI;
		maviOrnekSayisi++;
		labelMavi->Text = maviOrnekSayisi.ToString();
	}
	else if(radioButtonKirmiziSinif->Checked)
	{
		kalem = gcnew Pen(Color::Red, 2);
		alinanOrnek[2] = SINIF_KIRMIZI;
		kirmiziOrnekSayisi++;
		labelKirmizi->Text = kirmiziOrnekSayisi.ToString();
	}
	pictureBox1->CreateGraphics()->DrawLine(kalem, e->X - 2, e->Y, e->X + 2, e->Y);
	pictureBox1->CreateGraphics()->DrawLine(kalem, e->X, e->Y - 2, e->X, e->Y + 2);
	orneklemeYap(alinanOrnek);
}
private: void orneklemeYap(double *alinanOrnek) {
	double *gecici = new double[(ornekSayisi - 1) * 3];
	for (int i = 0; i < (ornekSayisi - 1) * 3; i++) {
		gecici[i] = ornekler[i];
	}
	ornekler = new double[ornekSayisi * 3];
	for (int j = 0; j < (ornekSayisi - 1) * 3; j++) {
		ornekler[j] = gecici[j];
	}
	delete gecici;
	ornekler[(ornekSayisi - 1) * 3] = alinanOrnek[0];
	ornekler[(ornekSayisi - 1) * 3 + 1] = alinanOrnek[1];
	ornekler[(ornekSayisi - 1) * 3 + 2] = alinanOrnek[2];
}
private: void ornekleriRestoreEt(double *cizilecekOrnekler) {
	for (int j = 0; j < ornekSayisi * 3; j += 3) {
		float x1 = (cizilecekOrnekler[j]) + (pictureBox1->Width / 2);
		float x2 = -((cizilecekOrnekler[j + 1]) - (pictureBox1->Height / 2));
		if (cizilecekOrnekler[j + 2] == SINIF_MAVI) {
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Blue, 2), float(x1 - 2), x2, (x1 + 2), x2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Blue, 2), (x1), (x2 - 2), (x1), (x2 + 2));
		}
		else {
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Red, 2), (x1 - 2), x2, (x1 + 2), x2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Red, 2), (x1), (x2 - 2), (x1), (x2 + 2));
		}

	}
}
private: void Dogruciz(double *cizilecekOrnekler, double *cizilecekDogruAgirliklari) {
	cizildi = true;
	if (cizilecekDogruAgirliklari[0] == 0) {
		if (cizilecekDogruAgirliklari[1] != 0) {
			double y1 = -cizilecekDogruAgirliklari[2] * biasKatsayisi / cizilecekDogruAgirliklari[1];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), 0, -(y1 - pictureBox1->Height / 2), pictureBox1->Width, -(y1 - pictureBox1->Height / 2));
			ornekleriRestoreEt(cizilecekOrnekler);
		}
	}
	else {
		if (cizilecekDogruAgirliklari[1] == 0) {
			double x1 = -cizilecekDogruAgirliklari[2] * biasKatsayisi / cizilecekDogruAgirliklari[0];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), x1 + pictureBox1->Width / 2, 0, x1 + pictureBox1->Width / 2, pictureBox1->Height);
			ornekleriRestoreEt(cizilecekOrnekler);
		}
		else {
			double y1 = (-cizilecekDogruAgirliklari[2] * biasKatsayisi - (cizilecekDogruAgirliklari[0] * pictureBox1->Width / 2)) / cizilecekDogruAgirliklari[1];
			double y2 = (-cizilecekDogruAgirliklari[2] * biasKatsayisi - (cizilecekDogruAgirliklari[0] * -(pictureBox1->Width / 2))) / cizilecekDogruAgirliklari[1];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 2), 0, -(y2 - pictureBox1->Height / 2), pictureBox1->Width, -(y1 - pictureBox1->Height / 2));
			ornekleriRestoreEt(cizilecekOrnekler);
		}
	}

}
private: System::Void buttonUygula_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ilkCagirim == 1) {
		agirliklar = new double[3];
		agirliklar[0] = 0.5;
		agirliklar[1] = 1.0;
		agirliklar[2] = 1.0;
		pictureBox1->CreateGraphics()->Clear(Color::White);

		if (checkBoxNormalizasyon->Checked) {
			Dogruciz(normalizeEdilmisDegerler, agirliklar);
		}
		else
		{
			Dogruciz(ornekler, agirliklar);
		}
		ilkCagirim = 0;
	}
	else {
		richTextBox1->Clear();
	}

	if (ornekSayisi == 0) {
		MessageBox::Show("Ogrenme yapmadan once ornek almaniz gerek");
	}

	int donguSayisi = 0;
	bool donguDevamEtsinMi = true;
	double output;
	richTextBox1->Clear();
	if (radioButtonPerceptron->Checked) {
		while (donguDevamEtsinMi) {
			donguDevamEtsinMi = false;
			for (int j = 0; j < ornekSayisi * 3; j += 3) {
				if (checkBoxNormalizasyon->Checked) {
					ogrenildiMi = false;
					output = outputHesaplaPerceptron(normalizeEdilmisDegerler, agirliklar, j);
					if ((ornekler[j + 2] - output != 0)) {
						donguDevamEtsinMi = true;
						agirliklar[0] = agirlikGuncellePerceptron(normalizeEdilmisDegerler, agirliklar, 0, j, output);
						agirliklar[1] = agirlikGuncellePerceptron(normalizeEdilmisDegerler, agirliklar, 1, j, output);
						agirliklar[2] = agirlikGuncellePerceptron(normalizeEdilmisDegerler, agirliklar, 2, j, output);
					}
				}
				else {
					output = outputHesaplaPerceptron(ornekler, agirliklar, j);
					if ((ornekler[j + 2] - output != 0)) {
						donguDevamEtsinMi = true;
						agirliklar[0] = agirlikGuncellePerceptron(ornekler, agirliklar, 0, j, output);
						agirliklar[1] = agirlikGuncellePerceptron(ornekler, agirliklar, 1, j, output);
						agirliklar[2] = agirlikGuncellePerceptron(ornekler, agirliklar, 2, j, output);
					}
				}
			}
			pictureBox1->CreateGraphics()->Clear(Color::White);
			if (checkBoxNormalizasyon->Checked) {
				Dogruciz(normalizeEdilmisDegerler, agirliklar);
			}
			else {
				Dogruciz(ornekler, agirliklar);
			}
			richTextBox1->AppendText("w: " + "\t" + agirliklar[0] + "\t" + agirliklar[1] + "\t" + agirliklar[2] + "\n");
			richTextBox1->ScrollToCaret();
			donguSayisi++;
		}
		if (checkBoxNormalizasyon->Checked) {
			ogrenildiMi = true;
		}
	}
	else if(radioButtonDelta->Checked)
	{
		if (checkBoxNormalizasyon->Checked) {
			ogrenildiMi = false;
			donguSayisi = 0;
			double error;
			do {
				error = 0;
				double output;
				for (int j = 0; j < 3 * ornekSayisi; j += 3) {
					output = outputHesaplaDelta(normalizeEdilmisDegerler, agirliklar, j);
					agirliklar[0] += agirlikGuncelleDelta(normalizeEdilmisDegerler, 0, j, output);
					agirliklar[1] += agirlikGuncelleDelta(normalizeEdilmisDegerler, 1, j, output);
					agirliklar[2] += agirlikGuncelleDelta(normalizeEdilmisDegerler, 2, j, output);
					error += pow((normalizeEdilmisDegerler[j + 2] - output), 2) / 2;
				}
				pictureBox1->CreateGraphics()->Clear(Color::White);
				Dogruciz(normalizeEdilmisDegerler, agirliklar);
				donguSayisi++;
				richTextBox1->AppendText("w: " + "\t" + agirliklar[0] + "\t" + agirliklar[1] + "\t" + agirliklar[2] + "\n");
				richTextBox1->ScrollToCaret();
			} while (error > hataPayiDegeri);
			ogrenildiMi = true;

		}
	
		else {
			double error;
			donguSayisi = 0;
			do {
				error = 0;
				for (int j = 0; j < 3 * ornekSayisi; j += 3) {
					output = outputHesaplaDelta(ornekler, agirliklar, j);
					agirliklar[0] += cKatsayisi * ((ornekler[j + 2]) - output) * (ornekler[j]);
					agirliklar[1] += cKatsayisi * ((ornekler[j + 2]) - output) * (ornekler[j + 1]);
					agirliklar[2] += cKatsayisi * ((ornekler[j + 2]) - output) * biasKatsayisi;
					error += pow((ornekler[j + 2] - output), 2) / 2;
				}
				pictureBox1->CreateGraphics()->Clear(Color::White);
				Dogruciz(ornekler, agirliklar);
				donguSayisi++;
				richTextBox1->AppendText("w: " + "\t" + agirliklar[0] + "\t" + agirliklar[1] + "\t" + agirliklar[2] + "\n");
				richTextBox1->ScrollToCaret();
			} while (error > hataPayiDegeri);
			
			labelDonguSayisi->Text = donguSayisi.ToString() + " dongude tamamlandi.";
		}
	}
	labelDonguSayisi->Text = donguSayisi.ToString() + " dongude tamamlandi.";

}
private: System::Void checkBoxNormalizasyon_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBoxNormalizasyon->Checked) {
		if (ornekSayisi > 0) {
			double ssx = 0, ssy = 0, ortx = 0, orty = 0;
			normalizeEdilmisDegerler = new double[ornekSayisi * 3];
			for (int j = 0; j < ornekSayisi * 3; j++) {
				normalizeEdilmisDegerler[j] = ornekler[j];
			}
			for (int j = 0; j < ornekSayisi * 3; j += 3) {
				ssx += ornekler[j];
				ssy += ornekler[j + 1];
			}
			ssx /= ornekSayisi;
			ssy /= ornekSayisi;
			for (int j = 0; j < ornekSayisi * 3; j += 3) {
				normalizeEdilmisDegerler[j] = pow((ornekler[j] - ssx), 2);
				normalizeEdilmisDegerler[j + 1] = pow((ornekler[j + 1] - ssy), 2);
			}
			ssx = 0;
			ssy = 0;
			for (int j = 0; j < ornekSayisi * 3; j += 3) {
				ssx += normalizeEdilmisDegerler[j];
				ssy += normalizeEdilmisDegerler[j + 1];
			}
			ssx = sqrt(ssx / ornekSayisi);
			ssy = sqrt(ssy / ornekSayisi);
			for (int j = 0; j < ornekSayisi * 3; j += 3) {
				ortx += ornekler[j];
				orty += ornekler[j + 1];
			}
			ortx /= ornekSayisi;
			orty /= ornekSayisi;
			for (int j = 0; j < ornekSayisi * 3; j += 3) {
				normalizeEdilmisDegerler[j] = (ornekler[j] - ortx) / ssx;
				normalizeEdilmisDegerler[j + 1] = (ornekler[j + 1] - orty) / ssy;
			}
			pictureBox1->CreateGraphics()->Clear(Color::White);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			ornekleriRestoreEt(normalizeEdilmisDegerler);
			if (cizildi)
				Dogruciz(normalizeEdilmisDegerler, agirliklar);
		}
		else {
			MessageBox::Show("Normalize edilecek örnek yok.");
			checkBoxNormalizasyon->Checked = false;
		}
	}
	else {
		pictureBox1->CreateGraphics()->Clear(Color::White);
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
		ornekleriRestoreEt(ornekler);
		if (cizildi)
			Dogruciz(ornekler, agirliklar);
	}

}
private: System::Void buttonTemizle_Click(System::Object^  sender, System::EventArgs^  e) { 
	if(!ornekler)
		delete ornekler;
	if(!normalizeEdilmisDegerler)
		delete normalizeEdilmisDegerler;
	agirliklar = nullptr;
	ornekSayisi = 0;
	cizildi = false;
	ogrenildiMi = false;
	ilkCagirim = 1;
	checkBoxNormalizasyon->Checked = false;
	hataPayiDegeri = 0;
	trackBar1->Value = 1;
	labelDonguSayisi->Text = "0";
	pictureBox1->CreateGraphics()->Clear(Color::White);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
	maviOrnekSayisi = 0;
	kirmiziOrnekSayisi = 0;
	labelMavi->Text = maviOrnekSayisi.ToString();
	labelKirmizi->Text = kirmiziOrnekSayisi.ToString();
	richTextBox1->Clear();
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (checkBoxNormalizasyon->Checked && ogrenildiMi) {
		double *zoomlu_dogru, *zoomlu_ornekler;
		int p = 0;
		zoomlu_dogru = new double[3];
		zoomlu_ornekler = new double[ornekSayisi * 3];
		for (int j = 0; j < 3; j++) {
			if (j % 3 == 2)
				zoomlu_dogru[j] = agirliklar[j] * trackBar1->Value;
			else
				zoomlu_dogru[j] = agirliklar[j];
		}
		for (int j = 0; j < ornekSayisi * 3; j++) {
			if (j % 3 == 0 || j % 3 == 1)
				zoomlu_ornekler[j] = normalizeEdilmisDegerler[j] * trackBar1->Value;
			else
				zoomlu_ornekler[j] = normalizeEdilmisDegerler[j];
		}
		pictureBox1->CreateGraphics()->Clear(Color::White);
		Dogruciz(zoomlu_ornekler, zoomlu_dogru);
		delete zoomlu_ornekler, zoomlu_dogru;
	}
	else {
		trackBar1->Value = 1;
		MessageBox::Show("Normalizeli ogrenme yapmadiniz");
	}

}
private: double agirlikGuncellePerceptron(double *gelenOrnekler, double *gelenAgirlik, int agirlikNumarasi, int iterasyon, double output) {
	double guncellenenAgirlik;
	if (agirlikNumarasi == 0) {
		guncellenenAgirlik = gelenAgirlik[0] + cKatsayisi * ((gelenOrnekler[iterasyon + 2]) - output) * (gelenOrnekler[iterasyon]) / 2;
	}
	else if (agirlikNumarasi == 1) {
		guncellenenAgirlik = gelenAgirlik[1] + cKatsayisi * ((gelenOrnekler[iterasyon + 2]) - output) * (gelenOrnekler[iterasyon + 1]) / 2;
	}
	else if (agirlikNumarasi == 2) {
		guncellenenAgirlik = gelenAgirlik[2] + cKatsayisi * ((gelenOrnekler[iterasyon + 2]) - output) * biasKatsayisi / 2;
	}
	return guncellenenAgirlik;
}
private: double agirlikGuncelleDelta(double *gelenOrnekler,int agirlikNumarasi, int iterasyon, double output) {
	double agirlikDegeri;
	if (agirlikNumarasi == 0) {
		agirlikDegeri = cKatsayisi * ((gelenOrnekler[iterasyon + 2]) - output) * ((pow(gelenOrnekler[iterasyon + 2], 2) - pow(output, 2)) / 2) * (gelenOrnekler[iterasyon]);
	}
	else if (agirlikNumarasi == 1) {
		agirlikDegeri = cKatsayisi * ((gelenOrnekler[iterasyon + 2]) - output) * ((pow(gelenOrnekler[iterasyon + 2], 2) - pow(output, 2)) / 2) * (gelenOrnekler[iterasyon + 1]);
	}
	else if(agirlikNumarasi == 2)
	{
		agirlikDegeri = cKatsayisi * ((gelenOrnekler[iterasyon + 2]) - output) * ((pow(gelenOrnekler[iterasyon + 2], 2) - pow(output, 2)) / 2) * biasKatsayisi;
	}
	return agirlikDegeri;
}
private: double outputHesaplaPerceptron(double *gelenOrnekler, double *gelenAgirliklar, int iterasyon) {
	double output;
	output = (gelenAgirliklar[0] * gelenOrnekler[iterasyon] + (gelenAgirliklar[1] * gelenOrnekler[iterasyon + 1]) + (gelenAgirliklar[2] * biasKatsayisi));
	
	if (output >= 1) {
		output = 1;
	}
	else
	{
		output = -1;
	}

	return output;
}
private: double outputHesaplaDelta(double *gelenOrnekler, double *gelenAgirliklar, int iterasyon) {
	double output;
	output = (2 / (1 + exp(-lamdaKatsayisi * (gelenAgirliklar[0] * gelenOrnekler[iterasyon] + (gelenAgirliklar[1] * gelenOrnekler[iterasyon + 1]) + (gelenAgirliklar[2] * biasKatsayisi))))) - 1;
	return output;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void pictureBox2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	ornekSayisi++;
	double alinanOrnek[3];
	Pen^ kalem;
	alinanOrnek[0] = e->X - (pictureBox1->Width / 2);
	alinanOrnek[1] = ((pictureBox1->Height / 2) - e->Y);

	if (radioButtonMaviSinif->Checked) {
		kalem = gcnew Pen(Color::Blue, 2);
		alinanOrnek[2] = SINIF_MAVI;
		maviOrnekSayisi++;
		labelMavi->Text = maviOrnekSayisi.ToString();

	}
	else if (radioButtonKirmiziSinif->Checked)
	{
		kalem = gcnew Pen(Color::Red, 2);
		alinanOrnek[2] = SINIF_KIRMIZI;
		kirmiziOrnekSayisi++;
		labelKirmizi->Text = kirmiziOrnekSayisi.ToString();
	}
	pictureBox1->CreateGraphics()->DrawLine(kalem, e->X - 2, e->Y, e->X + 2, e->Y);
	pictureBox1->CreateGraphics()->DrawLine(kalem, e->X, e->Y - 2, e->X, e->Y + 2);
	orneklemeYap(alinanOrnek);

}
};
}

#pragma once
#include "Noktalar.h"
#include "Matris.h"

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

#define SINIF_BIR (-1)
#define SINIF_IKI (1)

int pictureBoxBoyutu = 351;
int pictureBoxBoyutununYarisi = 175;

int sinifBirSayac = 0, sinifIkiSayac = 0;

int zoom = 100;
double epsilon = 0.1;

int yazmaFrekansi = 100;

double perceptronOgrenmeOrani = 0.2;
double deltaOgrenmeOrani = 0.8;

int ilkCagrim = 1;
int tamamlandiMi = 0;
namespace YSAPROJE {

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
	private: System::Windows::Forms::RadioButton^  rb_sinif1;
	private: System::Windows::Forms::RadioButton^  rb_sinif2;
	private: System::Windows::Forms::Button^  btnUygula;
	protected:



	private: System::Windows::Forms::Button^  btnTemizle;
	private: System::Windows::Forms::CheckBox^  cbNormalize;


	private: System::Windows::Forms::RadioButton^  rb_fnet1;
	private: System::Windows::Forms::RadioButton^  rb_fnet2;


	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Label^  label1;

	private:
		Noktalar^ referansNoktalar = gcnew Noktalar();
	private: System::Windows::Forms::Label^  lSinifBirSayac;
	private: System::Windows::Forms::Label^  lSinifIkiSayac;
	private: System::Windows::Forms::RichTextBox^  rtbOrnekler;
	private: System::Windows::Forms::RichTextBox^  rtbAgirliklar;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;








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
			this->btnUygula = (gcnew System::Windows::Forms::Button());
			this->btnTemizle = (gcnew System::Windows::Forms::Button());
			this->cbNormalize = (gcnew System::Windows::Forms::CheckBox());
			this->rb_fnet1 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_fnet2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lSinifIkiSayac = (gcnew System::Windows::Forms::Label());
			this->lSinifBirSayac = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rtbOrnekler = (gcnew System::Windows::Forms::RichTextBox());
			this->rtbAgirliklar = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(351, 351);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// rb_sinif1
			// 
			this->rb_sinif1->AutoSize = true;
			this->rb_sinif1->Checked = true;
			this->rb_sinif1->ForeColor = System::Drawing::Color::Blue;
			this->rb_sinif1->Location = System::Drawing::Point(7, 14);
			this->rb_sinif1->Name = L"rb_sinif1";
			this->rb_sinif1->Size = System::Drawing::Size(54, 17);
			this->rb_sinif1->TabIndex = 1;
			this->rb_sinif1->TabStop = true;
			this->rb_sinif1->Text = L"Sinif 1";
			this->rb_sinif1->UseVisualStyleBackColor = true;
			// 
			// rb_sinif2
			// 
			this->rb_sinif2->AutoSize = true;
			this->rb_sinif2->ForeColor = System::Drawing::Color::Red;
			this->rb_sinif2->Location = System::Drawing::Point(7, 28);
			this->rb_sinif2->Name = L"rb_sinif2";
			this->rb_sinif2->Size = System::Drawing::Size(54, 17);
			this->rb_sinif2->TabIndex = 2;
			this->rb_sinif2->Text = L"Sinif 2";
			this->rb_sinif2->UseVisualStyleBackColor = true;
			// 
			// btnUygula
			// 
			this->btnUygula->BackColor = System::Drawing::SystemColors::ControlDark;
			this->btnUygula->Location = System::Drawing::Point(368, 139);
			this->btnUygula->Name = L"btnUygula";
			this->btnUygula->Size = System::Drawing::Size(95, 39);
			this->btnUygula->TabIndex = 3;
			this->btnUygula->Text = L"Uygula";
			this->btnUygula->UseVisualStyleBackColor = false;
			this->btnUygula->Click += gcnew System::EventHandler(this, &MyForm::btnUygula_Click);
			// 
			// btnTemizle
			// 
			this->btnTemizle->BackColor = System::Drawing::SystemColors::ControlDark;
			this->btnTemizle->Location = System::Drawing::Point(368, 184);
			this->btnTemizle->Name = L"btnTemizle";
			this->btnTemizle->Size = System::Drawing::Size(95, 39);
			this->btnTemizle->TabIndex = 4;
			this->btnTemizle->Text = L"Temizle";
			this->btnTemizle->UseVisualStyleBackColor = false;
			this->btnTemizle->Click += gcnew System::EventHandler(this, &MyForm::btnTemizle_Click);
			// 
			// cbNormalize
			// 
			this->cbNormalize->AutoSize = true;
			this->cbNormalize->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cbNormalize->Location = System::Drawing::Point(375, 116);
			this->cbNormalize->Name = L"cbNormalize";
			this->cbNormalize->Size = System::Drawing::Size(72, 17);
			this->cbNormalize->TabIndex = 5;
			this->cbNormalize->Text = L"Normalize";
			this->cbNormalize->UseVisualStyleBackColor = false;
			// 
			// rb_fnet1
			// 
			this->rb_fnet1->AutoSize = true;
			this->rb_fnet1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rb_fnet1->Checked = true;
			this->rb_fnet1->Location = System::Drawing::Point(375, 76);
			this->rb_fnet1->Name = L"rb_fnet1";
			this->rb_fnet1->Size = System::Drawing::Size(71, 17);
			this->rb_fnet1->TabIndex = 6;
			this->rb_fnet1->TabStop = true;
			this->rb_fnet1->Text = L"F_NET_1";
			this->rb_fnet1->UseVisualStyleBackColor = false;
			// 
			// rb_fnet2
			// 
			this->rb_fnet2->AutoSize = true;
			this->rb_fnet2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rb_fnet2->Location = System::Drawing::Point(375, 93);
			this->rb_fnet2->Name = L"rb_fnet2";
			this->rb_fnet2->Size = System::Drawing::Size(71, 17);
			this->rb_fnet2->TabIndex = 7;
			this->rb_fnet2->Text = L"F_NET_2";
			this->rb_fnet2->UseVisualStyleBackColor = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->groupBox1->Controls->Add(this->lSinifIkiSayac);
			this->groupBox1->Controls->Add(this->rb_sinif1);
			this->groupBox1->Controls->Add(this->lSinifBirSayac);
			this->groupBox1->Controls->Add(this->rb_sinif2);
			this->groupBox1->Location = System::Drawing::Point(368, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(95, 58);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sınıflar:";
			// 
			// lSinifIkiSayac
			// 
			this->lSinifIkiSayac->AutoSize = true;
			this->lSinifIkiSayac->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lSinifIkiSayac->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lSinifIkiSayac->ForeColor = System::Drawing::Color::Red;
			this->lSinifIkiSayac->Location = System::Drawing::Point(67, 30);
			this->lSinifIkiSayac->Name = L"lSinifIkiSayac";
			this->lSinifIkiSayac->Size = System::Drawing::Size(15, 15);
			this->lSinifIkiSayac->TabIndex = 12;
			this->lSinifIkiSayac->Text = L"0";
			// 
			// lSinifBirSayac
			// 
			this->lSinifBirSayac->AutoSize = true;
			this->lSinifBirSayac->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lSinifBirSayac->ForeColor = System::Drawing::Color::Blue;
			this->lSinifBirSayac->Location = System::Drawing::Point(67, 16);
			this->lSinifBirSayac->Name = L"lSinifBirSayac";
			this->lSinifBirSayac->Size = System::Drawing::Size(15, 15);
			this->lSinifBirSayac->TabIndex = 11;
			this->lSinifBirSayac->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(473, 185);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 15);
			this->label1->TabIndex = 10;
			this->label1->Text = L"*******";
			// 
			// rtbOrnekler
			// 
			this->rtbOrnekler->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rtbOrnekler->Location = System::Drawing::Point(473, 25);
			this->rtbOrnekler->Name = L"rtbOrnekler";
			this->rtbOrnekler->Size = System::Drawing::Size(219, 96);
			this->rtbOrnekler->TabIndex = 11;
			this->rtbOrnekler->Text = L"";
			// 
			// rtbAgirliklar
			// 
			this->rtbAgirliklar->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rtbAgirliklar->Location = System::Drawing::Point(473, 140);
			this->rtbAgirliklar->Name = L"rtbAgirliklar";
			this->rtbAgirliklar->Size = System::Drawing::Size(219, 42);
			this->rtbAgirliklar->TabIndex = 12;
			this->rtbAgirliklar->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label2->Location = System::Drawing::Point(473, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Örnekler:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label3->Location = System::Drawing::Point(473, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Ağırlıklar:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 377);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->rtbAgirliklar);
			this->Controls->Add(this->rtbOrnekler);
			this->Controls->Add(this->rb_fnet2);
			this->Controls->Add(this->rb_fnet1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->cbNormalize);
			this->Controls->Add(this->btnTemizle);
			this->Controls->Add(this->btnUygula);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void btnTemizle_Click(System::Object^  sender, System::EventArgs^  e) {
	referansNoktalar->~Noktalar();
	referansNoktalar = gcnew Noktalar();

	label1->Text = "*****";
	ilkCagrim = 1;
	pictureBox1->Refresh();
	rtbAgirliklar->Clear();
	rtbOrnekler->Clear();
	sinifBirSayac = 0;
	sinifIkiSayac = 0;
	lSinifBirSayac->Text = "0";
	lSinifIkiSayac->Text = "0";
	rb_sinif1->Checked = true;
}

private: System::Void btnUygula_Click(System::Object^  sender, System::EventArgs^  e) {
	if (sinifBirSayac == 0 && sinifIkiSayac == 0)
	{
		MessageBox::Show("Alinmis ornek yok ve Rastgele bir dogru cizilidi", "Uyari!");

	}
	DateTime baslangic;
	baslangic = baslangic.Now;
	Nokta* p = referansNoktalar->getNoktalar();
	int sinifBirBoyut = 0;
	int sinifIkiBoyut = 0;
	while ((p = p->getSonraki()) != nullptr)
	{
		if (p->getSinifNo() == SINIF_BIR)
		{
			sinifBirBoyut++;
		}
		else if (p->getSinifNo() == SINIF_IKI)
		{
			sinifIkiBoyut++;
		}
	}

	if (cbNormalize->Checked && ilkCagrim)
	{
		ilkCagrim = 0;

		int x2Toplam = 0, y2Toplam = 0, noktaSayisi;
		double varyansX, varyansY, totalX = 0, totalY = 0;
		
		Nokta* p = referansNoktalar->getNoktalar();
		while ((p = p->getSonraki()) != nullptr)
		{
			int x = p->getX();
			int y = p->getY();

			totalX += x;
			totalY += y;

			x2Toplam += (x * x);
			y2Toplam += (y * y);
			
			noktaSayisi++;
		}

		totalX /= noktaSayisi;
		totalY /= noktaSayisi;


		varyansX = (x2Toplam / noktaSayisi) - (totalX * totalX);
		varyansY = (y2Toplam / noktaSayisi) - (totalY * totalY);
	
		p = referansNoktalar->getNoktalar();
		while ((p=p->getSonraki()) != nullptr)
		{
			p->setX((p->getX() - totalX) / sqrt(varyansX));
			p->setY((p->getY() - totalY) / sqrt(varyansY));

		}
	}


	Matris^ x1 = gcnew Matris(3, sinifBirBoyut);
	Matris^ x2 = gcnew Matris(3, sinifIkiBoyut);

	p = referansNoktalar->getNoktalar();

	double *sinifBirPtr = x1->getMatris();
	double *sinifIkiPtr = x2->getMatris();

	int i = 0, j = 0;

	while ((p = p->getSonraki()) != nullptr)
	{
		int k = 0;
		if (p->getSinifNo() == SINIF_BIR)
		{
			sinifBirPtr[i + k * sinifBirBoyut] = p->getX();
			k++;
			sinifBirPtr[i + k * sinifBirBoyut] = p->getY();
			k++;
			sinifBirPtr[i + k * sinifBirBoyut] = 1;
			i++;
		}
		else if (p->getSinifNo() == SINIF_IKI)
		{
			sinifIkiPtr[j + k * sinifIkiBoyut] = p->getX();
			k++;
			sinifIkiPtr[j + k * sinifIkiBoyut] = p->getY();
			k++;
			sinifIkiPtr[j + k * sinifIkiBoyut] = 1;
			j++;
		}
	}

		double c = perceptronOgrenmeOrani;
		if (rb_fnet2->Checked) 
		{
			c = deltaOgrenmeOrani;
		}
		Matris^ w = gcnew Matris(3, 1);
		w->getMatris()[0] = 0.5;
		w->getMatris()[1] = 1;
		w->getMatris()[2] = -1;


		int sayac = 0;
		double E = 1;

		while (!tamamlandiMi || E > epsilon)
		{
			tamamlandiMi = 1;
			E = 0;
			if (sinifBirBoyut >= sinifIkiBoyut)
			{
				int j = 0; ///
				for (i = 0; i < sinifBirBoyut; i++)
				{
					Matris^ sutunVektor = x1->getSutunVektor(i);
					Matris^ wTranspoz = w->transpoz();
					Matris^ netMatris = (wTranspoz * sutunVektor);


					double net = netMatris->getMatris()[0];
					double fTnet;
					double dMinusO = SINIF_BIR - fNet(rb_fnet1->Checked, net, &fTnet);
					if (dMinusO > epsilon || dMinusO < -epsilon)
					{
						E += (0.5 * dMinusO * dMinusO);
						w += (sutunVektor * (c * dMinusO * fTnet));
						tamamlandiMi = 0;
					}

					sutunVektor->~Matris();
					wTranspoz->~Matris();
					netMatris->~Matris();

					if (j < sinifIkiBoyut)
					{
						sutunVektor = x2->getSutunVektor(j);
						wTranspoz = w->transpoz();
						netMatris = (wTranspoz * sutunVektor);

						double net = netMatris->getMatris()[0];
						double fTnet;
						double dMinusO = SINIF_IKI - fNet(rb_fnet1->Checked, net, &fTnet);
						if (dMinusO > epsilon || dMinusO < -epsilon)
						{
							E += (0.5 * dMinusO * dMinusO);
							w += (sutunVektor * (c*dMinusO*fTnet));
							tamamlandiMi = 0;
						}
						j++;
						sutunVektor->~Matris();
						wTranspoz->~Matris();
						netMatris->~Matris();
					}

				}
			}
			else 
			{
				int j = 0;///
				for (i = 0; i < sinifIkiBoyut; i++)
				{
					Matris^ sutunVektor = x2->getSutunVektor(i);
					Matris^ wTranspoz = w->transpoz();
					Matris^ netMatris = (wTranspoz * sutunVektor);
					/////////////////////////////////////////////////////////

					double net = netMatris->getMatris()[0];
					double fTnet;
					double dMinusO = SINIF_IKI - fNet(rb_fnet1->Checked, net, &fTnet);
					if (dMinusO > epsilon || dMinusO < -epsilon)
					{
						E += (0.5*dMinusO*dMinusO);
						w += (sutunVektor * (c*dMinusO*fTnet));
						tamamlandiMi = 0;
					}
					j++;
					sutunVektor->~Matris();
					wTranspoz->~Matris();
					netMatris->~Matris();

					if (j<sinifBirBoyut)
					{
						sutunVektor = x1->getSutunVektor(j);
						wTranspoz = w->transpoz();
						netMatris = (wTranspoz * sutunVektor);

						double net = netMatris->getMatris()[0];
						double fTnet;
						double dMinusO = SINIF_BIR - fNet(rb_fnet1->Checked, net, &fTnet);
						if (dMinusO > epsilon || dMinusO < -epsilon)
						{
							E += (0.5*dMinusO*dMinusO);
							w += (sutunVektor * (c*dMinusO*fTnet));
							tamamlandiMi = 0;
						}
						sutunVektor->~Matris();
						wTranspoz->~Matris();
						netMatris->~Matris();
					}
				}
			}
			sayac++;
			if ((sayac % yazmaFrekansi) == 0)
			{
				double* matrisTutucu = w->getMatris();

				if (matrisTutucu[1] == 0)
				{
					matrisTutucu[1] = 0.00001;
				}

				int pad = 1;
				if (cbNormalize->Checked)
				{
					pad = zoom;
				}
				int px1 = 0;
				int py1 = ((px1 - pictureBoxBoyutununYarisi) * matrisTutucu[0] + pictureBoxBoyutununYarisi * matrisTutucu[1] + matrisTutucu[2] * pad) / (matrisTutucu[1]);
				referansNoktalar->setNoktalar(px1, py1, 0);

				int px2 = pictureBoxBoyutu;
				int py2 = ((px2 - pictureBoxBoyutununYarisi) * matrisTutucu[0] + pictureBoxBoyutununYarisi* matrisTutucu[1] + matrisTutucu[2] * pad) / (matrisTutucu[1]);
				referansNoktalar->setNoktalar(px2, py2, 0);
				pictureBox1->Refresh();
			}
		}
		double* matrisTutucu = w->getMatris();
		int pad = 1;
		if (cbNormalize->Checked)
		{
			pad = zoom;
		}

		int px1 = 0;
		int py1 = ((px1 - pictureBoxBoyutununYarisi) * matrisTutucu[0] + pictureBoxBoyutununYarisi* matrisTutucu[1] + matrisTutucu[2] * pad) / (matrisTutucu[1]);
		referansNoktalar->setNoktalar(px1, py1, 0);

		int px2 = pictureBoxBoyutu;
		int py2 = ((px2 - pictureBoxBoyutununYarisi) * matrisTutucu[0] + pictureBoxBoyutununYarisi * matrisTutucu[1] + matrisTutucu[2] * pad) / (matrisTutucu[1]);
		referansNoktalar->setNoktalar(px2, py2, 0);
		label1->Text = sayac + " dongude tamamlandi";
		rtbAgirliklar->Clear();
		rtbAgirliklar->AppendText(w->getMatris()[0] + "\t" + w->getMatris()[1] + "\t" + w->getMatris()[2]);
		pictureBox1->Refresh();
		DateTime bitis;
		bitis = bitis.Now;
		TimeSpan ortalamaZaman = bitis - baslangic;
		label1->Text += "\nSure: " + (Math::Round(100 * ortalamaZaman.TotalSeconds) / 100.0F).ToString() + "sn.";



}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	Graphics^ g = e->Graphics;
	Pen^ kalem = gcnew Pen(Color::White, 2);

	g->DrawLine(kalem, pictureBoxBoyutununYarisi, 0, pictureBoxBoyutununYarisi, pictureBoxBoyutu);
	g->DrawLine(kalem, 0, pictureBoxBoyutununYarisi, pictureBoxBoyutu, pictureBoxBoyutununYarisi);

	Nokta* p = referansNoktalar->getNoktalar()->getSonraki();	 // ilk nokta geçersiz

	while (p != nullptr)
	{
		if(p->getSinifNo() == 0) {
			//cizgi ciz
			while (p->getSonraki()->getSonraki() !=nullptr)
			{
				p = p->getSonraki();
			}
			kalem->Color = Color::Black;
			int x = p->getX();
			int y = p->getY();

			int sonX = p->getSonraki()->getX();
			int sonY = p->getSonraki()->getY();

			g->DrawLine(kalem, x, y, sonX, sonY);
			break;
		}
		else if (p->getSinifNo() == SINIF_BIR)
		{
			kalem->Color = Color::Blue;
		}
		else if (p->getSinifNo() == SINIF_IKI)
		{
			kalem->Color = Color::Red;
		}

		int x, y;
		if (cbNormalize->Checked) 
		{
			x = pictureBoxBoyutununYarisi + p->getX() * zoom;
			y = pictureBoxBoyutununYarisi - p->getY() * zoom;
		}
		else
		{
			x = pictureBoxBoyutununYarisi + p->getX();
			y = pictureBoxBoyutununYarisi - p->getY();
		}
		g->DrawLine(kalem, x - 5, y - 5, x + 5, y + 5);
		g->DrawLine(kalem, x - 5, y + 5, x + 5, y - 5);
		p = p->getSonraki();
		
	}
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	MouseEventArgs ^ms = (MouseEventArgs^)e;
	label1->Text = "";

	if (rb_sinif1->Checked) {
		rtbOrnekler->SelectionColor = Color::Blue;
		rtbOrnekler->AppendText("Sinif 1: ");
		sinifBirSayac++;
		lSinifBirSayac->Text = sinifBirSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), SINIF_BIR);
	}
	else if (rb_sinif2->Checked)
	{
		rtbOrnekler->SelectionColor = Color::Red;
		rtbOrnekler->AppendText("Sinif 2: ");
		sinifIkiSayac++;
		lSinifIkiSayac->Text = sinifIkiSayac.ToString();
		referansNoktalar->setNoktalar((ms->X - pictureBoxBoyutununYarisi), (pictureBoxBoyutununYarisi - ms->Y), SINIF_IKI);
	}

	rtbOrnekler->AppendText("normal(" + ms->X + " , " + ms->Y + ") ");
	rtbOrnekler->AppendText("koordinat(" + (ms->X - pictureBoxBoyutununYarisi) + " , " + (pictureBoxBoyutununYarisi - ms->Y) + ")\n");
	rtbOrnekler->ScrollToCaret(); 
	pictureBox1->Invalidate();
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

};
}

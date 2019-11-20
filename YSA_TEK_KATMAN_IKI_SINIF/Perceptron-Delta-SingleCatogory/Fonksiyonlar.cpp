#include <iostream>
#include <math.h>
#include <time.h>
double biasKatsayisi = 1;

void Dogruciz(double *cizilecekOrnekler, double *cizilecekDogruAgirliklari) {
	cizildi = true;
	if (cizilecekDogruAgirliklari[0] == 0) {
		if (cizilecekDogruAgirliklari[1] != 0) {
			double y1 = -cizilecekDogruAgirliklari[2] * biasKatsayisi / cizilecekDogruAgirliklari[1];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, -(y1 - pictureBox1->Height / 2), pictureBox1->Width, -(y1 - pictureBox1->Height / 2));
			ornekleriRestoreEt(cizilecekOrnekler);
		}
	}
	else {
		if (cizilecekDogruAgirliklari[1] == 0) {
			double x1 = -cizilecekDogruAgirliklari[2] * biasKatsayisi / cizilecekDogruAgirliklari[0];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), x1 + pictureBox1->Width / 2, 0, x1 + pictureBox1->Width / 2, pictureBox1->Height);
			ornekleriRestoreEt(cizilecekOrnekler);
		}
		else {
			double y1 = (-cizilecekDogruAgirliklari[2] * biasKatsayisi - (cizilecekDogruAgirliklari[0] * pictureBox1->Width / 2)) / cizilecekDogruAgirliklari[1];
			double y2 = (-cizilecekDogruAgirliklari[2] * biasKatsayisi - (cizilecekDogruAgirliklari[0] * -(pictureBox1->Width / 2))) / cizilecekDogruAgirliklari[1];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, -(y2 - pictureBox1->Height / 2), pictureBox1->Width, -(y1 - pictureBox1->Height / 2));
			ornekleriRestoreEt(cizilecekOrnekler);
		}
	}
}
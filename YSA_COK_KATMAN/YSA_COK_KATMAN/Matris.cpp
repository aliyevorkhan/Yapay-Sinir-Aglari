#include "Matris.h"
#include<math.h>
Matris::Matris()
{
	this->satir = 0;
	this->sutun = 0;
	matris = nullptr;
}
Matris::Matris(int satir, int sutun)
{
	this->satir = satir;
	this->sutun = sutun;

	matris = new double[satir * sutun];
	int i;
	for (i = 0; i < satir * sutun; i++) {
		matris[i] = 0;
	}
}
Matris::~Matris() {
	delete[] matris;
}
double* Matris::getMatris() {
	return matris;
}
int Matris::getSatir() {
	return this->satir;
}
int Matris::getSutun() {
	return this->sutun;
}
Matris^ Matris::getSutunVektor(int i) {
	Matris^ gecici = gcnew Matris(this->satir, 1); //tek sutunlu, gecici, tum elemanlari sifir olan bir vektor olusturuyoruz
	for (int j = 0; j < this->satir; j++)
	{
		gecici->matris[j] = this->matris[i + j * this->sutun];
	}
	return gecici;
}
Matris^ Matris::transpoz() {
	Matris^ gecici = gcnew Matris(this->sutun, this->satir);
	int k = 0;
	for (int i = 0; i < this->sutun; i++) {
		for (int j = 0; j < this->satir; j++)
		{
			gecici->matris[k] = this->matris[i + j * sutun];
			k++;
		}
	}
	return gecici;
}
Matris^ Matris::operator+(const Matris^ diger) {
	int buyukSatir;
	int buyukSutun;

	if (this->satir > diger->satir) {
		buyukSatir = this->satir;
	}
	else
	{
		buyukSatir = diger->satir;
	}

	if (this->sutun > diger->sutun) {
		buyukSutun = this->sutun;
	}
	else
	{
		buyukSutun = diger->sutun;
	}

	Matris^ gecici = gcnew Matris(buyukSatir, buyukSutun);
	for (int i = 0; i < this->satir; i++)
	{
		for (int j = 0; j < this->sutun; j++)
		{
			gecici->matris[i*buyukSutun + j] = this->matris[i*this->sutun + j];
		}
	}

	for (int i = 0; i < diger->satir; i++)
	{
		for (int j = 0; j < diger->sutun; j++)
		{
			gecici->matris[i*buyukSutun + j] += diger->matris[i*diger->sutun + j];
		}
	}

	return gecici;
}
Matris^ Matris::operator+=(const Matris^ diger) {
	for (int i = 0; i < this->satir; i++)
	{
		for (int j = 0; j < this->sutun; j++)
		{
			this->matris[i*this->sutun + j] += diger->matris[i*diger->sutun + j];
		}
	}
	return this;
}
Matris^ Matris::operator-(const Matris^ diger) {
	int buyukSatir;
	int buyukSutun;

	if (this->satir > diger->satir) {
		buyukSatir = this->satir;
	}
	else
	{
		buyukSatir = diger->satir;
	}

	if (this->sutun > diger->sutun) {
		buyukSutun = this->sutun;
	}
	else
	{
		buyukSutun = diger->sutun;
	}

	Matris^ gecici = gcnew Matris(buyukSatir, buyukSutun);
	for (int i = 0; i < this->satir; i++)
	{
		for (int j = 0; j < this->sutun; j++)
		{
			gecici->matris[i*buyukSutun + j] = this->matris[i*this->sutun + j];
		}
	}

	for (int i = 0; i < diger->satir; i++)
	{
		for (int j = 0; j < diger->sutun; j++)
		{
			gecici->matris[i*buyukSutun + j] -= diger->matris[i*diger->sutun + j];
		}
	}
	return gecici;
}
Matris^ Matris::operator*(const Matris^ diger) {
	Matris^ gecici = gcnew Matris(this->satir, diger->sutun);

	for (int i = 0; i < this->satir; i++)
	{
		for (int k = 0; k < diger->sutun; k++)
		{
			for (int j = 0; j < this->sutun; j++)
			{
				gecici->matris[i * diger->sutun + k] += this->matris[i * this->sutun + j] * diger->matris[k + j * diger->sutun];
			}
		}
	}
	return gecici;

}
Matris^ Matris::operator*(double k) {
	int boyut = this->satir * this->sutun;
	for (int i = 0; i < boyut; i++)
	{
		this->matris[i] *= k;
	}

	return this;
}
Matris% Matris::operator=(const Matris% diger) {
	this->satir = diger.satir;
	this->sutun = diger.sutun;

	matris = new double[this->satir * this->sutun];
	int boyut = diger.satir*diger.sutun;
	for (int i = 0; i < boyut; i++)
	{
		this->matris[i] = diger.matris[i];
	}

	return *this;
}
Matris^ Matris::getSatirVektor(int i) {
	Matris^ gecici = gcnew Matris(1, this->sutun);
	int j;

	for (j = 0; j < this->sutun; j++) {
		gecici->matris[j] = this->matris[i * this->sutun + j];
	}
	return gecici;
}

Matris^ Matris::satirGuncelle(int i, Matris^ diger) {
	int j;

	for (j = 0; j < diger->satir; j++) {
		this->matris[i * this->sutun + j] = diger->matris[j];
	}
	return this;
}
int Matris::maksimumSecici(){
	int max = this->matris[0];
	int ret = 0;
	for (int i = 1; i < this->satir * this->sutun; i++) {
		if (max < this->matris[i]) {
			max = this->matris[i];
			ret = i;
		}
	}
	return ret;
}

Matris^ Matris::fnet(int f) {
	int i, j;
	switch (f)
	{
	case 1: // sigmoid
		for (i = 0; i < this->satir; i++) {
			for (j = 0; j < this->sutun; j++) {
				this->matris[i * this->sutun + j] = (2 / (1 + exp(-this->matris[i * this->sutun + j]))) - 1;
			}
		}
		break;
	case 2: // sigmoid
		for (i = 0; i < this->satir; i++) {
			for (j = 0; j < this->sutun; j++) {
				this->matris[i * this->sutun + j] = (2 / (1 + exp(-this->matris[i * this->sutun + j] * 0.000001))) - 1;
			}
		}
		break;
	default:
		break;
	}

	return this;
}

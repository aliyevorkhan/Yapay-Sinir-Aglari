#pragma once
ref class Matris {
private:
	double *matris;
	int satir;
	int sutun;
public:
	Matris();
	Matris(int satir, int sutun);
	~Matris();
	double* getMatris();
	int getSatir();
	int getSutun();
	Matris^ getSutunVektor(int i);
	Matris^ getSatirVektor(int i);
	Matris^ satirGuncelle(int i, Matris^ diger);
	Matris^ transpoz();
	Matris^ fnet(int f);
	int maksSecici();

	Matris^ operator+(const Matris^ diger);
	Matris^ operator+=(const Matris^ diger);
	Matris^ operator-(const Matris^ diger);
	Matris^ operator*(const Matris^ diger);
	Matris^ operator*(double k);
	Matris% operator=(const Matris% diger);
};
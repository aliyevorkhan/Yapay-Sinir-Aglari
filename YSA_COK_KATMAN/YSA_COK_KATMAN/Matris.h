#pragma once
ref class Matris {
private:

	int satir;
	int sutun;
public:
	double *matris;
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
	int maksimumSecici();
	Matris^ fnet(int f);

	Matris^ operator+(const Matris^ diger);
	Matris^ operator+=(const Matris^ diger);
	Matris^ operator-(const Matris^ diger);
	Matris^ operator*(const Matris^ diger);
	Matris^ operator*(double k);
	Matris% operator=(const Matris% diger);
};
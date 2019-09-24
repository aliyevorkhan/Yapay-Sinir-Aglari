#pragma once
ref class Matris{
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
	Matris^ transpoz();

	Matris^ operator+(const Matris^ diger);
	Matris^ operator+=(const Matris^ diger);
	Matris^ operator-(const Matris^ diger);
	Matris^ operator*(const Matris^ diger);
	Matris^ operator*(double k);
	Matris% operator=(const Matris% diger);
};
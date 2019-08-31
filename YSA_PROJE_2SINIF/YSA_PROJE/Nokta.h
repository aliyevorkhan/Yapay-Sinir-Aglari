#pragma once

class Nokta
{
public:
	Nokta();
	~Nokta();
	Nokta(double = 0, double = 0, int sinifNo = 0);
	void setSonraki(Nokta* n);
	Nokta* getSonraki();
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	int getSinifNo();
private:
	Nokta* sonraki;
	double x;
	double y;
	int sinifNo;
};
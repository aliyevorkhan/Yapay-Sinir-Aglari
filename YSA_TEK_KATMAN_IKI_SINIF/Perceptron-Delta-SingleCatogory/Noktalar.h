#pragma once
#include "Nokta.h"

ref class Noktalar
{
private:
	Nokta* noktalar;
public:
	Noktalar();
	~Noktalar();
	Nokta* getNoktalar();
	void setNoktalar(int x, int y, int classId);
};
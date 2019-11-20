#include "Nokta.h"

Nokta::Nokta(double x, double y, int sinifNo)
{
	this->sonraki = nullptr;
	this->x = x;
	this->y = y;
	this->sinifNo = sinifNo;
}
Nokta::~Nokta()
{
	if (sonraki != nullptr) {
		sonraki->~Nokta();
	}
}
void Nokta::setSonraki(Nokta* n) {
	this->sonraki = n;
}
Nokta* Nokta::getSonraki() {
	return this->sonraki;
}
void Nokta::setX(double x) {
	this->x = x;
}
double Nokta::getX() {
	return x;
}
void Nokta::setY(double y) {
	this->y = y;
}
double Nokta::getY() {
	return y;
}
int Nokta::getSinifNo() {
	return sinifNo;
}
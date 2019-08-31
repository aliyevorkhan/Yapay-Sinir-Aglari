#include "Noktalar.h"
#include <iostream>

using namespace std;

Noktalar::Noktalar()
{
	this->noktalar = new Nokta(0);
}

Noktalar::~Noktalar() {
	Nokta* p = noktalar;
	if (p != nullptr) {
		p->~Nokta();
	}
}

void Noktalar::setNoktalar(int x, int y, int classId) {
	Nokta* p = noktalar;
	while (p->getSonraki() != nullptr) {
		p = p->getSonraki();
	}
	p->setSonraki(new Nokta(x, y, classId));
}

Nokta* Noktalar::getNoktalar() {
	return noktalar;
}
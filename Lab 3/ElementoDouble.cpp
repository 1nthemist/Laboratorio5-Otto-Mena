/*
* ElementoDouble.cpp
*
*  Created on: May 8, 2015
*      Author: b03843
*/

#include "stdafx.h"
#include "ElementoDouble.h"

ElementoDouble::ElementoDouble(double d) :
	d(d) {
}

int ElementoDouble::compareTo(Elemento* otro) {
	int cmp = 0;
	ElementoDouble * eDouble = static_cast<ElementoDouble *>(otro);
	if (eDouble != 0) {
		cmp = this->d < eDouble->d ? -1 : this->d == eDouble->d ? 0 : 1;
	}
	return cmp;
}

void ElementoDouble::imprimir(ostream& out) const {
	out << d;
}

ElementoDouble::~ElementoDouble() {
}

#pragma once

#include "Elemento.h"

#include <iostream>
using namespace std;

class ElementoDouble : public Elemento {

private:
	double d;



public:
	ElementoDouble(double d);
	int compareTo(Elemento *);
	void imprimir(ostream &) const;
	virtual ~ElementoDouble();


};

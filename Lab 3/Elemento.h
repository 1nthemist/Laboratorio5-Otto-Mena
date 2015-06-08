#pragma once

#include <iostream>
using namespace std;

class Elemento {

	friend ostream & operator<<(ostream &, const Elemento &);

protected:
	Elemento();
	Elemento *hijoIzq, *hijoDer;

public:

	Elemento * getHijoIzq();
	Elemento * getHijoDer();
	Elemento * getElementoSiguiente();
	Elemento *elementoSiguiente;
	void setElementoSiguiente(Elemento *);
	void setHijoIzq(Elemento *);
	void setHijoDer(Elemento *);
	int Elemento::getPosicion(Elemento *);

	virtual ~Elemento();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;

	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);

};

ostream & operator<<(ostream &, const Elemento &);


#pragma once
#include "Elemento.h"
#include "Persona.h"

class ElementoPersona : public Elemento {

private:
	Persona *p;



public:
	ElementoPersona(Persona *p);
	int compareTo(Elemento *);
	void imprimir(ostream &) const;
	virtual ~ElementoPersona();


};


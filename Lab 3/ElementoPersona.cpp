#include "stdafx.h"
#include "ElementoPersona.h"

ElementoPersona::ElementoPersona(Persona *p) :
	p(p) {
}

int ElementoPersona::compareTo(Elemento* otro) {
	int cmp = 0;
	ElementoPersona * ePersona = static_cast<ElementoPersona *>(otro);
	if (ePersona != 0) {
		cmp = this->p->identificacion < ePersona->p->identificacion ? -1 : this->p->identificacion == ePersona->p->identificacion ? 0 : 1;
	}
	return cmp;
}

void ElementoPersona::imprimir(ostream& out) const {
	out << p->nombre << ":" << p->identificacion;
}

ElementoPersona::~ElementoPersona() {
}

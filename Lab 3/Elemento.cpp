
#include "stdafx.h"
#include "Elemento.h"

Elemento::Elemento() {
	hijoIzq = NULL;
	hijoDer = NULL;
	elementoSiguiente = NULL;
}

Elemento::~Elemento() {
}

Elemento * Elemento::getHijoIzq() {
	return hijoIzq;
}

Elemento * Elemento::getHijoDer() {
	return hijoDer;
}

void Elemento::setHijoIzq(Elemento * e) {
	this->hijoIzq = e;
}

void Elemento::setHijoDer(Elemento * e) {
	this->hijoDer = e;
}

void Elemento::setElementoSiguiente(Elemento * e) {
	this->elementoSiguiente = e;
}

Elemento * Elemento::getElementoSiguiente() {
	return elementoSiguiente;
}



ostream & operator<<(ostream & out, const Elemento & e) {
	e.imprimir(out);
	return out;
}

bool Elemento::operator <(Elemento& otro) {
	return this->compareTo(&otro) < 0;
}

bool Elemento::operator <=(Elemento& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Elemento::operator >(Elemento& otro) {
	return this->compareTo(&otro) > 0;
}

bool Elemento::operator >=(Elemento& otro) {
	return this->compareTo(&otro) >= 0;
}
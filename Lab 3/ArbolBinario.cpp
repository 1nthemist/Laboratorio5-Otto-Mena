/*
* ArbolBinario.cpp
*
*  Created on: 5/5/2015
*      Author: ruben.jimenez
*/

#include "stdafx.h"
#include "ArbolBinario.h"

ArbolBinario::ArbolBinario() {
	raiz = NULL;
}

ArbolBinario::~ArbolBinario() {
	if (raiz != NULL) {
		destruirRec(raiz);
	}
}

void ArbolBinario::destruirRec(Elemento * nodo) {
	if (nodo->getHijoIzq() != NULL) {
		destruirRec(nodo->getHijoIzq());
	}
	if (nodo->getHijoDer() != NULL) {
		destruirRec(nodo->getHijoDer());
	}
	// Primero se destruye a los hijos y luego al padre.
	delete nodo;
}

void ArbolBinario::insertarElemento(Elemento * elemento) {
	if (raiz == NULL) {
		raiz = elemento;
	}
	else {
		insertarElementoRec(raiz, elemento);
	}
}

void ArbolBinario::insertarElementoRec(Elemento * nodoActual,
	Elemento * elemento) {
	if (*nodoActual < *elemento) {
		if (nodoActual->getHijoIzq() != NULL) {
			insertarElementoRec(nodoActual->getHijoIzq(), elemento);
		}
		else {
			nodoActual->setHijoIzq(elemento);
		}
	}
	else {
		if (nodoActual->getHijoDer() != NULL) {
			insertarElementoRec(nodoActual->getHijoDer(), elemento);
		}
		else {
			nodoActual->setHijoDer(elemento);
		}
	}
}

ostream & operator<<(ostream & out, ArbolBinario & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}

void ArbolBinario::imprimir(Elemento* nodo, ostream& out, int profundidad) {
	if (nodo->getHijoIzq() != NULL) {
		imprimir(nodo->getHijoIzq(), out, profundidad + 1);
	}
	for (int i = 0; i < profundidad; ++i) {
		cout << "\t";
	}
	out << *nodo << endl;
	if (nodo->getHijoDer() != NULL) {
		imprimir(nodo->getHijoDer(), out, profundidad + 1);
	}
}


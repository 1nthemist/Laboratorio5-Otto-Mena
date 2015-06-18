/*
* ArbolBinario.h
*
*  Created on: 5/5/2015
*      Author: ruben.jimenez
*/

#pragma once

#include "Elemento.h"
#include <iostream>
using namespace std;

class ArbolBinario {

	friend ostream & operator<<(ostream &, ArbolBinario &);

private:
	Elemento * raiz;

public:
	ArbolBinario();
	virtual ~ArbolBinario();
	void insertarElemento(Elemento *);

private:
	void insertarElementoRec(Elemento *, Elemento *);
	void imprimir(Elemento *, ostream &, int);
	void destruirRec(Elemento *);
};

ostream & operator<<(ostream &, ArbolBinario &);


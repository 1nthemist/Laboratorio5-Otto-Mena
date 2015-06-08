//La clase lista fue construida a partir de la clase ArbolBinario creada por el profesor Ruben Jimenez para el curso
//de programacion 2, y comparta varias similitudes con esta. La clase tiene punteros a un ultimo elemento y a un
//primer elemento que formaran parte de la lista, y a partir de eso puee agregar, o eliminar elementos en cualquier
//posicion de la misma. Se hace tambien una sobrecarga al operador "<<" para poder imprimir directamente la lista en pantalla
//descendientemente (los primeros elementos se encuentran arriba).

#pragma once
#include "Elemento.h"
#include <iostream>
using namespace std;

class Lista
{
	friend ostream & operator<<(ostream &, Lista &);

private:
	Elemento *elementoPrimero;
	Elemento *elementoUltimo;
	void insertarElementoRec(Elemento *, Elemento *, int, int);
	void eliminarElementoRec(Elemento *, int, int);
	void eliminarElementoRecSimple(Elemento *, Elemento *);
	void destruirRec(Elemento *);
	int length;

public:

	Lista();
	~Lista();
	void imprimir(Elemento *, ostream &, int);
	void insertarPrimero(Elemento *);
	void insertarUltimo(Elemento *);
	void insertarEnPosicion(Elemento *, int);
	void eliminarPrimero();
	void eliminarUltimo();
	void eliminarPosicion(int);
	Elemento * getPrimero();
	Elemento * getUltimo();
	int getLength();
};

ostream & operator<<(ostream &, Lista &);


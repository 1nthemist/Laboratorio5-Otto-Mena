// Lab 3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ElementoPersona.h"
#include "Persona.h"
#include "Elemento.h"
#include "ElementoInt.h"
#include "ElementoDouble.h"
#include "Lista.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Lista a;
	for (int i = 0; i < 10; i++)
	{
		a.insertarPrimero(new ElementoInt(i));  //se agregan 10 elementos en la primera posicion cada uno, haciendo que el primero sea el ultimo
	}
	a.insertarEnPosicion(new ElementoInt(15), 7); //se inserta el elementoInt(15) en la posicion 7
	a.eliminarPrimero();   //se elimina el primer elemento
	a.eliminarPosicion(1);  //se elimina el elemento de la posicion 1
	a.eliminarUltimo();    //se elimina el ultimo elemento.

	Lista b;
	b.insertarUltimo(new ElementoDouble(3.5));    //se repiten diferentes operaciones para los elementos Double.
	b.insertarEnPosicion(new ElementoDouble(7.785),0);
	b.insertarEnPosicion(new ElementoDouble(0.5), 1);
	b.insertarPrimero(new ElementoDouble(0.01));
	
	Lista c;
	Persona * array[4];
	for (int i = 0; i < 4; i++)
	{
		array[i] = new Persona("Andres", i + 1);
	}

	
	c.insertarUltimo(new ElementoPersona(array[0]));  //se repiten diferentes operaciones para los elementos Persona.
	c.insertarEnPosicion(new ElementoPersona(array[1]),0);
	c.insertarEnPosicion(new ElementoPersona(array[2]),1);
	c.insertarPrimero(new ElementoPersona(array[3]));
	



	cout << "El primer elemento de la lista b es: " << *b.getPrimero() << " y el ultimo elemento es: " << *b.getUltimo() << endl;
	cout << "La lista b tiene: " << b.getLength() << " elementos." << endl;
	cout << "" << endl;
	cout << b << endl;
	cout << "" << endl;
	cout << "El primer elemento de la lista a es: " << *a.getPrimero() << " y el ultimo elemento es: " << *a.getUltimo() << endl;
	cout << "La lista a tiene : " << a.getLength() << " elementos." << endl;
	cout << "" << endl;
	cout << a << endl;
	cout << "" << endl;
	cout << "El primer elemento de la lista c es: " << *c.getPrimero() << " y el ultimo elemento es: " << *c.getUltimo() << endl;
	cout << "La lista c tiene : " << c.getLength() << " elementos." << endl;
	cout << "" << endl;
	cout << c << endl;
	 
	for (int i = 0; i < 4; i++)
	{

		delete array[i];
	}
	system("pause");
	return 0;
}


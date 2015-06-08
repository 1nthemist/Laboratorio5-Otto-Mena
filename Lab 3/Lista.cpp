#include "stdafx.h"
#include "Lista.h"


Lista::Lista()
{
	elementoPrimero = NULL;
	elementoUltimo = NULL;   //se inicializa la lista vacia
	length = 0; //length se actualiza cada vez que agregamos o eliminamos un elemento de la lista
}


Lista::~Lista()
{
	if (elementoPrimero != NULL) {
		destruirRec(elementoPrimero);  //destructor de la clase lista, destruye tambien
	}								 // a los demas elementos de la lista
}

void Lista::destruirRec(Elemento * e) {
	if (e->getElementoSiguiente() != NULL) {
		destruirRec(e->getElementoSiguiente());
	}
	delete e;
}


void Lista::insertarPrimero(Elemento * elementoAgregar)   //inserta un elemento en la primera posicion de la list
{
	if (elementoPrimero == NULL)
	{
		elementoPrimero = elementoAgregar;
		elementoUltimo = elementoAgregar;
		length++;
	}
	else
	{
		elementoAgregar->setElementoSiguiente(elementoPrimero);
		elementoPrimero = elementoAgregar;
		length++;
	}
}

void Lista::insertarUltimo(Elemento * elementoAgregar) //inserta un elemento en la ultima posicion de la lista
{
	if (elementoUltimo == NULL)
	{

		elementoUltimo = elementoAgregar;
		elementoPrimero = elementoAgregar;      
		length++;
	}
	else
	{
		elementoUltimo->setElementoSiguiente(elementoAgregar);
		elementoUltimo = elementoAgregar;                      
		length++;
	}
}

void Lista::insertarEnPosicion(Elemento * elementoAgregar, int posicion)
{					
	if (posicion == 0)							//inserta un elemento en cualquier posicion
	{											//notar que la posicion 0 es el inicio de la lista y agregar un elemento
		insertarPrimero(elementoAgregar);		//alli seria lo mismo que realizar el metodo insertaPrimero.
	}
	else
	{
		if (posicion == length)
		{
			insertarUltimo(elementoAgregar);
		}
		else
		{
			int espaciosAvanzar = 0;    //este contador nos lleva hasta la posicion antes de la posicion donde queremos introducir el elemento
			this->insertarElementoRec(elementoPrimero, elementoAgregar, espaciosAvanzar, posicion);
			length++;
		}


	}
}


void Lista::insertarElementoRec(Elemento * elementoPosicion, Elemento * elementoAgregar, int espaciosAvanzar, int posicion)
{
	if (espaciosAvanzar + 1 == posicion)
	{
		Elemento * auxiliar = elementoPosicion->getElementoSiguiente();   //metodo auxiliar para agregar un elemento en una posicion n
		elementoAgregar->setElementoSiguiente(auxiliar);				//busca la posicion anterior a n de forma recursiva
		elementoPosicion->setElementoSiguiente(elementoAgregar);	//una vez encontrada dicha casilla, se cambian a lo que apuntan los punteros

	}
	else
	{
		insertarElementoRec(elementoPosicion->getElementoSiguiente(), elementoAgregar, espaciosAvanzar + 1, posicion); //se repite el metodo si aun no estamos en la posicion n-1
	}
}

void Lista::eliminarPrimero() //elimina el primer elemento de la lista
{
	Elemento * auxiliar = elementoPrimero;
	if (length == 1)
	{
		elementoPrimero = NULL;
		elementoUltimo = NULL;
	}
	else
	{
		elementoPrimero = auxiliar->getElementoSiguiente();
	}
	delete auxiliar;
	length--;
}

void Lista::eliminarUltimo()  
{
	Elemento * auxiliar = elementoUltimo;   //se elimina el ultimo elemento de la lista
	if (length == 1)
	{
		elementoPrimero = NULL;
		elementoUltimo = NULL;
	}
	else
	{
		eliminarElementoRecSimple(elementoPrimero, auxiliar);
	}
	length--;
}

void Lista::eliminarElementoRecSimple(Elemento * e, Elemento * auxiliar)  //metodo auxilir de eliminarPrimero
{																	//este metodo busca la antepenultima posicion (length -1)
	if (e->getElementoSiguiente() == elementoUltimo)			//y una vez estando alli, la hace el nuevo elementoUltimo, ademas de referenciar el antiguo elementoUltimo
	{
		elementoUltimo = e;
		elementoUltimo->setElementoSiguiente(NULL);
	}
	else
	{
		eliminarElementoRecSimple(e->getElementoSiguiente(), auxiliar);
	}
}

void Lista::eliminarPosicion(int posicion)   //elimina un elemento de cualquier posicion
{
	if (posicion == 0)
	{
		eliminarPrimero();
	}
	else
	{
		if (posicion == length)
		{
			eliminarUltimo();
		}
		else
		{

			int espaciosAvanzar = 0;
			this->eliminarElementoRec(elementoPrimero, espaciosAvanzar, posicion);

		}
	}
	length--;
}

void Lista::eliminarElementoRec(Elemento * elementoPosicion, int espaciosAvanzar, int posicion)	//de forma similar a como se agrego un elemento en la posicion n, este metodo
{																							//busca la posicion n-1 de forma recursiva y una vez hallada desreferencia 
	if (espaciosAvanzar + 1 < posicion)														//el elemento que se quiere eliminar.
	{

		eliminarElementoRec(elementoPosicion->getElementoSiguiente(), espaciosAvanzar + 1, posicion);
	}
	else
	{
		Elemento * auxiliar = elementoPosicion->getElementoSiguiente();
		elementoPosicion->setElementoSiguiente(auxiliar->getElementoSiguiente());
		delete auxiliar;
	}
}

ostream & operator<<(ostream & out, Lista & a) { //sobrecarga del operador <<
	a.imprimir(a.elementoPrimero, out, 0);
	return out;
}

void Lista::imprimir(Elemento * e, ostream & out, int posicion)  //se imprime el primer elemento y asi se continua hacia abajo un elemento por fila.
{
	if (e != NULL)
	{
		e->imprimir(out);
		cout << "       Posicion numero: " << posicion << endl;
		if (e->getElementoSiguiente() != NULL)
		{
			imprimir(e->getElementoSiguiente(), out, posicion +1);
		}
	}
}

Elemento * Lista::getPrimero() //devuelve el primer elemento
{
	return elementoPrimero;
}

Elemento * Lista::getUltimo() //devuelve el ultimo elemento
{
	return elementoUltimo;
}


int Lista::getLength() //devuelve la cantidad de elementos
{
	return length;
}

#include "stdafx.h"
#include "Persona.h"


Persona::Persona(string str, int i)

{
	nombre = str;
	identificacion = i;
}


Persona::~Persona()
{
}

int Persona::getIdentificacion()
{
	return identificacion;
}

string Persona::getNombre()
{
	return nombre;
}





#pragma once
#include <cstdlib>
#include <string>
using std::string;


class Persona
{


public:
	Persona(string, int);
	~Persona();
	int getIdentificacion();
	string getNombre();
	int identificacion;
	string nombre;
};


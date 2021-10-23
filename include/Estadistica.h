#pragma once
#include <string>
#include "Videojuego.h"

using namespace std;

class Estadistica
{
private:
	string nombre;
	string descripcion;

public:
	Estadistica();
	Estadistica(string nombre, string desc);
	string getNombre();
	string getDescripcion();
	~Estadistica();

	//OPERACIONES
	virtual float calcularValor(Videojuego* vj) = 0;
	friend ostream& operator<< (ostream& out, Estadistica* &e);
};
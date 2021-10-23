#ifndef _DTVALORESTADISTICA_H
#define _DTVALORESTADISTICA_H

#include <iostream>
using namespace std;

class DtValorEstadistica{
	
	private:
		// Atributos
		string nombre;
		float valor;

	public:
		// Constructores y Destructores
		DtValorEstadistica(string nombre, float valor);
		~DtValorEstadistica();

		// Getters
		string getNombre();
		float getValor();
};
#endif
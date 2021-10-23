#ifndef _DTINFOSUSC_H
#define _DTINFOSUSC_H

#include "../include/DtCosto.h"
#include <string>
#include <iostream>

using namespace std;

class DtInfoSusc{
	
	private:
		// Atributos
		string nombreVid;
		DtCosto* costo;

	public:
		// Constructores y Destructores
		DtInfoSusc(string nombreVid,
		DtCosto* costo);
		~DtInfoSusc();

		// Getters
		string getNombreVid();
		DtCosto* getCosto();

		friend ostream& operator<< (ostream& out, DtInfoSusc& dtis);
};

#endif
#ifndef _DTCOSTO_H
#define _DTCOSTO_H

#include <iostream>

using namespace std;

class DtCosto{
	
	private:
		// Atributos
		float unMes;
		float tresMeses;
		float unAnio;
		float vitalicia;

	public:
		// Constructores y Destructores
		DtCosto(float unMes, float tresMeses, float unAnio, float vitalicia);
		~DtCosto();

		// Getters
		float getUnMes();
		float getTresMeses();
		float getUnAnio();
		float getVitalicia();

		friend ostream& operator<< (ostream& out, DtCosto& dtc);
};

#endif
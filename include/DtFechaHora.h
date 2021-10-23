#ifndef _DTFECHAHORA_H
#define _DTFECHAHORA_H

#include "TipoValidez.h"
#include <iostream>
#include <time.h>
using namespace std;

class DtFechaHora{

	private:
		// Atributos
		int dia;
		int mes;
		int anio;
		int hora;
		int minuto;

	public:
		// Constructores y Destructores
		DtFechaHora();
		DtFechaHora(int diaN, int mesN,	int anioN, int horaN, int minutoN);
		~DtFechaHora();

		// Getters
		int getDia();
		int getMes();
		int getAnio();
		int getHora();
		int getMinuto();

		friend ostream& operator<< (ostream& out, DtFechaHora& dtfh);
		friend int operator-(DtFechaHora &f1, DtFechaHora &f2);
		friend DtFechaHora* operator+(DtFechaHora &f1, TipoValidez &validez);
};

#endif

#ifndef _DTINFOBASICAPARTIDAINDIVIDUAL_H
#define _DTINFOBASICAPARTIDAINDIVIDUAL_H

#include "../include/DtFechaHora.h"

class DtInfoBasicaPartidaIndividual{

	private:
		// Atributos
		int identificador;
		DtFechaHora* fechaComienzo;
		float duracion;

	public:
		// Constructores y Destructores
		DtInfoBasicaPartidaIndividual(int identificador,
		DtFechaHora* fechaComienzo,
		float duracion);
		~DtInfoBasicaPartidaIndividual();
		// Getters
		int getIdentificador();
		DtFechaHora* getFechaComienzo();
		float getDuracion();
		friend ostream& operator<< (ostream& out, DtInfoBasicaPartidaIndividual& dtibPI);
};
#endif

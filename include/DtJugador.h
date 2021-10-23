#ifndef _DTJUGADOR_H
#define _DTJUGADOR_H

#include <iostream>
#include <string>

using std::string;
using namespace std;

class DtJugador{

	private:
		// Atributos
		string nickname;
		string descripcion;

	public:
		// Constructores y Destructores
		DtJugador(string nickname,
		string descripcion);
		~DtJugador();

		// Getters
		string getNickname();
		string getDescripcion();

		friend ostream& operator<< (ostream& out, DtJugador& dtj);
};
#endif

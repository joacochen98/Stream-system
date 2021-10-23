#ifndef _DTINFOESTADISTICA_H
#define _DTINFOESTADISTICA_H
#include <string>

using std::string;

class DtInfoEstadistica{
	
	private:
		// Atributos
		string nombre;
		string descripcion;

	public:
		// Constructores y Destructores
		DtInfoEstadistica(string nombre,
		string descripcion);
		~DtInfoEstadistica();

		// Getters
		string getNombre();
		string getDescripcion();
};
#endif

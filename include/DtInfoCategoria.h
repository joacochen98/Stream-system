#ifndef _DTINFOCATEGORIA_H
#define _DTINFOCATEGORIA_H
#include <string>


using std::string;

class DtInfoCategoria{

	private:
		// Atributos
		string nombre;
		string descripcion;
		string tipoCategoria;

	public:
		// Constructores y Destructores
		DtInfoCategoria(string nombre,	string descripcion, string tipoCategoria);
		~DtInfoCategoria();

		// Getters
		string getNombre();
		string getDescripcion();
		string getTipoCategoria();
};
#endif
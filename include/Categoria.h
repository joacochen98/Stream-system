#ifndef _Categoria
#define _Categoria

#include <string>
#include <iostream>

using namespace std;

class Categoria {
	
	private:
		string nombre;
		string descripcion;

	public:
		Categoria(string nombre, string descr);
		string getNombre();
		string getDescripcion();

		~Categoria();
		
		friend ostream& operator<< (ostream& out, Categoria& c);
};
#endif
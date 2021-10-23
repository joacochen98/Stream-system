#ifndef _Genero
#define _Genero

#include "../include/Categoria.h"
#include "../include/TipoGenero.h"

using std::string;

class Genero: public Categoria {
	
	private:
		TipoGenero genero;

	public:
		Genero(TipoGenero gen, string nombre, string descr);
		TipoGenero getGenero();
		
		~Genero();	
};
#endif

#ifndef _Plataforma
#define _Plataforma

#include "Categoria.h"
#include "TipoPlataforma.h"

using std::string;

class Plataforma: public Categoria {
	
	private:
		TipoPlataforma plataforma;

	public:
		Plataforma(TipoPlataforma plataf, string nombre, string descr);
		TipoPlataforma getPlataforma();
		~Plataforma();
};
#endif

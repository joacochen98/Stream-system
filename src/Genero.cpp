#include "../include/Genero.h"

Genero::Genero(TipoGenero gen, string nombre, string descr) : Categoria(nombre, descr){
	this->genero = gen;
};

TipoGenero Genero::getGenero() {
	return this->genero;
};

Genero::~Genero() {
};

ostream& operator<< (ostream& out, Genero& g){
	string nombre = g.getNombre();
	string descripcion = g.getDescripcion();
	TipoGenero genero = g.getGenero();

	out << endl;
	out << "Nombre: " << nombre <<  endl;
	out << "Descripcion: " << descripcion <<  endl;
	switch(genero){
		case 0: out << "Genero: accion" <<  endl; break;
		case 1: out << "Genero: aventura" <<  endl; break;
		case 2: out << "Genero: estrategia" <<  endl; break;
		case 3: out << "Genero: deporte" <<  endl; break;
		default: out << "Comando no reconocido" <<  endl; break;
	}
    return out;
};
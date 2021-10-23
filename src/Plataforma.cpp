#include "../include/Plataforma.h"

Plataforma::Plataforma(TipoPlataforma plataf, string nombre, string descr) : Categoria(nombre, descr) {
	this->plataforma = plataf;
};

TipoPlataforma Plataforma::getPlataforma() {
	return this->plataforma;
};

Plataforma::~Plataforma() {

};

ostream& operator<< (ostream& out, Plataforma& p){
	string nombre = p.getNombre();
	string descripcion = p.getDescripcion();
	TipoPlataforma plataforma = p.getPlataforma();
	out << endl;
	out << "Nombre: " << nombre <<  endl;
	out << "Descripcion: " << descripcion <<  endl;
	switch(plataforma){
		case 0: out << "Plataforma: PC" <<  endl; break;
		case 1: out << "Plataforma: Switch" <<  endl; break;
		case 2: out << "Plataforma: PS4" <<  endl; break;
		case 3: out << "Plataforma: PS5" <<  endl; break;
		case 4: out << "Plataforma: Xbox One" <<  endl; break;
		case 5: out << "Plataforma: Xbox X" <<  endl; break;
		default: out << "Comando no reconocido" <<  endl; break;
	}	
    return out;
};
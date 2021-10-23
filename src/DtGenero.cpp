#include "../include/DtGenero.h"
#include <iostream>
using namespace std;

DtGenero::DtGenero(string nombre, string desc, TipoGenero genero) : DtCategoria(nombre, desc) {
	this->genero = genero;
};

DtGenero::~DtGenero() {};

TipoGenero DtGenero::getGenero() {
     return this->genero;
};

ostream& operator<< (ostream& out, set<DtGenero*>& setC) {
	set<DtGenero*>::iterator it;
	string nombre;
	string descripcion;

	for (it = setC.begin(); it != setC.end(); it++) {
		DtGenero* aux = *it;
		out << endl;
		out << "Nombre: " << aux->getNombre() << endl;
		out << "Descripcion: " << aux->getDescripcion() << endl;
	}	
    return out;
};
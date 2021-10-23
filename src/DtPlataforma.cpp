#include "../include/DtPlataforma.h"
#include <iostream>
using namespace std;

DtPlataforma::DtPlataforma(string nombre, string desc, TipoPlataforma plataforma) : DtCategoria(nombre, desc) {
	this->plataforma = plataforma;
};

DtPlataforma::DtPlataforma(Plataforma *plataforma): DtCategoria() {
	this->plataforma = plataforma->getPlataforma();
};

TipoPlataforma DtPlataforma::getPlataforma() {
     return this->plataforma;
};

DtPlataforma::~DtPlataforma() {
};

ostream& operator<< (ostream& out, set<DtPlataforma*>& setC) {
	set<DtPlataforma*>::iterator it;
	string nombre;
	string descripcion;

	for (it = setC.begin(); it != setC.end(); it++) {
		DtPlataforma* aux = *it;
		out << endl;
		out << "Nombre: " << aux->getNombre() << endl;
		out << "Descripcion: " << aux->getDescripcion() << endl;
	}	
    return out;
};
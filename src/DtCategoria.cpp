#include "../include/DtCategoria.h"
#include <iostream>
using namespace std;

DtCategoria::DtCategoria(){

};

DtCategoria::DtCategoria(string nombre, string descripcion) {
	this->nombre = nombre;
	this->descripcion = descripcion;
};

DtCategoria::DtCategoria(Categoria *c) {
	this->nombre = c->getNombre();
	this->descripcion = c->getDescripcion();
};

string DtCategoria::getNombre() {
     return this->nombre;
};

string DtCategoria::getDescripcion() {
    return this->descripcion;
};

DtCategoria::~DtCategoria() {
};

ostream& operator<< (ostream& out, set<DtCategoria*>& setC) {
	set<DtCategoria*>::iterator it;
	string nombre;
	string descripcion;

	for (it = setC.begin(); it != setC.end(); it++) {
		DtCategoria* aux = *it;
		out << endl;
		out << "Nombre: " << aux->getNombre() << endl;
		out << "Descripcion: " << aux->getDescripcion() << endl;
	}	
    return out;
};
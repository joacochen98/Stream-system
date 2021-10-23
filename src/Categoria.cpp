#include "../include/Categoria.h"
#include "../include/Genero.h"
#include "../include/Plataforma.h"

Categoria::Categoria(string nombre, string descr) {
	this->nombre = nombre;
	this->descripcion = descr;
};

string Categoria::getNombre() {
	return this->nombre;
};

string Categoria::getDescripcion() {
	return this->descripcion;
};

Categoria::~Categoria() {

};

/*ostream& operator<< (ostream& out, Categoria* &c){
	if (dynamic_cast<Genero*>(c) != NULL) {
		Genero* g = dynamic_cast<Genero*>(c);
		cout << *g << endl;            
    }
    else {
    	Plataforma* p = dynamic_cast<Plataforma*>(c);
    	cout << *p << endl;
    }
	return out;
};*/

ostream& operator<< (ostream& out, Categoria& c){
	string nombre = c.getNombre();
	string descripcion = c.getDescripcion();
	
	out << endl;
	out << "Nombre: " << nombre <<  endl;
	out << "Descripcion: " << descripcion <<  endl;
	
    return out;
};
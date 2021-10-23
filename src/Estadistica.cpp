#include "../include/Estadistica.h"
#include "../include/CantidadTotalJugadores.h"
#include "../include/TotalHorasJugadas.h"

Estadistica::Estadistica() {
};

Estadistica::Estadistica(string nombre, string desc) {
	this->nombre = nombre;
	this->descripcion = desc;
};

string Estadistica::getNombre() {
	return this->nombre;
};

string Estadistica::getDescripcion() {
	return this->descripcion;
};

Estadistica::~Estadistica() {
};

ostream& operator<< (ostream& out, Estadistica* &e) {
	if (dynamic_cast<CantidadTotalJugadores*>(e) != NULL) {
		CantidadTotalJugadores* ctj = dynamic_cast<CantidadTotalJugadores*>(e);
		cout << *ctj << endl;            
    }
    else {
    	TotalHorasJugadas* thj = dynamic_cast<TotalHorasJugadas*>(e);
    	cout << *thj << endl;
    }
	return out;
};
#include "../include/DtInfoEstadistica.h"
#include <string>

using std::string;

DtInfoEstadistica::DtInfoEstadistica(string nombre, string descripcion){
	this->nombre = nombre;
	this->descripcion = descripcion;
};

DtInfoEstadistica::~DtInfoEstadistica(){};

string DtInfoEstadistica::getNombre(){
	return this->nombre;
};

string DtInfoEstadistica::getDescripcion(){
	return this->descripcion;
};
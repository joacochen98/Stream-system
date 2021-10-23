#include "../include/DtInfoCategoria.h"
#include <string>

using std::string;

DtInfoCategoria::DtInfoCategoria(string nombre, string descripcion, string tipoCategoria){
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->tipoCategoria = tipoCategoria;
};

DtInfoCategoria::~DtInfoCategoria(){};

string DtInfoCategoria::getNombre(){
	return this->nombre;
};

string DtInfoCategoria::getDescripcion(){
	return this->descripcion;
};

string DtInfoCategoria::getTipoCategoria(){
	return this->tipoCategoria;
};
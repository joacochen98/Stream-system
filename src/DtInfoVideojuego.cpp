#include "../include/DtInfoVideojuego.h"
#include <iostream>

using namespace std;

DtInfoVideojuego::DtInfoVideojuego(string nombre, string descripcion) : DtInfoBasicaVideojuego(nombre) {
	this->descripcion = descripcion;
};

string DtInfoVideojuego::getDescripcion() {
	return this->descripcion;
};

DtInfoVideojuego::~DtInfoVideojuego() {
	
};
#include "../include/DtInfoBasicaVideojuego.h"

#include <iostream>
using namespace std;

DtInfoBasicaVideojuego::DtInfoBasicaVideojuego(string nombre){
	this->nombre = nombre;
};

string DtInfoBasicaVideojuego::getNombre() {
	return this->nombre;
};

DtInfoBasicaVideojuego::~DtInfoBasicaVideojuego() {
};
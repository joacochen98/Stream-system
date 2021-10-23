#include "../include/DtValorEstadistica.h"
#include <iostream>
using namespace std;

DtValorEstadistica::DtValorEstadistica(string nombre, float valor) {
	this->nombre = nombre;
	this->valor = valor;
};

float DtValorEstadistica::getValor() {
    return this->valor;
};

string DtValorEstadistica::getNombre() {
    return this->nombre;
};

DtValorEstadistica::~DtValorEstadistica() {
};
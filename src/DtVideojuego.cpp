#include "../include/DtVideojuego.h"
#include <iostream>
using namespace std;

DtVideojuego::DtVideojuego(string nombre, string desc, DtCosto* costo) : DtInfoVideojuego(nombre,desc){
	this->costo = costo;
};

DtVideojuego::~DtVideojuego() {
    delete costo;
};

string DtVideojuego::getNombre() {
     return this->nombre;
};

string DtVideojuego::getDescripcion() {
    return this->descripcion;
};

DtCosto* DtVideojuego::getCostos() {
    return this->costo;
};

float DtVideojuego::getPuntajePromedio() {
    return this->puntajePromedio;
};

float DtVideojuego::getTotalHorasJugadas() {
    return this->totalHorasJugadas;
};

int DtVideojuego::getCantidadPartidasActivas(){
    return this->cantidadPartidasActivas;
};
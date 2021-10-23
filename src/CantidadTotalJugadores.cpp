#include "../include/CantidadTotalJugadores.h"

CantidadTotalJugadores::CantidadTotalJugadores(string nombre, string descripcion) : Estadistica(nombre, descripcion)
{
}

CantidadTotalJugadores::~CantidadTotalJugadores()
{
}

float CantidadTotalJugadores::calcularValor(Videojuego* vj) {	
	float res = vj->getHistorialSuscripciones().size();
	return res;
};

void CantidadTotalJugadores::seleccionarVideojuego(Videojuego* videojuego) {
	this->videojuegoSeleccionado = videojuego;
};

ostream& operator<< (ostream& out, CantidadTotalJugadores& ctj){
	string nombre = ctj.getNombre();
	string descripcion = ctj.getDescripcion();

	out << endl;
	out << "Nombre: " << nombre <<  endl;
	out << "Descripcion: " << descripcion << endl;

    return out;
};
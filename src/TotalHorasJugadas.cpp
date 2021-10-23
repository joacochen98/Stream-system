#include "../include/TotalHorasJugadas.h"

TotalHorasJugadas::TotalHorasJugadas(string nombre, string descripcion) : Estadistica(nombre, descripcion) {
};

TotalHorasJugadas::~TotalHorasJugadas() {
};

float TotalHorasJugadas::calcularValor(Videojuego* vj) {
	float val = 0;
	map<int, Partida*> aux = vj->getPartidas();
	map<int, Partida*>::iterator it;

	for (it = aux.begin(); it != aux.end(); it++) {
		Partida* p = it->second;
		val = p->darTotalHorasParticipantes() + val;	
	};	
	return val;
};

void TotalHorasJugadas::seleccionarVideojuego(Videojuego* videojuego) {
	this->videojuegoSeleccionado = videojuego;
};

ostream& operator<< (ostream& out, TotalHorasJugadas& thj){
	string nombre = thj.getNombre();
	string descripcion = thj.getDescripcion();
	out << endl;
	out << "Nombre: " << nombre <<  endl;
	out << "Descripcion: " << descripcion << endl;
    return out;
};
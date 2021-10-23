#include "../include/DtPartidaIndividual.h"
#include "../include/PartidaIndividual.h"
#include "../include/DtPartida.h"

DtPartidaIndividual::DtPartidaIndividual(int identificador, DtFechaHora* fechacomienzo, float duracion, bool continua, string nombreVj): DtPartida( identificador, fechacomienzo, duracion, nombreVj) {
    this->continuaPartidaAnterior = continua;
};

bool  DtPartidaIndividual::getContinuaPartida() {
    return this->continuaPartidaAnterior;
};

DtPartidaIndividual::~DtPartidaIndividual() {};

ostream& operator<< (ostream& out, DtPartidaIndividual& pi) {
	int id = pi.getIdentificador();
	string nombre = pi.getNombreVideojuego();
	DtFechaHora* fecha = pi.getFechaComienzo();
 	out << endl;
 	out << "Tipo partida: Individual" << endl;
 	out << "El id de la partida es: " << id << endl;
 	out << "Partida perteneciente al juego: " << nombre << endl;
 	out << "La fecha de comienzo de la partida es: " << *fecha;
 	if (pi.getContinuaPartida())
     	out << "Continuacion de una partida anterior: " << "Si" << "\n";
     else
     	out << "Continuacion de una partida anterior: " << "No" << "\n";
  out << endl;

  return out;
 };
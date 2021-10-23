#include "../include/DtPartida.h"
#include "../include/DtPartidaIndividual.h"
#include "../include/DtPartidaMultijugador.h"
#include <iostream>
using namespace std;

DtPartida::DtPartida(){
};

DtPartida::DtPartida(int identificador, DtFechaHora* fechacomienzo, float duracion, string nombreVj) {
	this->idPartida = identificador;
	this->fechaComienzo = fechacomienzo;
	this->fechaFinalizacion = NULL;
	this->duracion = duracion;
	this->finalizada = false;
	this->nombreVj = nombreVj;
};

DtPartida::~DtPartida() {
	delete fechaComienzo;
	delete fechaFinalizacion;
};

DtFechaHora* DtPartida::getFechaComienzo() {
     return this->fechaComienzo;
};

DtFechaHora* DtPartida::getFechaFinalizacion() {
     return this->fechaFinalizacion;
};

float DtPartida::getDuracion() {
    return this->duracion;
};

bool DtPartida::getFinalizada() {
    return this->finalizada;
};

int DtPartida::getIdentificador() {
    return this->idPartida;
};

string DtPartida::getNombreVideojuego() {
	return this->nombreVj;
};

ostream& operator<< (ostream& out, DtPartida* &p) {
  if (dynamic_cast<DtPartidaIndividual*>(p) != NULL) {
    DtPartidaIndividual* ndtp = dynamic_cast<DtPartidaIndividual*>(p);
 		cout << *ndtp;
  }
  else {
    DtPartidaMultijugador* ndtp = dynamic_cast<DtPartidaMultijugador*>(p);
    cout << *ndtp;
  }
  return out;
};
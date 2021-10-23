#include "../include/Partida.h"
#include "../include/PartidaIndividual.h"
#include "../include/PartidaMultijugador.h"
#include "../include/FechaHoraSistema.h"

//CONSTRUCTOR
Partida::Partida() {
};

Partida::Partida(int idPartida, DtFechaHora* fechaComienzo, Videojuego* videojuego, bool finalizada, string nicknameJugadorInicio) {
	this->idPartida = idPartida;
	this->fechaComienzo = fechaComienzo;
	this->videojuego = videojuego;
	this->finalizada = finalizada;
	this->nicknameJugadorInicio = nicknameJugadorInicio;
	this->fechaFinalizacion = NULL;
};

//SETTERS - GETTERS
void Partida::setFinalizada(bool finalizada) {
	this->finalizada = finalizada;
};

void Partida::setFechaFinalizacion(DtFechaHora* fechaFinalizacion) {
	this->fechaFinalizacion = fechaFinalizacion;
};

void Partida::setDuracion(int duracion) {
	this->duracion = duracion;
};

int Partida::getIdPartida() {
	return this->idPartida;
};

bool Partida::getFinalizada() {
	return this->finalizada;
};

DtFechaHora* Partida::getFechaComienzo() {
	return this->fechaComienzo;
};

DtFechaHora* Partida::getFechaFinalizacion() {
	return this->fechaFinalizacion;
};

float Partida::getDuracion() {
	float res;
	if (finalizada){
		int horas = fechaFinalizacion->getHora() - fechaComienzo->getHora();
    	int minutos = fechaFinalizacion->getMinuto() - fechaComienzo->getMinuto();
		res = horas * 60 + minutos;
	}
	else{
		FechaHoraSistema* fhs = FechaHoraSistema::getInstancia();
		DtFechaHora* fechaSistema = fhs->getFechaHoraSistema();
		int horas = fechaSistema->getHora() - fechaComienzo->getHora();
    	int minutos = fechaSistema->getMinuto() - fechaComienzo->getMinuto();
		res = horas * 60 + minutos;
		delete fechaSistema;
	}
	return res;
};

Videojuego* Partida::getVideojuego() {
	return this->videojuego;
};

string Partida::getNicknameJugadorInicio() {
	return this->nicknameJugadorInicio;
};

//DESTRUCTOR
Partida::~Partida() {
	if(fechaComienzo != NULL) delete fechaComienzo;
	if(finalizada) delete fechaFinalizacion;
};

ostream& operator<< (ostream& out, Partida* &p){
	if (dynamic_cast<PartidaIndividual*>(p) != NULL) {
		PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(p);
		cout << *pi << endl;            
    }
    else {
    	PartidaMultijugador* pm = dynamic_cast<PartidaMultijugador*>(p);
    	cout << *pm << endl;
    }
	return out;
};
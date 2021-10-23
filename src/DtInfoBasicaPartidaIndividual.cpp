#include "../include/DtInfoBasicaPartidaIndividual.h"

DtInfoBasicaPartidaIndividual::DtInfoBasicaPartidaIndividual(int identificador,
		DtFechaHora* fechacomienzo,
		float duracion){
	this->identificador = identificador;
	this->fechaComienzo = fechacomienzo;
	this->duracion = duracion;
};

DtInfoBasicaPartidaIndividual::~DtInfoBasicaPartidaIndividual(){
	delete fechaComienzo;
};

int DtInfoBasicaPartidaIndividual::getIdentificador(){
	return this->identificador;
};

DtFechaHora* DtInfoBasicaPartidaIndividual::getFechaComienzo(){
	return this->fechaComienzo;
};

float DtInfoBasicaPartidaIndividual::getDuracion(){
	return this->duracion;
};

ostream& operator<< (ostream& out, DtInfoBasicaPartidaIndividual& dtibPI){
	int id = dtibPI.getIdentificador();
	DtFechaHora* fechaComienzo = dtibPI.getFechaComienzo();
	int duracion = dtibPI.getDuracion();

	out << "Identificador: "<< id << endl;
	out << "Fecha de comienzo: "<< *fechaComienzo;
	out << "Duracion: "<< duracion << endl;
	return out;
};
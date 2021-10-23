#include "../include/DtCosto.h"

DtCosto::DtCosto(float unMes, float tresMeses, float unAnio, float vitalicia){
	this->unMes = unMes;
	this->tresMeses = tresMeses;
	this->unAnio = unAnio;
	this->vitalicia = vitalicia;
};

DtCosto::~DtCosto(){};

float DtCosto::getUnMes(){
	return this->unMes;
};

float DtCosto::getTresMeses(){
	return this->tresMeses;
};

float DtCosto::getUnAnio(){
	return this->unAnio;
};

float DtCosto::getVitalicia(){
	return this->vitalicia;
};

ostream& operator<< (ostream& out, DtCosto& dtc){
	float unMes = dtc.getUnMes();
	float tresMeses = dtc.getTresMeses();
	float unAnio = dtc.getUnAnio();
	float vitalicia = dtc.getVitalicia();

	out << endl;
	out << "Costo mensual: " << unMes <<  endl;
	out << "Costo trimestral: " << tresMeses <<  endl;
	out << "Costo anual: " << unAnio <<  endl;
	out << "Costo vitalicia: " << vitalicia <<  endl;
	return out;
};
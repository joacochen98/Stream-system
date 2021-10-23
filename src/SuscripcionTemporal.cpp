#include "../include/SuscripcionTemporal.h"
#include "../include/FechaHoraSistema.h"
#include <iostream>

SuscripcionTemporal::SuscripcionTemporal(float costo, DtFechaHora* fechaPago, TipoPago metodoPago, TipoValidez validez, bool cancelada): Suscripcion(costo, fechaPago, metodoPago){
			this->validez = validez;
			this->cancelada = cancelada;
			DtFechaHora* fechaFinalizacion = *fechaPago + validez;
			this->fechaFinalizacion = fechaFinalizacion; ;
};

SuscripcionTemporal::~SuscripcionTemporal(){
	delete this->fechaFinalizacion;
};

TipoValidez SuscripcionTemporal::getValidez(){
	return this->validez;
};

bool SuscripcionTemporal::getCancelada(){
	return this->cancelada;
};

DtFechaHora* SuscripcionTemporal::getFechaFinalizacion(){
	return this->fechaFinalizacion;
};

void SuscripcionTemporal::setValidez(TipoValidez validez){

};

void SuscripcionTemporal::setCancelada(bool cancelada){

};

void SuscripcionTemporal::setFechaFinalizacion(){

};

bool SuscripcionTemporal::cancelarSuscripcionTemporal() {
	this->setFechaFinalizacion();
	this->cancelada = true;
	return true;
};

ostream& operator<< (ostream& out, SuscripcionTemporal& st) {
	float costo = st.getCosto();
	DtFechaHora* fechaPago = st.getFechaPago();
	TipoPago metodoPago = st.getMetodoPago();
	TipoValidez validez = st.getValidez();
	bool cancelada = st.getCancelada();
	DtFechaHora* fechaFinalizacion = st.getFechaFinalizacion();
	
	int dia, mes, anio, hora, minutos, dia2, mes2, anio2, hora2, minutos2;
	dia = fechaPago->getDia(); 
	mes = fechaPago->getMes(); 
	anio = fechaPago->getAnio(); 
	hora = fechaPago->getHora(); 
	minutos = fechaPago->getMinuto();
	dia2 = fechaFinalizacion->getDia(); 
	mes2 = fechaFinalizacion->getMes(); 
	anio2 = fechaFinalizacion->getAnio(); 
	hora2 = fechaFinalizacion->getHora(); 
	minutos2 = fechaFinalizacion->getMinuto();

	string stringPago;
	switch (metodoPago){
		case tarjeta: stringPago = "tarjeta"; break;
		case PayPal: stringPago = "PayPal"; break;
		default: cout << "error"; break;
	}
	
	string stringValidez;
	switch (validez){
		case unMes: stringValidez = "un mes"; break;
		case tresMeses: stringValidez = "tres meses"; break;
		case unAnio: stringValidez = "un anio"; break;
		default: cout << "error"; break;
	}

	out << endl;
	out << "Suscripcion temporal creada:" << endl;
	out << "Costo: " << costo << endl;
	out << "Fecha pago: " << dia << "/" << mes << "/" << anio << ", " << hora << ":" << minutos << endl;
	out << "Metodo pago: " << stringPago << endl;
	out << "Validez: " << stringValidez << endl;
	out << "Cancelada: ";
	if (cancelada) 
		out << "si" << endl;
	else
		out << "no" << endl;
		
	out << "Fecha Finalizacion: " << dia2 << "/" << mes2 << "/" << anio2 << ", " << hora2 << ":" << minutos2 << endl;
	
    return out;
};
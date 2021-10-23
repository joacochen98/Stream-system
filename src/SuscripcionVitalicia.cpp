#include "../include/SuscripcionVitalicia.h"

SuscripcionVitalicia::SuscripcionVitalicia(float costo, DtFechaHora* fechaPago, TipoPago metodoPago): Suscripcion(costo, fechaPago, metodoPago){
};

SuscripcionVitalicia::~SuscripcionVitalicia(){
};

bool SuscripcionVitalicia::cancelarSuscripcionTemporal() {
	return false;
};

ostream& operator<< (ostream& out, SuscripcionVitalicia& sv) {
	float costo = sv.getCosto();
	DtFechaHora* fechaPago = sv.getFechaPago();
	TipoPago metodoPago = sv.getMetodoPago();
	
	int dia, mes, anio, hora, minutos;
	dia = fechaPago->getDia(); 
	mes = fechaPago->getMes(); 
	anio = fechaPago->getAnio(); 
	hora = fechaPago->getHora(); 
	minutos = fechaPago->getMinuto();

	string stringPago;
	switch (metodoPago){
		case tarjeta: stringPago = "tarjeta"; break;
		case PayPal: stringPago = "PayPal"; break;
		default: cout << "error"; break;
	}

	out << endl;
	out << "Suscripcion vitalicia creada:" << endl;
	out << "Costo: " << costo << endl;
	out << "Fecha pago: " << dia << "/" << mes << "/" << anio << ", " << hora << ":" << minutos << endl;
	out << "Metodo pago: " << stringPago << endl;	
	out << "Es vitalicia" << endl;
	
    return out;
};
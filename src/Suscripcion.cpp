#include "../include/Suscripcion.h"
#include "../include/SuscripcionTemporal.h"
#include "../include/SuscripcionVitalicia.h"

Suscripcion::Suscripcion(float costo, DtFechaHora* fechaPago, TipoPago metodoPago){
    this->costo = costo;
    this->fechaPago = fechaPago;
    this->metodoPago = metodoPago;
};

Suscripcion::~Suscripcion(){
    delete this->fechaPago;
};

float Suscripcion::getCosto(){
    return this->costo;
};

DtFechaHora* Suscripcion::getFechaPago(){
    return this->fechaPago;
};

TipoPago Suscripcion::getMetodoPago(){
    return this->metodoPago;
};

ostream& operator<< (ostream& out, Suscripcion* &s) {
	if (dynamic_cast<SuscripcionTemporal*>(s) != NULL) {
		SuscripcionTemporal* st = dynamic_cast<SuscripcionTemporal*>(s);
		cout << *st << endl;            
    }
    else {
    	SuscripcionVitalicia* sv = dynamic_cast<SuscripcionVitalicia*>(s);
    	cout << *sv << endl;
    }
	return out;
};
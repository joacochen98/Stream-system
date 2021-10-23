#ifndef _SUSCRIPCION_
#define _SUSCRIPCION_

#include "DtFechaHora.h"
#include "TipoPago.h"
#include <iostream>

using namespace std;

class Suscripcion
{
private:
	float costo;
	DtFechaHora* fechaPago;
	TipoPago metodoPago;

public:
	Suscripcion(float costo, DtFechaHora* fechaPago, TipoPago metodoPago);
	virtual ~Suscripcion();
	float getCosto();
	DtFechaHora* getFechaPago();
	TipoPago getMetodoPago();
	virtual bool cancelarSuscripcionTemporal() = 0;
};

ostream& operator<< (ostream& out, Suscripcion* &s);

#endif
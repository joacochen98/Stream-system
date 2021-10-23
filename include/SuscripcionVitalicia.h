#ifndef _SUSCRIPCION_VITALICIA_H
#define _SUSCRIPCION_VITALICIA_H

#include "../include/Suscripcion.h"

class SuscripcionVitalicia: public Suscripcion
{
private:


public:
	SuscripcionVitalicia(float costo, DtFechaHora* fechaPago, TipoPago metodoPago);
	~SuscripcionVitalicia();
	bool cancelarSuscripcionTemporal();
	friend ostream& operator<< (ostream& out, SuscripcionVitalicia& sv);
};

#endif

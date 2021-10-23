#ifndef _SUSCRIPCION_TEMPORAL_H
#define _SUSCRIPCION_TEMPORAL_H

#include "../include/Suscripcion.h"
#include "../include/TipoValidez.h"
#include "../include/DtFechaHora.h"

class SuscripcionTemporal: public Suscripcion
{
private:
	TipoValidez validez;
	bool cancelada;
	DtFechaHora* fechaFinalizacion;

public:
	SuscripcionTemporal(float costo, DtFechaHora* fechaPago, TipoPago metodoPago, TipoValidez validez, bool cancelada);
	~SuscripcionTemporal();

	TipoValidez getValidez();
	bool getCancelada();
	DtFechaHora* getFechaFinalizacion();

	void setValidez(TipoValidez validez);
	void setCancelada(bool cancelada);
	void setFechaFinalizacion();
	//OPERACIONES
	bool cancelarSuscripcionTemporal();
	friend ostream& operator<< (ostream& out, SuscripcionTemporal& st);
};

#endif

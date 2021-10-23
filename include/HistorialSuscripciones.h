#ifndef _HISTORIAL_SUSCRIPCIONES_H
#define _HISTORIAL_SUSCRIPCIONES_H

#include "../include/Suscripcion.h"
#include "../include/DtInfoSusc.h"
#include "../include/TipoSuscripcion.h"
#include "../include/TipoPago.h"
#include "../include/DtJugador.h"

#include <set>
#include <string>
using namespace std;

class Videojuego;
class Jugador;

class HistorialSuscripciones
{
private:
	//PSEUDOATRIBUTOS (LINKS)
	Jugador* jugadorHistorial;				// jugador al que corresponde el historial
	Videojuego* videojuegoHistorial;		// videojuego al que corresponde el historial

	Suscripcion* suscripcionActiva;			// suscripcion con el rol Activa
	set<Suscripcion*> suscripciones;		// TODAS las suscripciones (contiene a suscripcionActiva si existe)

public:
	HistorialSuscripciones(Jugador* jugador, Videojuego* videojuego);
	~HistorialSuscripciones();

	void setJugadorHistorial(Jugador* jugador);
	set<Suscripcion*> getSuscripciones();
	void setSuscripcionActiva(Suscripcion* suscripcion);	
	Suscripcion* getSuscripcionActiva();
	Videojuego* getVideojuegoHistorial();
	Jugador* getJugadorHistorial();

	//OPERACIONES	
	bool tieneSuscripcionActiva();
	DtInfoSusc* pedirDatos();
	void cancelarSuscripcion();
	void cancelarSuscripcionActiva();
	void confirmarSuscripcion(TipoSuscripcion tipoSusc,	DtFechaHora* fechaPago, TipoPago pago, float costoDeTipoSusc);
	bool esVitalicia(TipoSuscripcion tipoSusc);
	string obtenerNombreVideojuego();
	DtJugador* obtenerInfoJugador();
	void agregarSuscripcion(Suscripcion* suscripcion);
	void borrarHistorial();
	friend ostream& operator<< (ostream& out, HistorialSuscripciones& hs);
};

#include "Jugador.h"
#include "../include/Videojuego.h"

#endif
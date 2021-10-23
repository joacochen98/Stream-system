#include "../include/HistorialSuscripciones.h"
#include "../include/SuscripcionTemporal.h"
#include "../include/SuscripcionVitalicia.h"

HistorialSuscripciones::HistorialSuscripciones(Jugador* jugador, Videojuego* videojuego) {
	this->videojuegoHistorial = videojuego;
	this->jugadorHistorial = jugador;
	videojuego->agregarHistorialSuscripciones(this);
};

HistorialSuscripciones::~HistorialSuscripciones() {
	set<Suscripcion*>::iterator it;
	for (it = suscripciones.begin(); it != suscripciones.end(); it++) delete *it;
};

Videojuego* HistorialSuscripciones::getVideojuegoHistorial() {
	return this->videojuegoHistorial;
};

Jugador* HistorialSuscripciones::getJugadorHistorial() {
	return this->jugadorHistorial;
};

void HistorialSuscripciones::setJugadorHistorial(Jugador* jugador) {
	this->jugadorHistorial = jugador;
};

set<Suscripcion*> HistorialSuscripciones::getSuscripciones() {
	return this->suscripciones;
};

void HistorialSuscripciones::setSuscripcionActiva(Suscripcion* suscripcion) {
	this->suscripcionActiva = suscripcion;
};

//OPERACIONES

Suscripcion* HistorialSuscripciones::getSuscripcionActiva() {
	return this->suscripcionActiva;
};

bool HistorialSuscripciones::tieneSuscripcionActiva() {
	return this->suscripcionActiva != NULL;
};

DtInfoSusc* HistorialSuscripciones::pedirDatos() {	
	string nombreVid = this->videojuegoHistorial->getNombre();
	DtCosto* costo = this->videojuegoHistorial->getCosto();	
	DtInfoSusc* res = new DtInfoSusc(nombreVid, costo);
	return res;
};

void HistorialSuscripciones::cancelarSuscripcion() {
	bool fueCancelada = this->suscripcionActiva->cancelarSuscripcionTemporal();
	if (fueCancelada) this->cancelarSuscripcionActiva();	
};

void HistorialSuscripciones::cancelarSuscripcionActiva() {
	this->suscripcionActiva = NULL;
};

void HistorialSuscripciones::confirmarSuscripcion(TipoSuscripcion tipoSusc,	DtFechaHora* fechaPago, TipoPago pago, float costoDeTipoSusc){
	bool esVit = esVitalicia(tipoSusc);
	Suscripcion* nuevaSuscripcion = NULL;
	if (!esVit){
		TipoValidez validez;
		switch(tipoSusc){
			case TemporalUnMes: validez = unMes; break;
			case TemporalTresMeses: validez = tresMeses; break;
			case TemporalUnAnio: validez = unAnio; break;
			default: "tipoSusc no valido"; break;
		}	
		SuscripcionTemporal* nuevaSuscripcionTemp = new SuscripcionTemporal(costoDeTipoSusc, fechaPago, pago, validez, false);
		this->suscripciones.insert(nuevaSuscripcionTemp);
		this->suscripcionActiva = nuevaSuscripcionTemp;
	}
	else{
		SuscripcionVitalicia* nuevaSuscripcionVit = new SuscripcionVitalicia(costoDeTipoSusc, fechaPago, pago);
		this->suscripciones.insert(nuevaSuscripcionVit);
		this->suscripcionActiva = nuevaSuscripcionVit;
	}
};

bool HistorialSuscripciones::esVitalicia(TipoSuscripcion tipoSusc) {
	return tipoSusc == Vitalicia;
};

string HistorialSuscripciones::obtenerNombreVideojuego() {
	string nombre = this->videojuegoHistorial->getNombre();
	return nombre;
};

DtJugador* HistorialSuscripciones::obtenerInfoJugador() {
	string nickname = this->jugadorHistorial->getNickname();
	string descripcion = this->jugadorHistorial->getDescripcion();
	DtJugador *res = new DtJugador(nickname, descripcion);
	return res;
};

void HistorialSuscripciones::agregarSuscripcion(Suscripcion* suscripcion){
	this->suscripciones.insert(suscripcion);
};
void HistorialSuscripciones::borrarHistorial() {
	this->jugadorHistorial->quitarHistorialSuscripciones(this->videojuegoHistorial->getNombre());
};

ostream& operator<< (ostream& out, HistorialSuscripciones& hs){
	string nombreJ = hs.jugadorHistorial->getNickname();
	string nombreV = hs.videojuegoHistorial->getNombre();
	out << endl;
	out << "Se creo el historial de suscripciones para el par (" << nombreJ << ", " << nombreV << ")" << endl;

	set<Suscripcion*>::iterator it = hs.suscripciones.begin();
	bool esVacioHistorial = it == hs.suscripciones.end();
	if (esVacioHistorial)
		out << "El historial esta vacio" << endl;
	else{
		out << "Se le agregaron las siguientes suscripciones: " << endl;
		for (it; it != hs.suscripciones.end(); it++){
			Suscripcion* aImprimir = *it;
			out << aImprimir;
			if (aImprimir == hs.suscripcionActiva)
				out << "Esa es la suscripcion activa" << endl;
		}
	}
    return out;
};
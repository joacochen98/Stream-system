#include "../include/Videojuego.h"
#include "../include/Fabrica.h"
#include "../include/HistorialSuscripciones.h"
#include "../include/FechaHoraSistema.h"
#include "../include/DtFechaHora.h"
#include "../include/Partida.h"

using std::string;

Videojuego::Videojuego(string nombre, string descripcion, DtCosto* costo) {
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->costo = costo;
	this->cantidadPartidasActivas = 0;
};

//SETTERS - GETTERS
void Videojuego::setNombre(string nombre) {
	this->nombre = nombre;

};
void Videojuego::setDescripcion(string descripcion) {
	this->descripcion = descripcion;

};
void Videojuego::setCosto(DtCosto* costo) {
	this->costo = costo;

};
void Videojuego::setPuntajePromedio(float puntajePromedio) {

};
void Videojuego::setTotalHorasJugadas(float totalHorasJugadas) {

};
void Videojuego::setCantidadPartidasActivas(int cantidadPartidasActivas) {

};

void Videojuego::setGenPlatCat(set<Genero*> g, set<Plataforma*> p, set<Categoria*> c) {
	this->generos = g;
	this->plataformas = p;
	this->categorias = c;
};

string Videojuego::getNombre() {
	return this->nombre;
};

string Videojuego::getDescripcion() {
	return this->descripcion;
};

DtCosto* Videojuego::getCosto() {
	return this->costo;
};

float Videojuego::getPuntajePromedio() {
	if (this->puntajes.size() == 0) return 0;	
	else {
		int sumaPuntajes = 0;
		set<Puntaje *> puntajesVideojuego = this->puntajes;
		for (set<Puntaje *>::iterator it = puntajesVideojuego.begin(); it != puntajesVideojuego.end(); it++)
		{
			Puntaje *puntaje = *it;
			sumaPuntajes = sumaPuntajes + puntaje->getPuntaje();
		};
		return (float)sumaPuntajes / puntajesVideojuego.size();
	}
};

float Videojuego::getTotalHorasJugadas() {
	return 0;
};

int Videojuego::getCantidadPartidasActivas() {
	return 0;
};

set<Categoria*> Videojuego::getCategorias() {
	return this->categorias;
};

set<Genero *> Videojuego::getGeneros(){
	return this->generos;
};

set<Plataforma *> Videojuego::getPlataformas() {
	return this->plataformas;
};
set<Puntaje *> Videojuego::getPuntajes() {
	return this->puntajes;
};

map<string, HistorialSuscripciones*> Videojuego::getHistorialSuscripciones(){
	return this->historialSuscripciones;
};

map<int, Partida*> Videojuego::getPartidas() {
	return this->partida;
};

Videojuego:: ~Videojuego(){
	if (this->costo != NULL){
		delete this->costo;
	}

	set<Puntaje*>::iterator it;
	for (it = puntajes.begin(); it != puntajes.end(); it++)
		delete *it;

	map<string, HistorialSuscripciones*>:: iterator it2;
	for (it2 = historialSuscripciones.begin(); it2 != historialSuscripciones.end(); it2++)
		delete it2->second;

	map<int, Partida*>::iterator it3;
	for (it3 = partida.begin(); it3 != partida.end(); it3++)
		delete it3->second;
 };

bool Videojuego::usuarioTieneSuscActiva() {
	bool res;
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion(); 
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	string nombreJugador = jugadorSesion->getNickname();
	if (this->historialSuscripciones.find(nombreJugador) == this->historialSuscripciones.end()) {
		return false;
	};
	map<string, HistorialSuscripciones*> historialesDelVideojuego = this->historialSuscripciones;
	map<string, HistorialSuscripciones*>::iterator it;
	it = historialesDelVideojuego.find(nombreJugador); 	
	bool tieneHistorial = it != historialesDelVideojuego.end(); 
	if (tieneHistorial){
		res = it->second->tieneSuscripcionActiva();
	}
	else{
		res = false;
	}
	return res;
 };

void Videojuego::cancelarSuscripcion() {
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion();
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	string nombreJugador = jugadorSesion->getNickname();
	
	map<string, HistorialSuscripciones*>::iterator it = this->historialSuscripciones.find(nombreJugador);
	it->second->cancelarSuscripcion();

 };

void Videojuego::confirmarSuscripcion(TipoSuscripcion tipoSusc, TipoPago pago) {
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion(); 
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	string nombreJugador = jugadorSesion->getNickname();

	map<string, HistorialSuscripciones*>::iterator it = this->historialSuscripciones.find(nombreJugador);	
	bool existe = it != this->historialSuscripciones.end();
	
	if(!existe){
		//cout << "Crea un historial para ese videojuego" << endl << endl;
		HistorialSuscripciones* hsNuevo = new HistorialSuscripciones(jugadorSesion, this);
		this->historialSuscripciones.insert({nombreJugador, hsNuevo});
		jugadorSesion->agregarHistorialSuscripciones(this->nombre, hsNuevo); 
		bool encontro = this->historialSuscripciones.find(nombreJugador) != this->historialSuscripciones.end();
		string s;
		if (encontro) s = "si";		
		else s = "no";		
		//cout << "El historial creado " << s << " fue agregado a los historiales del videojuego" << endl << endl;
	}
	else cout << "Ya tenia un historial para ese videojuego" << endl << endl;	
	float costoDeTipoSusc = this->getCostoDeTipoSusc(tipoSusc);
	FechaHoraSistema* fhs = FechaHoraSistema::getInstancia();
	DtFechaHora* fechaPago = fhs->getFechaHoraSistema();
	this->historialSuscripciones.find(nombreJugador)->second->confirmarSuscripcion(tipoSusc, fechaPago, pago, costoDeTipoSusc);
 };

set<DtJugador*> Videojuego::obtenerNicknamesJugadores() {
	set<DtJugador*> res;
	map<string, HistorialSuscripciones*>::iterator it;
	for (it = this->historialSuscripciones.begin(); it != this->historialSuscripciones.end(); it++) {
		HistorialSuscripciones* historial = it->second;
		if (historial->tieneSuscripcionActiva()){
			DtJugador* infoJugador = historial->obtenerInfoJugador();
			res.insert(infoJugador);
		}
	}
	return res;
 };

void Videojuego::sumarCantPartidas() {
	this->cantidadPartidasActivas++;
};

void Videojuego::restarCantPartidas() {
	this->cantidadPartidasActivas--;
};

bool Videojuego::tienePartidasAct() {
	return this->cantidadPartidasActivas>0;
 };

void Videojuego::eliminar() {

 };

float Videojuego::getCostoDeTipoSusc(TipoSuscripcion tipoSusc) {
	float res;
	switch(tipoSusc){
		case TemporalUnMes: res = this->costo->getUnMes(); break;
		case TemporalTresMeses: res = this->costo->getTresMeses(); break;
		case TemporalUnAnio: res = this->costo->getUnAnio(); break;
		case Vitalicia: res = this->costo->getVitalicia(); break;
		default: cout << "valor de tipoSusc no valido" << endl; break;
	}
	return res;
 };

void Videojuego::agregarPuntaje(Puntaje* newPuntaje) {
	this->puntajes.insert(newPuntaje);
};

ostream& operator<< (ostream& out, Videojuego &v){
	string nombre = v.nombre;
	string descripcion = v.descripcion;
	DtCosto* costo = v.costo;
	int cantPartidas = v.cantidadPartidasActivas;
	out << endl;
	out << "Videojuego creado:" << endl;
	out << "Nombre: " << nombre <<  endl;
	out << "Descripcion: " << descripcion << endl;
	out << "Costos por tipo de suscripcion: " << *costo;
	out << "Cantidad de partidas: " << cantPartidas <<  endl;
	out << endl;
    return out;
};

void Videojuego::agregarHistorialSuscripciones(HistorialSuscripciones * hs) {
	this->historialSuscripciones.insert({hs->getJugadorHistorial()->getNickname(), hs});
}

void Videojuego::EliminarHistorialSuscripciones() {
	map<string, HistorialSuscripciones*>::iterator it2;
	for (it2 = historialSuscripciones.begin(); it2 != historialSuscripciones.end(); it2++){
			it2->second->borrarHistorial(); 
	}
}
void Videojuego::EliminarPuntajes() {
}

void Videojuego::EliminarPartidas() {
	map<int, Partida*>::iterator it4;
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	for (it4 = partida.begin(); it4 != partida.end(); it4++){
		string nombreJugadorPartida = it4->second->getNicknameJugadorInicio();
		Jugador* JugadorPartida = iU->buscarJugador(nombreJugadorPartida);
		it4->second->borrarPartida(JugadorPartida);
	};
};

void Videojuego::agregarPartida(Partida* p){
	this->partida.insert({p->getIdPartida(), p});
};
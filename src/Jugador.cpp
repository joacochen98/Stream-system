#include "../include/Jugador.h"

Jugador::Jugador(){
};

Jugador::Jugador(string email, string contrasenia, string nickname, string descripcion) : Usuario(email, contrasenia)
{
	this->nickname = nickname;
	this->descripcion = descripcion;
};

Jugador::~Jugador() {
};

string Jugador::getNickname(){
	return this->nickname;
};

string Jugador::getDescripcion(){
	return this->descripcion;
};

map<string, HistorialSuscripciones*> Jugador::getHistoriales_de_suscripciones(){
	return this->historiales_de_suscripciones;
};

map<int, Partida*> Jugador::getPartidasIniciadas(){
	return this->partidasIniciadas;
};

//OPERACIONES
set<DtInfoSusc*> Jugador::listarVidConSuscActivas() {
	set<DtInfoSusc*> res;
	map<string, HistorialSuscripciones*>::iterator it;
	for (it = this->historiales_de_suscripciones.begin(); it != this->historiales_de_suscripciones.end(); it++) {
		bool tieneActiva = it->second->tieneSuscripcionActiva();
		if (tieneActiva) {
			cout << "Tiene suscripcion activa para " << it->second->getVideojuegoHistorial()->getNombre() << endl << endl;
			DtInfoSusc* DtIS = it->second->pedirDatos();
			res.insert(DtIS);
		}
		else
			cout << "No iene suscripcion activa para " << it->second->getVideojuegoHistorial()->getNombre() << endl << endl;
	}
	return res;
};

void Jugador::agregarHistorialSuscripciones(string nombre, HistorialSuscripciones* hsNuevo) {
	this->historiales_de_suscripciones.insert({nombre, hsNuevo});
};

void Jugador::quitarHistorialSuscripciones(string nombreHistorial) {
	map<string,HistorialSuscripciones*>::iterator it = historiales_de_suscripciones.find(nombreHistorial);
  	if (it != historiales_de_suscripciones.end())
	  	it->second = NULL;
    	historiales_de_suscripciones.erase (it);
};

set<string> Jugador::nombresVideojuegos() {
	set<string> res;
	map<string, HistorialSuscripciones*>::iterator it;
	for (it = this->historiales_de_suscripciones.begin(); it != this->historiales_de_suscripciones.end(); it++) {
		HistorialSuscripciones* historial = it->second;
		if (historial->tieneSuscripcionActiva()){
			string nombre = historial->obtenerNombreVideojuego();
			res.insert(nombre);
		}
	}
	return res;
};

set<DtInfoBasicaPartidaIndividual*> Jugador::infoPartidasFinalizadas(string nombreVideojuegoSeleccionado) {
	set<DtInfoBasicaPartidaIndividual*> res;
	map<int, Partida*>::iterator it;
	for (it = this->partidasIniciadas.begin(); it != this->partidasIniciadas.end(); it++) {
		Partida* partida = it->second;
		bool finalizada = partida->getFinalizada();
		if (finalizada && partida->getVideojuego()->getNombre() == nombreVideojuegoSeleccionado) {
			DtInfoBasicaPartidaIndividual* infoPartidaIndividual = partida->obtenerInfoPartidaIndividual();
			if (infoPartidaIndividual != NULL)
				res.insert(infoPartidaIndividual);
		}
	}
	return res;
};

set<DtPartida*> Jugador::obtenerInfoPartidas() {
	set<DtPartida*> res;
	map<int, Partida*>::iterator it;
	for (it = this->partidasIniciadas.begin(); it != this->partidasIniciadas.end(); it++) {
		Partida *p = it->second;
		bool esFinalizada = p->getFinalizada();
		if(!esFinalizada) {
			DtPartida *datos = p->getDatosPartida();
			res.insert(datos);
		}
	}
	return res;
};

void Jugador::agregarNuevaPartida(Partida* nuevaPartida){
	this->partidasIniciadas.insert({nuevaPartida->getIdPartida(), nuevaPartida});
};

void Jugador::quitarPartidaIniciada(int idPartida){
	map<int,Partida*>::iterator it = this->partidasIniciadas.find(idPartida);
	if (it != this->partidasIniciadas.end()){
		it->second = NULL;
		this->partidasIniciadas.erase(it);
	}
};

ostream& operator<< (ostream& out, Jugador& j){
	string email = j.getEmail();
	string contrasenia = j.getContrasenia();
	string nickname = j.getNickname();
	string descripcion = j.getDescripcion();

	out << endl;
	out << "Email: " << email <<  endl;
	out << "Contrasenia: " << contrasenia << endl;
	out << "Nickname: " << nickname <<  endl;
	out << "Descripcion: " << descripcion <<  endl;

    return out;
};
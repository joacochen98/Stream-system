#include "../include/ControladorUsuario.h"
#include <iostream>

ControladorUsuario::ControladorUsuario() {
};

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario* ControladorUsuario::getInstancia() {
	if (instancia == NULL) instancia = new ControladorUsuario();
	return instancia;
};

// OPERACIONES SISTEMA

bool ControladorUsuario::datosInicioSesion(string email, string contrasenia) {
	auto it = this->coleccionUsuarios.find(email);
	if (it != this->coleccionUsuarios.end() && contrasenia.compare(it->second->getContrasenia()) == 0){
		this->usuarioSesion = it->second;
		return true;
	}
	else return false;
};

void ControladorUsuario::tipoUsuarioRegistrar(string tipoUsuario){
	this->tipoUsuario = tipoUsuario;
};

bool ControladorUsuario::existeEmail(string email) {
	return coleccionUsuarios.count(email) == 1;
};

void ControladorUsuario::recordarEmail(string email) {
	this->email = email;
};

void ControladorUsuario::recordarContrasenia(string contrasenia) {
	this->contrasenia = contrasenia;
};

void ControladorUsuario::ingresarNombreEmpresa(string nombreEmpresa) {
	this->nombreEmpresa = nombreEmpresa;
};

bool ControladorUsuario::existeNicknameJugador(string nickname) {
	return coleccionJugadores.count(nickname) == 1;
};

void ControladorUsuario::recordarNickname(string nickname) {
	this->nickname = nickname;
};

void ControladorUsuario::ingresarDescripcion(string descripcion) {
	this->descripcion = descripcion;
};

void ControladorUsuario::confirmarAltaUsuario() {
	if (this->tipoUsuario == "desarrollador") {
		Desarrollador* desarrollador = new Desarrollador(email, contrasenia, nombreEmpresa);
		coleccionUsuarios.insert({email, desarrollador});
		coleccionDesarrolladores.insert(desarrollador);
	}
	else {
		Jugador* jugador = new Jugador(email, contrasenia, nickname, descripcion);
		coleccionUsuarios.insert({email, jugador});
		coleccionJugadores.insert({nickname, jugador});
	}
	cancelar();
};

void ControladorUsuario::cancelar() {
	this->email = "";
	this->contrasenia = "";
	this->nombreEmpresa = "";
	this->nickname = "";
	this->descripcion = "";
	this->tipoUsuario = "";
};

void ControladorUsuario::setDesarrolladorSesion(Desarrollador* desarrollador){
	this->usuarioSesion = desarrollador;
};

void ControladorUsuario::setJugadorSesion(Jugador* jugador){
	this->usuarioSesion = jugador;
};

Usuario* ControladorUsuario::getUsuarioSesion() {
	return this->usuarioSesion;
};

set<string> ControladorUsuario::listarVideojuegosPublicadosPorDesarrolador() {
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(this->usuarioSesion);
	set<string> res = desarrolladorSesion->listarNombresVideojuegos();
	return res;
};

void ControladorUsuario::seleccionarVideojuego(string nombreVid) {
	this->nombreVid = nombreVid;
};

set<DtValorEstadistica*> ControladorUsuario::mostrarEstadistica() {
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(this->usuarioSesion);
	set<DtValorEstadistica*> res = desarrolladorSesion->mostrarEstadisticas(this->nombreVid);
	return res;
};

Jugador* ControladorUsuario::buscarJugador(string nickname) {
	map<string, Jugador*>::iterator it;
	it = this->coleccionJugadores.find(nickname);
	Jugador *res = it->second;
	return res;
};

Desarrollador* ControladorUsuario::buscarDesarrollador(string nombreEmpresa){
	Desarrollador* res = NULL;
	set<Desarrollador*>::iterator it = this->coleccionDesarrolladores.begin();
    bool encontro = false;
    while (it != coleccionDesarrolladores.end() && !encontro)
        if ((*it)->getEmpresa() == nombreEmpresa)encontro = true;
        else it++;         
    if (encontro) res = *it;     
	return res;
};

set<Desarrollador*> ControladorUsuario::getDesarrolladores() {
	return this->coleccionDesarrolladores;
};

bool ControladorUsuario::usuarioSesionEsDesarrollador() {
	Usuario* usuarioSesion = this->getUsuarioSesion();
	if (usuarioSesion == NULL) return false;
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(usuarioSesion);
	return desarrolladorSesion != NULL;
};

ControladorUsuario::~ControladorUsuario() {
	map<string,Usuario*>::iterator it1;
	for (it1 = this->coleccionUsuarios.begin(); it1 != this->coleccionUsuarios.end(); ++it1) delete it1->second;
	coleccionJugadores.clear();
	coleccionDesarrolladores.clear();
};

void ControladorUsuario::cerrarSesion() {
	this->usuarioSesion = NULL;
};

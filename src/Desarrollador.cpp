#include "../include/Desarrollador.h"
#include <string>

Desarrollador::Desarrollador(string email, string contrasenia, string empresa) : Usuario(email, contrasenia){
	this->empresa = empresa;
};

Desarrollador::~Desarrollador(){
};

string Desarrollador::getEmpresa(){
	return this->empresa;
};

//OPERACIONES

set<string> Desarrollador::listarNombresVideojuegos() {
	set<string> listarNombres;
	map<string, Videojuego*>::iterator it;
	for (it = this->videojuegosPublicados.begin(); it != this->videojuegosPublicados.end(); it++) {
		string nombreVid = it->second->getNombre();
		listarNombres.insert(nombreVid);
	}
	return listarNombres;
};

set<DtValorEstadistica*> Desarrollador::mostrarEstadisticas(string nombreVid) {
	set<DtValorEstadistica*> res;
	map<string, Videojuego*>::iterator it1;
	it1 = this->videojuegosPublicados.find(nombreVid);
	map<string, Estadistica*>::iterator it2;
	for (it2 = this->estadisticas_de_interes.begin(); it2 != this->estadisticas_de_interes.end(); it2++) {
		string aux = it2->second->getNombre();
		float val = it2->second->calcularValor(it1->second);
		DtValorEstadistica* dtE = new DtValorEstadistica(aux, val);
		res.insert(dtE);
	}
	return res;
};

void Desarrollador::eliminarVideojuegopublicado(string nombre){
	map<string, Videojuego*>::iterator it = this->videojuegosPublicados.find(nombre);
	if (it != this->videojuegosPublicados.end()){
		//it->second = NULL;
		videojuegosPublicados.erase(it);
	}
};

void Desarrollador::agregarVideojuegoPublicado(Videojuego* vj) {
	this->videojuegosPublicados.insert({vj->getNombre(), vj});
};

ostream& operator<< (ostream& out, Desarrollador& d){
	string email = d.getEmail();
	string contrasenia = d.getContrasenia();
	string empresa = d.getEmpresa();
	out << endl;
	out << "Email: " << email <<  endl;
	out << "Contrasenia: " << contrasenia << endl;
	out << "Empresa: " << empresa <<  endl;
    return out;
};

map<string, Videojuego*> Desarrollador::getVideojuegosPublicados() {
	return this->videojuegosPublicados;
};

void Desarrollador::agregarEstadistica(Estadistica *estadistica) {
	this->estadisticas_de_interes.insert({estadistica->getNombre(), estadistica});
};
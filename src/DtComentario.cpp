#include "../include/DtComentario.h"
#include <string>

using std::string;

DtComentario::DtComentario(string autor, string texto, int id, DtFechaHora* fechaComentario){
	this->autor = autor;
	this->texto = texto;
	this->id = id;
	this->fechaComentario = fechaComentario;
};
 
DtComentario::~DtComentario() {
};

string DtComentario::getAutor(){
	return this->autor;
};

string DtComentario::getTexto(){
	return this->texto;
};

int DtComentario::getId(){
	return this->id;
};

DtFechaHora* DtComentario::getFechaHora(){
	return this->fechaComentario;
};
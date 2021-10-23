#include "../include/DtJugador.h"
#include <iostream>
using namespace std;

using std::string;

DtJugador::DtJugador(string nickname,
		string descripcion){
	this->nickname = nickname;
	this->descripcion = descripcion;
};

DtJugador::~DtJugador(){};

string DtJugador::getNickname(){
	return this->nickname;
};

string DtJugador::getDescripcion(){
	return this->descripcion;
};

ostream& operator<< (ostream& out, DtJugador& dtj){
	string nickname = dtj.getNickname();
	string descripcion = dtj.getDescripcion();

	out << "Nickname: "<< nickname << endl;
	cout << "Descripcion: " << descripcion << endl;
	return out;
};

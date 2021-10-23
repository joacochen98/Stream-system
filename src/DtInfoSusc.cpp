#include "../include/DtInfoSusc.h"

using std::string;

DtInfoSusc::DtInfoSusc(string nombreVid,
		DtCosto* costo){
	this->nombreVid = nombreVid;
	this->costo = costo;
};

DtInfoSusc::~DtInfoSusc(){
	delete costo;
};

string DtInfoSusc::getNombreVid(){
	return this->nombreVid;
};

DtCosto* DtInfoSusc::getCosto(){
	return this->costo;
};

ostream& operator<< (ostream& out, DtInfoSusc& dtis){
	string nombre = dtis.getNombreVid();
	DtCosto* costo = dtis.getCosto();
	
	out << endl;
	out << "Nombre: " << nombre <<  endl;
	out << *costo <<  endl;
	
    return out;
}
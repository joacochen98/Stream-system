#include "../include/DtFechaHora.h"
#include "../include/TipoValidez.h"
#include <stdexcept>
#include <iostream>
using namespace std;

DtFechaHora::DtFechaHora() {
};

DtFechaHora::DtFechaHora(int diaN,int mesN,int anioN,int horaN,int minutoN){
	this->dia=diaN;
	this->mes=mesN;
	this->anio=anioN;
	this->hora=horaN;
	this->minuto=minutoN;
	if (diaN > 31 || diaN < 1 || mesN > 12 || mesN < 1 || anioN < 1900
		|| horaN > 23 || horaN < 0 || minutoN > 59 || minutoN < 0 ) {
		throw std::invalid_argument("Esa fecha no es valida");
	}
};

DtFechaHora::~DtFechaHora(){};

int DtFechaHora::getDia(){
	return this->dia;
};

int DtFechaHora::getMes(){
	return this->mes;
};

int DtFechaHora::getAnio(){
	return this->anio;
};

int DtFechaHora::getHora(){
	return this->hora;
};

int DtFechaHora::getMinuto(){
	return this->minuto;
};

ostream& operator<< (ostream& out, DtFechaHora& dtfh){
	int dia = dtfh.getDia();
	int mes = dtfh.getMes();
	int anio = dtfh.getAnio();
	int hora = dtfh.getHora();
	int minuto = dtfh.getMinuto();
	out << dia << "/" << mes << "/" << anio << " - " << hora << ":";
	if (minuto < 10) {
		out << "0";
	};
	out << minuto << endl;
	return out;
};

// sobrecarga de operador - para calcular la diferencia entre instancias de DtFechaHora en minutos
int operator-(DtFechaHora &f1, DtFechaHora &f2)
{
	struct tm time1;
	struct tm time2;

	time1.tm_hour = f1.getHora();
	time1.tm_min = f1.getMinuto();
	time1.tm_year = f1.getAnio() - 1900;
	time1.tm_mon = f1.getMes();
	time1.tm_mday = f1.getDia();
	time1.tm_sec = 0;

	time2.tm_hour = f2.getHora();
	time2.tm_min = f2.getMinuto();
	time2.tm_year = f2.getAnio() - 1900;
	time2.tm_mon = f2.getMes();
	time2.tm_mday = f2.getDia();
	time2.tm_sec = 0;

	int resultado = difftime(mktime(&time1), mktime(&time2)) / 60;
	return resultado;
};

DtFechaHora* operator+(DtFechaHora &f1, TipoValidez &validez){
	int dia = f1.getDia();
	int mes = f1.getMes();
	int anio = f1.getAnio();
	int hora = f1.getHora();
	int minuto = f1.getMinuto();

    if (validez == unMes){
        if (mes < 12){
            mes +=1;
        }else{
            anio += 1;
            mes = 1;          
        }
    } else if( validez == tresMeses){
        int totalmeses = mes + 3;
        if (totalmeses <= 12 ){
            mes = totalmeses;
        }else{
            anio += 1;
            mes = totalmeses % 12;
        }
    } else if (validez== unAnio) {
        anio += 1;
    } 
    DtFechaHora* res = new DtFechaHora(dia, mes, anio, hora, minuto);
    return res;
};
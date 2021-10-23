#include "../include/FechaHoraSistema.h"
#include <iostream>
using namespace std;
#include <iomanip> 

FechaHoraSistema::FechaHoraSistema(int diaN, int mesN, int anioN, int horaN, int minutoN) {
    this->dia = diaN;
    this->mes = mesN;
    this->anio = anioN;
    this->hora = horaN;
    this->minuto = minutoN;
};

FechaHoraSistema *FechaHoraSistema::instancia = NULL;

FechaHoraSistema *FechaHoraSistema::getInstancia(){
    if (instancia == NULL)
    {
        instancia = new FechaHoraSistema(12, 6, 2021, 21, 0);
    };
    return instancia;
};

void FechaHoraSistema::releaseInstancia() {
    if ( instancia != NULL) {
        delete instancia;
        instancia = NULL;
    };
}

FechaHoraSistema::~FechaHoraSistema() {
}

int FechaHoraSistema::getDia() {
    return this->dia;
};

int FechaHoraSistema::getMes() {
    return this->mes;
};

int FechaHoraSistema::getAnio() {
    return this->anio;
};

int FechaHoraSistema::getHora() {
    return this->hora;
};

int FechaHoraSistema::getMinuto() {
    return this->minuto;
};

void FechaHoraSistema::setFechaHoraSistema(int diaN, int mesN, int anioN, int horaN, int minutoN) {
    this->dia = diaN;
    this->mes = mesN;
    this->anio = anioN;
    this->hora = horaN;
    this->minuto = minutoN;
};

DtFechaHora* FechaHoraSistema::getFechaHoraSistema() {
    DtFechaHora* res = new DtFechaHora(this->dia, this->mes, this->anio, this->hora, this->minuto);
    return res;
};

DtFechaHora* FechaHoraSistema::getFechaHoraCalculada(TipoValidez validez) {
    if (validez == unMes){
        if (this->mes < 12){
            this->mes +=1;
        }else{
            this->anio += 1;
            this->mes = 1;          
        }
    } else if( validez == tresMeses){
        int totalmeses = this->mes + 3;
        if (totalmeses <= 12 ){
            this->mes = totalmeses;
        }else{
            this->anio += 1;
            this->mes = totalmeses % 12;
        }
    } else if (validez== unAnio) {
        this->anio += 1;
    } 
    DtFechaHora* res = new DtFechaHora(this->dia, this->mes, this->anio, this->hora, this->minuto);
    return res;
};
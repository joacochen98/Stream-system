#ifndef _FECHA_SISTEMA_H
#define _FECHA_SISTEMA_H

#include "DtFechaHora.h"
#include "TipoValidez.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


class FechaHoraSistema
{
private:
    // Singleton
    static FechaHoraSistema *instancia;
    ~FechaHoraSistema();
    FechaHoraSistema(int diaN, int mesN, int anioN, int horaN, int minutoN);

    // Atributos
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

public:
    static FechaHoraSistema *getInstancia();
    static void releaseInstancia();
    

    // Getters
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    // Setters
    void setFechaHoraSistema(int diaN, int mesN, int anioN, int horaN, int minutoN);
    DtFechaHora* getFechaHoraSistema();
    DtFechaHora* getFechaHoraCalculada(TipoValidez validez);

};

#endif
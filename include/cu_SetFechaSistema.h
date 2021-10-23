#ifndef CU_SETFECHASISTEMA_H
#define CU_SETFECHASISTEMA_H

#include "../include/FechaHoraSistema.h"

#include <iostream>

using namespace std;

void cu_SetFechaSistema() {
    FechaHoraSistema* fechaSistema = FechaHoraSistema::getInstancia();

    int anio;
    bool valido = false;
    while (!valido)
    {
        cout << "Ingrese el anio (>=1900): ";
        cin >> anio;
        if (anio >= 1900)
        {
            valido = true;
        };
    };

    int mes;
    valido = false;
    while (!valido)
    {
        cout << "Ingrese el mes (1-12): ";
        cin >> mes;
        if (mes > 0 && mes < 13)
        {
            valido = true;
        };
    };

    int dia;
    valido = false;
    while (!valido)
    {
        cout << "Ingrese el dia (1-31): ";
        cin >> dia;
        if (dia > 0 && dia < 32)
        {
            valido = true;
        };
    };

    int hora;
    valido = false;
    while (!valido)
    {
        cout << "Ingrese la hora (0-23): ";
        cin >> hora;
        if (hora >= 0 && hora < 24)
        {
            valido = true;
        };
    };

    int minuto;
    valido = false;
    while (!valido)
    {
        cout << "Ingrese el minuto (0-59): ";
        cin >> minuto;
        if (minuto >= 0 && minuto < 60)
        {
            valido = true;
        };
    };

    fechaSistema->setFechaHoraSistema(dia, mes, anio, hora, minuto);

    cout << "Fecha y Hora ingresada: " << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto << endl;
};

#endif // !CU_SETFECHASISTEMA_H
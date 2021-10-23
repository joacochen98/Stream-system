#ifndef _SELECCIONARESTADISTICAS_H
#define _SELECCIONARESTADISTICAS_H

#include "../include/Fabrica.h"
#include "../include/DtInfoEstadistica.h"

#include <iostream>

using namespace std;

const string MSJ_OPCION_NO_VALIDA = "La opcion ingresada no es valida";

    void
    cu_SeleccionarEstadisticas()
{
    Fabrica *fabrica = Fabrica::getInstancia();
    IVideojuego *iv = fabrica->getIVideojuego();

    cout << "Estadisticas disponibles:" << endl;
    set<DtInfoEstadistica*> estadisticas = iv->listarEstadisticas();
    for (set<DtInfoEstadistica*>::iterator it = estadisticas.begin(); it != estadisticas.end(); it++)
    {
        DtInfoEstadistica* dt = *it;
        cout << "  Nombre: " << dt->getNombre() << endl;
        cout << "  Descripcion: " << dt->getDescripcion() << endl << endl;
        delete (*it);
    };
    int opcion = 1;
    bool salir = false;
    while (!salir) {
        switch (opcion)
        {
            case 1: {
                string nombreNuevaEstadistica;
                cout << "Ingrese el nombre de la nueva estadistica: ";
                cin >> nombreNuevaEstadistica;
                try
                {
                     iv->seleccionarEstadistica(nombreNuevaEstadistica);
                }
                catch(const std::exception& e)
                {
                    //std::cerr << e.what() << '\n';
                    cout << "Estadistica no valida" << endl;
                    salir = true;
                };
                
                cout << "Seleccione una opcion:" << endl;
                cout << "1 - Seleccionar una nueva estadistica" << endl;
                cout << "0 - Salir" << endl;
                cin >> opcion;

                switch (opcion)
                {
                    case 1: {
                        break;
                    };
                    case 0: {
                        salir = true;
                        break;
                    };
                    default: {
                        cout << MSJ_OPCION_NO_VALIDA << endl;
                        break;
                    };
                };
                break;
            };
            default: {
                cout << MSJ_OPCION_NO_VALIDA << endl;
                break;
            };
        };
    };
};

#endif // !_SELECCIONARESTADISTICAS_H
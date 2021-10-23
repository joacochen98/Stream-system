#ifndef _CONSULTARESTADISTICAS_H
#define _CONSULTARESTADISTICAS_H

#include "../include/Fabrica.h"
#include "../include/Videojuego.h"

#include <iostream>

void cu_ConsultarEstadisticas() {

    Fabrica *fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    IUsuario* iu = fabrica->getIUsuario();

    cout << "Estos son los videojuegos publicados por este desarrollador:" << endl;
    set<string> nombres = iu->listarVideojuegosPublicadosPorDesarrolador();

    for (set<string>::iterator it = nombres.begin(); it != nombres.end(); it++) {
        cout << "-Nombre: " << *it << endl;  
    };

    cout << "Ingrese el nombre del videojuego que desea ver sus estadisticas: " << endl;
    string nombreVj;
    cin.ignore();
    getline(cin, nombreVj);
    iu->seleccionarVideojuego(nombreVj);

    bool nombreValido = false;
    for (set<string>::iterator it2 = nombres.begin(); it2 != nombres.end(); it2++) {
        nombreValido = nombreValido || *it2 == nombreVj;  
    };

    if(nombreValido){
        set<DtValorEstadistica*> estadistica = iu->mostrarEstadistica();
        if (!estadistica.empty()){
            set<DtValorEstadistica*>::iterator it;
            for (it = estadistica.begin(); it != estadistica.end(); it++)  {
                float f = (*it)->getValor();
                int n = static_cast<int>(f);
                cout << (*it)->getNombre() << ": " << n << endl;
                delete (*it);
            }    
        }
        else{
            cout << "No tiene estadisticas seleccionadas" << endl;
        } 
    }
    else
        cout << "Videojuego no valido" << endl;    
};
#endif
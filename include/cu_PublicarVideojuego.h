#ifndef CU_PUBLICARVIDEOJUEGO_H
#define CU_PUBLICARVIDEOJUEGO_H

#include "Fabrica.h"

#include <string>
#include <iostream>

using namespace std;

void cu_PublicarVideojuego() {
    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* interfazVideojuego = fabrica->getIVideojuego();

    string nombreJuego;
    string descripcionJuego;
    float unMes;
    float tresMeses;
    float unAnio;
    float vitalicia;
    DtCosto* costos;

    cout << "Ingrese el nombre del Videojuego y descripcion:" << endl;
    cin.ignore();
    getline (cin,nombreJuego);
    getline (cin,descripcionJuego);

    cout << "Ingrese el costo de suscripcion para un Mes, 3 meses, 1 año y Vitalicia" << endl;
    cin >> unMes;
    cin >> tresMeses;
    cin >> unAnio;
    cin >> vitalicia;

    costos = new DtCosto(unMes, tresMeses, unAnio, vitalicia);
    interfazVideojuego->agregarNuevoVideojuego(nombreJuego, descripcionJuego, costos);

    cout << "A continuacion se lista los generos disponibles en el sistema: " << endl;
    set<DtGenero*> generos = interfazVideojuego->listarGenero();
    cout << generos << endl;

    bool parar = false;
    int i = 1;
    int aux = 1;
    while(!parar) {
        if (i <= generos.size() ) {
            string generoSeleccionado;
            cout << "Ingrese el nombre del genero que desea agregar al Videojuego: " << endl;
            cin >> generoSeleccionado;
            interfazVideojuego->agregarGenero(generoSeleccionado);

            cout << "Si desea agregar mas generos ingrese 1 y en caso contrario 0." << endl;
            cin >> aux;
            if (aux == 0) parar = true;
            i++;
        } 
        else {
            cout << "Maximo numero de generos alcanzado." << endl;
            parar = true;
        }               
    };

    cout << "A continuacion se lista las plataformas disponibles en el sistema: " << endl;
    set<DtPlataforma*> plataformas = interfazVideojuego->listarPlataformas();
    cout << plataformas << endl;

    parar = false;
    i = 1;
    aux = 1;
    while(!parar) {
        if (i <= plataformas.size() ) {
        string plataformaSeleccionada;
        cout << "Ingrese el nombre de la plataforma que desea agregar al Videojuego: " << endl;
        cin.ignore();
        getline(cin, plataformaSeleccionada);
        interfazVideojuego->agregarPlataforma(plataformaSeleccionada);

        cout << "Si desea agregar mas plataformas ingrese 1 y en caso contrario 0." << endl;
        cin >> aux;
        if (aux == 0) parar = true;
        i++;
        } 
        else {
        cout << "Maximo numero de plataformas alcanzado." << endl;
        parar = true;
        }               
    };

    cout << "A continuacion se lista las categorias disponibles en el sistema: " << endl;
    set<DtCategoria*> categorias = interfazVideojuego->listarCategorias();
    cout << categorias << endl;

    parar = false;
    i = 1;
    aux = 1;
    while(!parar) {
        if (i <= categorias.size() ) {
        string categoriaSeleccionada;
        cout << "Ingrese el nombre de la categoria que desea agregar al Videojuego: " << endl;
        cin.ignore();
        getline(cin, categoriaSeleccionada);
        interfazVideojuego->agregarCategoria(categoriaSeleccionada);

        cout << "Si desea agregar mas categorias ingrese 1 y en caso contrario 0." << endl;
        cin >> aux;
        if (aux == 0) parar = true;
        i++;
        } 
        else {
        cout << "Maximo numero de categorias alcanzado." << endl;
        parar = true;
        }               
    };

    cout << "Si desea confimar la publicacion ingrese 1, en caso contrario y desea cancelar ingrese 0." << endl;
    cin >> aux;
    if (aux == 1) interfazVideojuego->confirmarNuevoVideojuego();
    else interfazVideojuego->cancelar();

    set<DtGenero*>::iterator it = generos.begin();
    set<DtPlataforma*>::iterator it2 = plataformas.begin();
    set<DtCategoria*>::iterator it3 = categorias.begin();
    for (it; it != generos.end(); it++) delete (*it);
    for (it2; it2 != plataformas.end(); it2++) delete (*it2);
    for (it3; it3 != categorias.end(); it3++) delete (*it3);
    interfazVideojuego->borrarMemoriaSistema();
}

#endif
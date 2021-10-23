#ifndef CU_ASIGNARPUNTAJE_H
#define CU_ASIGNARPUNTAJE_H

#include "Fabrica.h"

#include <string>
#include <iostream>

using namespace std;

// caso de uso Asignar Puntaje a Videojuego
void cu_AsignarPuntajeVideojuego() {
  try
  {
    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    string in_nombreVideojuego;
    int in_puntaje;

    cout << "Seleccionar Videojuego:" << endl;
    // listar nombres de los videojuegos del sistema
    set<DtInfoVideojuego*> dtVideojuegos = iv->listarInfoVideojuegos();
    for (set<DtInfoVideojuego*>::iterator it = dtVideojuegos.begin(); it != dtVideojuegos.end(); it++)
    {
      DtInfoVideojuego* dt = *it;
      cout << "Nombre: " << dt->getNombre() << endl;
      cout << "Descripcion: " << dt->getDescripcion() << endl;
      cout << "--" << endl;
      delete (*it);
    };
    cout << endl;

    // seleccionar videojuego
    cin.ignore();
    getline(cin, in_nombreVideojuego);
    try
    {
       iv->seleccionarVideojuego(in_nombreVideojuego);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }   

    // asignar puntaje al videojuego
    cout << "Ingresar puntaje a asignar: ";
    cin >> in_puntaje;
    try
    {
      iv->puntuarVideojuego(in_puntaje);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }    
    cout << "Puntaje asignado correctamente." << endl;

    // se libera la memoria temporal del sistema
    iv->borrarMemoriaSistema();
  }
  catch(const std::exception& err)
  {
    std::cerr << err.what() << '\n';
  }
};

#endif

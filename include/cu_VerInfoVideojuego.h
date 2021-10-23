#ifndef CU_VERINFOVIDEOJUEGO_H
#define CU_VERINFOVIDEOJUEGO_H

#include "Fabrica.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void cu_VerInfoVideojuego() {
  /*try
  {*/
    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    string in_nombreVideojuego;
    cout << "Seleccionar Videojuego:" << endl;
    set<DtInfoBasicaVideojuego*> dtVideojuegos = iv->listarVideojuegos();
    for (set<DtInfoBasicaVideojuego*>::iterator it = dtVideojuegos.begin(); it != dtVideojuegos.end(); it++)
    {
      DtInfoBasicaVideojuego* dt = *it;
      cout << "- " << dt->getNombre() << endl;
      delete (*it);
    };
    cin.ignore();
    getline (cin,in_nombreVideojuego);
    bool estaEnElSistema = true;
    try
    {
        iv->seleccionarVideojuego(in_nombreVideojuego);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        estaEnElSistema = false;
    }

    if (estaEnElSistema){
      try
    {
      cout << "Descripcion: " << iv->getDescripcionVideojuegoSeleccionado() << endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }    
    cout << "Costos:" << endl;
    DtCosto* dtCosto = iv->getCostosVideojuegoSeleccionado();
    cout << "  Un mes: $" << dtCosto->getUnMes() << endl;
    cout << "  Tres meses: $" << dtCosto->getTresMeses() << endl;
    cout << "  Un anio: $" << dtCosto->getUnAnio() << endl;
    cout << "  Vitalicia: $" << dtCosto->getVitalicia() << endl;
    cout << "Categorias:" << endl;
    set<string> categorias = iv->getCategoriasVideojuegoSeleccionado();
    for (set<string>::iterator it = categorias.begin(); it != categorias.end(); it++)
    {
      string nombreCategoria = *it;
      cout << " - " << nombreCategoria << endl;
    };
    try
    {
      cout << "Empresa del Desarrollador: " << iv->getEmpresaDesarrolladoraVideojuegoSeleccionado() << endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    try
    {
      cout << "Puntaje promedio: " << std::setprecision(2) << iv->getPuntajePromedioVideojuegoSeleccionado() << endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }    
    IUsuario* iu = fabrica->getIUsuario();
    if (iu->usuarioSesionEsDesarrollador())
    {
      try
      {
        float f = iv->getTotalHorasJugadasVideojuegoSeleccionado();
        int n = static_cast<int>(f);
        cout << "Total de horas jugadas: " << n << " minutos" << endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }      
    };
    iv->borrarMemoriaSistema();
    }
    /*else
      cout << "Videojuego no valido" << endl;*/
    
  /*}
  catch(const std::exception& err)
  {
    std::cerr << err.what() << '\n';
  }*/
};

#endif
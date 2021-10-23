#ifndef CU_ELIMINARVIDEOJUEGO_H
#define CU_ELIMINARVIDEOJUEGO_H

#include "DtInfoBasicaVideojuego.h"
#include "Fabrica.h"

#include <string>
#include <iostream>

using namespace std;

int menuConfirmarEliminarVideojuego() {
  cout << "Deseas Eliminar el Videojuego:" << endl;
  cout << "1 - Confirmar" << endl;
  cout << "2 - Cancelar" << endl;
  int Opcion3;
  cin >> Opcion3;
  return Opcion3;
};


void cu_EliminarVideojuego(){
    try{
        Fabrica* fabrica = Fabrica::getInstancia();
        IVideojuego* interfazVideojuego = fabrica->getIVideojuego();
        string in_nombreVideojuego;
        set<DtInfoBasicaVideojuego*> nombrevideojuegospublicados = interfazVideojuego->listarVideojuegosPublicadosDesarrollador();
        if (nombrevideojuegospublicados.empty()){
            cout << "No existen videojuegos Publicados por el desarrollador:" << endl;
        }else{
            cout << "Videojuegos Publicados:" << endl;
            for (set<DtInfoBasicaVideojuego*>::iterator it = nombrevideojuegospublicados.begin(); it != nombrevideojuegospublicados.end(); it++)
            {
                DtInfoBasicaVideojuego* dt = *it;
                cout << "- " << dt->getNombre() << endl;
                delete (*it);
            };
            // seleccionar videojuego
            cout << "Ingrese el nombre del videojuego que desea seleccionar: " << endl;
            cin.ignore();
            getline(cin, in_nombreVideojuego);
            interfazVideojuego->eliminarVideojuego(in_nombreVideojuego);
            bool salir = false;
            while (!salir) {
                int Opcion4 = menuConfirmarEliminarVideojuego();
                switch (Opcion4) {
                        case 1: { // Confirmar
                            interfazVideojuego->confirmarEliminar(); // 
                            cout << "Se ha eliminado el Videojuego" << endl;
                            salir = true;
                            break;
                        };
                        case 2: { //Cancelar
                            interfazVideojuego->cancelar();
                            salir = true;
                            break;
                        };
                        default: {
                            cout << "Comando No Reconocido" << endl;
                            break;
                        };
                    }; // switch
            }
        }
    }
    catch(const std::exception& err)
    {
        std::cerr << err.what() << '\n';
    }

};

#endif
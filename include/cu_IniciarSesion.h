#ifndef CU_INICIARSESION_H
#define CU_INICIARSESION_H

#include "Fabrica.h"
#include "cu_AsignarPuntajeVideojuego.h"
#include "cu_EliminarVideojuego.h"
#include "cu_VerInfoVideojuego.h"
#include "cu_PublicarVideojuego.h"
#include "cu_AgregarCategoria.h"
#include "cu_SuscribirseAVideojuego.h"
#include "cu_SetFechaSistema.h"
#include "cu_IniciarPartida.h"
#include "cu_FinalizarPartida.h"
#include "cu_SeleccionarEstadisticas.h"
#include "cu_ConsultarEstadisticas.h"
#include "cu_AbandonarPartidaMultijugador.h"

#include <string>
#include <iostream>

using namespace std;

int menuDesarrollador() {
  cout << endl;
  cout << "Las opciones son:" << endl;
  cout << "1 - Agregar categoria" << endl;
  cout << "2 - Publicar videojuego" << endl;
  cout << "3 - Eliminar videojuego" << endl;
  cout << "4 - Seleccionar estadísticas" << endl;
  cout << "5 - Consultar estadísticas" << endl;
  cout << "6 - Ver información de videojuego" << endl;
  cout << "7 - Modificar fecha del sistema" << endl;
  cout << "8 - Salir" << endl;
  cout << endl;
  int opcion;
  cin >> opcion;
  return opcion;
};

int menuJugador() {
  cout << endl;
  cout << "Las opciones son:" << endl;
  cout << "1 - Suscribirse a videojuego" << endl;
  cout << "2 - Asignar puntaje a videojuego" << endl;
  cout << "3 - Iniciar partida" << endl;
  cout << "4 - Abandonar partida multijugador" << endl;
  cout << "5 - Finalizar partida" << endl;
  cout << "6 - Ver información de videojuego" << endl;
  cout << "7 - Modificar fecha del sistema" << endl;
  cout << "8 - Salir" << endl;
  cout << endl;
  int opcion;
  cin >> opcion;
  return opcion;
};

bool cu_IniciarSesion() {
    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* interfazUsuario = fabrica->getIUsuario();
    bool exist_user = false;
    bool desea_cancelar = false;
    bool comando_opcion = false;
    while (!exist_user && !desea_cancelar) {
        cout << "Ingresar email: ";
        string email;
        cin.ignore();
        getline(cin, email);
        cout << "Ingresar contraseña: ";
        string contrasenia;
        getline(cin, contrasenia);
        exist_user = interfazUsuario->datosInicioSesion(email,contrasenia);
        comando_opcion = false;
        if (!exist_user){
            cout << "Usuario no existe en el sistema: " << endl;
            while(!comando_opcion){
                cout << "1 - Reingresar Datos Usuario" << endl;
                cout << "2 - Cancelar Reingreso" << endl;
                int opc2;
                cin >> opc2;
                switch(opc2) {
                    case 1: {   // Reingresar Datos Usuario
                        comando_opcion = true;
                        break;
                    };
                    case 2: {  // Cancelar Reingreso
                        comando_opcion = true;
                        desea_cancelar = true;
                        break;
                    };
                    default: {
                        cout << "Comando No Reconocido" << endl;
                        comando_opcion = false;
                        break;
                    }
                }
            }//while
        }else {
            cout << "Inicio Sesion Correctamente" << endl;
        }
    }
    return desea_cancelar;
};

void sesionDesarrollador() {
    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* interfazVideojuego = fabrica->getIVideojuego();
    IUsuario* interfazUsuario = fabrica->getIUsuario();

    bool salir = false;
    while(!salir) {
        int Opcionmenu = menuDesarrollador();
        switch(Opcionmenu) {

            case 1: {   // Agregar categoria
                cu_AgregarCategoria();
                break;
            };

            case 2: {  // Publicar videojuego
                cu_PublicarVideojuego();
                break;
            };

            case 3: {  // Eliminar videojuego
                cu_EliminarVideojuego();
                break;
            };

            case 4: {  //Seleccionar estadísticas
                cu_SeleccionarEstadisticas();
                break;
            };

            case 5: {  //Consultar estadísticas
                cu_ConsultarEstadisticas();
                break;
            };

            case 6: {   // Ver información de videojuego
                cu_VerInfoVideojuego();
                break;
            };

            case 7: {   // Modificar fecha del sistema
                cu_SetFechaSistema();
                break;
            };

            case 8: {  //Salir
                cout << "Fin." << endl;
                interfazUsuario->cerrarSesion();
                interfazUsuario->cancelar();
                salir = true;
                break;
            };

            default: {
                cout << "Comando No Reconocido" << endl;
                break;
            }

        }  //switch
    }  //while
};

void sesionJugador() {
    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* interfazUsuario = fabrica->getIUsuario();
    bool salir = false;
    while(!salir) {
        int Opcionmenu = menuJugador();
        switch(Opcionmenu) {

            case 1: {   // Suscribirse a Videojuego
                cu_SuscribirseAVideojuego();
                break;
            };

            case 2: {  // Asignar puntaje a videojuego
                cu_AsignarPuntajeVideojuego();
                break;
            };

            case 3: {  // Iniciar partida
                cu_IniciarPartida();
                break;
            };

            case 4: {  // Abandonar partida multijugador
                cu_AbandonarPartidaMultijugador();
                break;
            };

            case 5: {  // Finalizar partida
                cu_FinalizarPartida();
                break;
            };

            case 6: {  //Ver información de videojuego
                cu_VerInfoVideojuego();
                break;
            };

            case 7:
            { // Modificar fecha del sistema
                cu_SetFechaSistema();
                break;
            };

            case 8: {  //Salir
                cout << "Fin." << endl;
                interfazUsuario->cerrarSesion();
                interfazUsuario->cancelar();
                salir = true;
                break;
            };

            default: {
                cout << "Comando No Reconocido" << endl;
                break;
            }

        }  //switch
    } // while
}

#endif

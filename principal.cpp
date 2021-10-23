#include "include/Desarrollador.h"
#include "include/Fabrica.h"
#include "include/FechaHoraSistema.h"
// #include "include/IPartida.h"
// #include "include/IUsuario.h"
// #include "include/IVideojuego.h"
#include "include/cu_AltaUsuario.h"
#include "include/cu_IniciarSesion.h"
#include "include/cu_CargarDatosDePrueba.h"
#include <iostream>
#include <string>

using namespace std;

int menuPrincipal() {
  cout << "Bienvenido, las opciones son:" << endl;
  cout << "1 - Alta de Usuario" << endl;
  cout << "2 - Iniciar Sesion" << endl;
  //cout << "3 - Modificar Fecha del Sistema" << endl;
  cout << "3 - Cargar Datos de Prueba" << endl;
  cout << "4 - Salir" << endl;
  int opcion;
  cin >> opcion;
  return opcion;
};

int main()
{
  int Opcion = 0;
  bool salir = false;

  Fabrica* fabrica = Fabrica::getInstancia();
  IUsuario* interfazUsuario = fabrica->getIUsuario();
  IVideojuego* interfazVideojuego = fabrica->getIVideojuego();
  IPartida* interfazPartida = fabrica->getIPartida();

  while(!salir) {

    Opcion = menuPrincipal();

    switch (Opcion) {
      case 1: { // Alta de Usuario
        cu_AltaUsuario();
        break;
      };

      case 2: { // Iniciar Sesion
        bool desea_cancelar = cu_IniciarSesion();
        if (!desea_cancelar){
          if (dynamic_cast<Desarrollador*>(interfazUsuario->getUsuarioSesion()) != NULL){
            sesionDesarrollador();        
          } 
          else if (dynamic_cast<Jugador*>(interfazUsuario->getUsuarioSesion()) != NULL) {          
            sesionJugador();          
          }; // else
        }
        break;
      };

      case 3: { // Cargar Datos de Prueba
        cu_CargarDatosDePrueba();
        break;
      };

      case 4: {
        cout << "Fin." << endl;
        salir = true;
        break;
      };

      default: {
        cout << "Comando No Reconocido" << endl;
        break;
      };
    }; // switch
  }; // while
  
  delete interfazUsuario;
  delete interfazVideojuego;
  delete interfazPartida;
  Fabrica::releaseInstancia();
  FechaHoraSistema::releaseInstancia();
  return 0;
}

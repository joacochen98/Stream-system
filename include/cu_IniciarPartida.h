#ifndef CU_INICIARPARTIDA_H
#define CU_INICIARPARTIDA_H

#include "Fabrica.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "JugadorUnido.h"


#include <string>
#include <iostream>

using namespace std;

int menuTipoPartida() {
  cout << "Tipo de partida a iniciar:" << endl;
  cout << "1 - Individual" << endl;
  cout << "2 - Multijugador" << endl;
  cout << "3 - Cancelar" << endl;
  int opcion;
  cin >> opcion;
  return opcion;
};

int menuPartidaIndividual() {
  cout << "Desea continuar una partida anterior?" << endl;
  cout << "1 - Si" << endl;
  cout << "2 - No" << endl;
  cout << "3 - Cancelar" << endl;
  int opcion2;
  cin >> opcion2;
  return opcion2;
};

int menuConfirmarPartida() {
  cout << "Confirmar partida:" << endl;
  cout << "1 - Confirmar" << endl;
  cout << "2 - Cancelar" << endl;
  int Opcion3;
  cin >> Opcion3;
  return Opcion3;
};

void cu_IniciarPartida() {
  bool out = false;
  bool out3 = false;
  Fabrica* fabrica = Fabrica::getInstancia();
  IPartida* interfazPartida = fabrica->getIPartida();
  IUsuario* interfazUsuario = fabrica->getIUsuario();
  Usuario* usuarioSesion = interfazUsuario->getUsuarioSesion();
  Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);

  //Se listan los nombres de videojuego para los cuales tiene suscripcion activa
  set<string> NombresVideojuegos = interfazPartida->listarNombresVideojuegos();
  string nombreVideojuegoSeleccionado;
  //Tiene suscripcion activa para algun videojuego
  if (NombresVideojuegos.empty() == false) {
    cout << "Ingrese el nombre del videojuego para el cual quiere iniciar una partida:" << endl;
    for (set<string>::iterator it = NombresVideojuegos.begin(); it != NombresVideojuegos.end(); it++) {
      string nombreVj = *it;
      cout << "- " << nombreVj << endl;
    }
    //selecciona el nombre del videojuego
    cin.ignore();
    getline(cin, nombreVideojuegoSeleccionado);
    //Control de que el nombre de videojuego escrito pertenece a la lista
    while (NombresVideojuegos.count(nombreVideojuegoSeleccionado) != 1) {
        cout << "Error: videojuego seleccionado no pertenece a la lista" << endl;
        cout << "Favor ingresar nuevamente el nombre del videojuego" << endl;
        getline(cin, nombreVideojuegoSeleccionado);
    };
    //Se guarda el nombre del videojuego en el controlador
    interfazPartida->seleccionarVideojuegoSuscripcion(nombreVideojuegoSeleccionado);
  }
  //No tiene suscripcion activa para ningun videojuego
  else {
    cout << "Usted no tiene suscripciones activas para ningun videojuego" << endl;
    out = true;
    out3 = true;
  }


//Partida Individual o Multijugador
  bool tipoPartida;
  int Opcion = 0;
  while(!out) {
      Opcion = menuTipoPartida();
      switch (Opcion) {
      case 1: { // Individual
          tipoPartida = true; //true = PARTIDA INDIVIDUAL

          int Opcion2 = 0;
          bool out2 = false;
          while(!out2) {
              Opcion2 = menuPartidaIndividual();
              switch (Opcion2) {
              case 1: { // CASO 1: continua anterior
                  set<DtInfoBasicaPartidaIndividual*> partidasFinalizadas = interfazPartida->historialPartidasFinalizadas(nombreVideojuegoSeleccionado);
                  if (partidasFinalizadas.size() != 0) {
                    set<int> Idpermitidos;
                    cout << "Seleccione el identificador de la partida que desea continuar:" << endl;
                    for (set<DtInfoBasicaPartidaIndividual*>::iterator it = partidasFinalizadas.begin(); it != partidasFinalizadas.end(); it++) {
                      DtInfoBasicaPartidaIndividual* pi = *it;
                      cout << *pi;
                      Idpermitidos.insert(pi->getIdentificador());
                    }
                    int identificador;
                    cin >> identificador;
                    while (Idpermitidos.count(identificador) != 1) {
                        cout << "Error: identificador seleccionado no pertenece a la lista" << endl;
                        cout << "Favor ingresar nuevamente el identificadorde la partida" << endl;
                        cin >> identificador;
                    };

                    interfazPartida->continuarPartida(true);
                    interfazPartida->ingresarPartida(identificador);
                    //Se libera la memoria de DtInfoBasicaPartidaIndividual
                    for (set<DtInfoBasicaPartidaIndividual*>::iterator it = partidasFinalizadas.begin(); it != partidasFinalizadas.end(); it++) {
                      delete (*it);
                    }
                    partidasFinalizadas.clear();
                    out = true;
                    out2 = true;
                  }
                  else {
                    cout << "Usted no tiene partidas individuales finalizadas para continuar" << endl;
                    out = true;
                    out2 = true;
                    out3 = true;
                  }

                  break;
              };

              case 2: { //CASO 2: nueva partida
                  interfazPartida->continuarPartida(false);
                  out = true;
                  out2 = true;
                  break;
              };

              case 3: { //CASO 3: Cancela
                  interfazPartida->cancelar();
                  out = true;
                  out2 = true;
                  out3 = true;
                  break;
              };

              default: {
                  cout << "Comando No Reconocido" << endl;
                  break;
              };
            }; // switch
          }; // while

          out = true;
          break;
      };

      case 2: { // Multijugador
          tipoPartida = false;//false = PARTIDA MULTIJUGADOR

          cout << "¿Será transmitida en vivo?" << endl;
          cout << "1 - Si" << endl;
          cout << "2 - No" << endl;
          int enVivo;
          cin >> enVivo;
          while((enVivo != 1) && (enVivo != 2)){
            cout << "Comando no reconocido, ingrese nuevamente el número" << endl;
            cin >> enVivo;
          }
          if (enVivo == 1) {
            interfazPartida->esPartidaEnVivo(true);
          }
          else {
            interfazPartida->esPartidaEnVivo(false);
          }
          //Lista de jugadores con suscripcion activa al videojuego
          //Se elimina de la lista el jugador que inicio sesion
          set <DtJugador*> jugadores = interfazPartida->listarNicknamesJugadores();
          for (set<DtJugador*>::iterator it = jugadores.begin(); it != jugadores.end(); it++) {
            DtJugador* jugador = *it;
            if (jugador->getNickname().compare(jugadorSesion->getNickname()) == 0 ) {
              delete(*it);
              jugadores.erase(*it);
              break;
            }
          }

          if (jugadores.size() != 0) {  //=====hay otros jugadores con suscripcion activa=====
            set<string> nicknamesJugadores;
            cout << "Se listan los nicknames de jugadores con suscripcion activa para el videojuego seleccionado:" << endl;
            for (set<DtJugador*>:: iterator it = jugadores.begin(); it != jugadores.end(); it++) {
              DtJugador* j = *it;
              nicknamesJugadores.insert(j->getNickname());
              cout << *j;
            }

            //Se debe agregar al menos 1 nickname para partida multijugador
            string nickname;
            int seguir;
            cout << "Escriba el nickname del jugador para unirlo a la partida" << endl;
            cin.ignore();
            getline(cin, nickname);
            //CONTROLES
            while (nickname.find(' ') != string::npos || nicknamesJugadores.count(nickname) != 1) {
              //Control de nickname sin espacios
              if (nickname.find(' ') != string::npos) {
                cout << "El nickname no puede tener espacios, ingrese nuevamente el nickname" << endl;
                getline(cin, nickname);
              }
              //Control para ver si esta en la lista de jugadores
              else if (nicknamesJugadores.count(nickname) != 1){
                cout << "Error: el nickname seleccionado no pertenece a la lista" << endl;
                cout << "Favor ingresar nuevamente el nickname del jugador" << endl;
                getline(cin, nickname);
              }
            }
            //Se borra de la lista de jugadores y se guarda en el controlador
            nicknamesJugadores.erase(nickname);
            interfazPartida->agregarNicknamePartida(nickname);

            //Seguir agregando jugadores
            bool salir = false;
            while (!salir && nicknamesJugadores.size() != 0) {
              cout << "Seguir agregando jugadores a la partida?" << endl;
              cout << "1 - Si" << endl;
              cout << "2 - No" << endl;
              cin >> seguir;
              if (seguir == 1) {

                cout << "Escriba el nickname del jugador para unirlo a la partida" << endl;
                cin.ignore();
                getline(cin, nickname);
                //CONTROLES
                while (nickname.find(' ') != string::npos || nicknamesJugadores.count(nickname) != 1) {
                  //Control de nickname sin espacios
                  if (nickname.find(' ') != string::npos) {
                    cout << "El nickname no puede tener espacios, ingrese nuevamente el nickname" << endl;
                    getline(cin, nickname);
                  }
                  //Control para ver si esta en la lista de jugadores
                  else if (nicknamesJugadores.count(nickname) != 1){
                    cout << "Error: el nickname seleccionado no pertenece a la lista o ya fue agregado previamente" << endl;
                    cout << "Favor ingresar nuevamente el nickname del jugador" << endl;
                    getline(cin, nickname);
                  }
                }
                //Se borra de la lista de jugadores y se guarda en el controlador
                nicknamesJugadores.erase(nickname);
                interfazPartida->agregarNicknamePartida(nickname);

              }
              else if(seguir == 2) {
                salir = true;
              }
              else {
                cout << "comando no reconocido" << endl;
                //salir = true;
              }
            }

          //Se libera la memoria de DtJugador
          for (set<DtJugador*>::iterator it = jugadores.begin(); it != jugadores.end(); it++) {
            delete (*it);
          }
          jugadores.clear();
          }
          else { //=====No hay otros jugadores con suscripcion activa=====
            cout << "No hay otros jugadores con suscripcion activa para este videojuego" << endl;
            interfazPartida->cancelar();
            out3 = true;
          }
          out = true;
          break;
      };

      case 3: { //Cancelar
          interfazPartida->cancelar();
          out = true;
          out3 = true;
          break;
      };

      default: {
          cout << "Comando No Reconocido" << endl;
          break;
      };
    }; // switch
  }; //while

//Confirmar o cancelar
  int Opcion3 = 0;
  while(!out3) {
      Opcion3 = menuConfirmarPartida();
      switch (Opcion3) {
      case 1: { // Confirmar
          interfazPartida->confirmarAltaPartida(tipoPartida);
          cout << "Partida iniciada de forma exitosa!" << endl;
          out = true;
          out3 = true;
          break;
      };

      case 2: { //Cancelar
          interfazPartida->cancelar();
          out = true;
          out3 = true;
          break;
      };

      default: {
          cout << "Comando No Reconocido" << endl;
          break;
      };
    }; // switch
  }; // while
}
#endif
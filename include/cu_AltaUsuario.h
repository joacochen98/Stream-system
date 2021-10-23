#ifndef CU_ALTAUSUARIO_H
#define CU_ALTAUSUARIO_H

#include "Fabrica.h"

#include <string>
#include <iostream>

using namespace std;

int menuAltaUsuario() {
  cout << "Tipo de usuario a registrar:" << endl;
  cout << "1 - Desarrollador" << endl;
  cout << "2 - Jugador" << endl;
  cout << "3 - Cancelar" << endl;
  int opcion2;
  cin >> opcion2;
  return opcion2;
};

int menuConfirmarAltaUsuario() {
  cout << "Confirmar alta de usuario:" << endl;
  cout << "1 - Confirmar" << endl;
  cout << "2 - Cancelar" << endl;
  int Opcion3;
  cin >> Opcion3;
  return Opcion3;
};

void cu_AltaUsuario() {
    Fabrica* fabrica = Fabrica::getInstancia();
    IUsuario* interfazUsuario = fabrica->getIUsuario();

//Datos de Usuario
    cout << "Ingrese un email: ";
    string email;
    cin.ignore();
    getline(cin, email);
    //CONTROLES
    while (email.find(' ') != string::npos || interfazUsuario->existeEmail(email) == 1) {
      if (email.find(' ') != string::npos) {
        cout << "El email no puede tener espacios, ingrese nuevamente el email" << endl;
        getline(cin, email);
      }
      else if (interfazUsuario->existeEmail(email) == 1){
        cout << "El email ingresado ya existe en el sistema, favor ingresar un email distinto: " << endl;
        getline(cin, email);
      }
    }
    interfazUsuario->recordarEmail(email); //Se guarda en la memoria del Controlador Usuario

    cout << "Ingrese una contraseña: ";
    string contrasenia;
    getline(cin, contrasenia);
    while (contrasenia.find(' ') != string::npos) {
      cout << "La contraseña no puede tener espacios, ingrese nuevamente la contraseña" << endl;
      getline(cin, contrasenia);
    }
    interfazUsuario->recordarContrasenia(contrasenia); //Se guarda en la memoria del Controlador Usuario

//Opciones Desarrollador o Jugador

    int Opcion2 = 0;
    bool out2 = false;
    bool out3 = false;
    while(!out2) {
        Opcion2 = menuAltaUsuario();
        switch (Opcion2) {
        case 1: { // Desarrollador
            interfazUsuario->tipoUsuarioRegistrar("desarrollador");
            cout << "Ingrese el nombre de la Empresa: ";
            string nombreEmpresa;
            cin.ignore();
            getline (cin,nombreEmpresa);
            interfazUsuario->ingresarNombreEmpresa(nombreEmpresa); //Se guarda en la memoria del Controlador Usuario
            out2 = true;
            break;
        };

        case 2: { // Jugador
            interfazUsuario->tipoUsuarioRegistrar("jugador");
            cout << "Ingrese un nickname: ";
            string nickname;
            cin.ignore();
            getline(cin, nickname);
            //CONTROLES
            while (nickname.find(' ') != string::npos || interfazUsuario->existeNicknameJugador(nickname) == 1) {
              if (nickname.find(' ') != string::npos) {
                cout << "El nickname no puede tener espacios, ingrese nuevamente el nickname" << endl;
                getline(cin, nickname);
              }
              else if (interfazUsuario->existeNicknameJugador(nickname) == 1){
                cout << "El nickname ingresado ya existe en el sistema, favor ingresar un nickname distinto: " << endl;
                getline(cin, nickname);
              }
            }
            interfazUsuario->recordarNickname(nickname); //Se guarda en la memoria del Controlador Usuario

            //Ingreso de descripcion
            cout << "Ingrese una descripcion: ";
            string descripcion;
            cin.ignore();
            getline (cin,descripcion);
            interfazUsuario->ingresarDescripcion(descripcion); //Se guarda en la memoria del Controlador Usuario

            out2 = true;
            break;
        };

        case 3: { //Cancelar
            interfazUsuario->cancelar();
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

//confirmarAltaUsuario

    int Opcion3 = 0;

    while(!out3) {
        Opcion3 = menuConfirmarAltaUsuario();
        switch (Opcion3) {
        case 1: { // Confirmar
            interfazUsuario->confirmarAltaUsuario();
            cout << "Usuario registrado de forma exitosa!" << endl;
            out3 = true;
            break;
        };

        case 2: { //Cancelar
            interfazUsuario->cancelar();
            out3 = true;
            out2 = true;
            break;
        };

        default: {
            cout << "Comando No Reconocido" << endl;
            break;
        };
        }; // switch
    }; // while
}

#endif // !CU_ALTAUSUARIO_H

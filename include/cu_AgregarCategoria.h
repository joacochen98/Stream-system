#ifndef CU_AGREGARCATEGORIA_H
#define CU_AGREGARCATEGORIA_H

#include "DtCategoria.h"
#include "DtGenero.h"
#include "DtInfoCategoria.h"
#include "DtPlataforma.h"
#include "Fabrica.h"
#include "IVideojuego.h"
#include "cu_AsignarPuntajeVideojuego.h"
#include "cu_VerInfoVideojuego.h"
#include "cu_PublicarVideojuego.h"

#include <set>
#include <string>
#include <iostream>

using namespace std;

int menuConfirmarCategoria() {
  cout << "Confirmar Categoria:" << endl;
  cout << "1 - Confirmar" << endl;
  cout << "2 - Cancelar" << endl;
  int Opcion3;
  cin >> Opcion3;
  return Opcion3;
};


int menuGeneros() {
  cout << "Generos:" << endl;
  cout << "1 - Accion" << endl;
  cout << "2 - Aventura" << endl;
  cout << "3 - Estrategia" << endl;
  cout << "4 - Deporte" << endl;
  cout << "5 - Supervivencia" << endl;
  int opcion5;
  cin >> opcion5;
  return opcion5;
};


int menuPlataforma() {
  cout << "Plataformas:" << endl;
  cout << "1 - PC" << endl;
  cout << "2 - Switch" << endl;
  cout << "3 - PS4" << endl;
  cout << "4 - XboxOne" << endl;
  cout << "5 - XboxX" << endl;
  cout << "6 - PS5" << endl;
  int opcion5;
  cin >> opcion5;
  return opcion5;
};

int menuTipoCategoria() {
  cout << "Tipo de Categoria:" << endl;
  cout << "1 - Plataforma" << endl;
  cout << "2 - Género" << endl;
  cout << "3 - Otro" << endl;
  int opcion;
  cin >> opcion;
  return opcion;
};

void cu_AgregarCategoria(){
    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* interfazVideojuego = fabrica->getIVideojuego();
    cout << "Categorias disponibles en el sistema: " << endl;
    cout << "--------------------------------------" << endl;
    set<string> nombresTodasCategorias = interfazVideojuego->listarNombreTodasCategorias();
    for (auto it = nombresTodasCategorias.begin(); it != nombresTodasCategorias.end(); ++it){
        cout << *it << endl;
    }
    cout << "--------------------------------------" << endl;
    cout << "Agregar Categoría " << endl;
    bool out2 = false;
    bool out3 = false;
    bool out4 = false;
    DtInfoCategoria* DtInfocategoria;
    string descripcion; 
    string nickname;
    string tipoCategoria;
    while(!out2) {
        int Opcion2 = menuTipoCategoria();
        switch (Opcion2) {
            case 1: { // Plataforma       
                tipoCategoria = "Plataforma"; 
                while(!out3) {
                    int Opcion3 = menuPlataforma();
                    switch (Opcion3) {
                        case 1: { // PC
                            nickname = "PC";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 2: { // Switch
                            nickname = "Switch";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 3: { // PS4
                            nickname = "PS4";
                            cout << "Ingresar descripcion: ";
                            cin.ignore(); 
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 4: { // XboxOne
                            nickname = "XboxOne";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 5: { // XboxX
                            nickname = "XboxX";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 6: { // PS5
                            nickname = "PS5";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        default: {
                            cout << "Comando No Reconocido" << endl;
                            break;
                        };
                    }; // switch
                } //while  out3
                DtInfocategoria = new DtInfoCategoria(nickname,descripcion,tipoCategoria);
                interfazVideojuego->ingresarDatosCategoria(DtInfocategoria);
                while(!out4) {
                    int Opcion4 = menuConfirmarCategoria();
                    switch (Opcion4) {
                    case 1: { // Confirmar
                        interfazVideojuego->confirmarCategoria(); // tipogenero,"genero",descripcion
                        cout << "Categoria Agregada" << endl;
                        out4 = true;
                        break;
                    };
                    case 2: { //Cancelar
                        interfazVideojuego->cancelarCategoria();
                        out4 = true;
                        break;
                    };
                    default: {
                        cout << "Comando No Reconocido" << endl;
                        break;
                    };
                    }; // switch
                }; // while out4
                break;
            };
            case 2: { // Genero
                tipoCategoria = "Genero";
                while(!out3) {
                    int Opcion3 = menuGeneros();
                    switch (Opcion3) {
                        case 1: { // Accion
                            nickname = "Accion";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 2: { // Aventura
                            nickname = "Aventura";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 3: { // Estrategia
                            nickname = "Estrategia";
                            cout << "Ingresar descripcion: "; 
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 4: { // Deporte
                            nickname = "Deporte";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        case 5: { // Supervivencia
                            nickname = "Supervivencia";
                            cout << "Ingresar descripcion: ";
                            cin.ignore();
                            getline(cin,descripcion);
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        default: {
                            cout << "Comando No Reconocido" << endl;
                            break;
                        };
                    }; // switch
                } //while  out3
                DtInfocategoria = new DtInfoCategoria(nickname,descripcion,tipoCategoria);
                interfazVideojuego->ingresarDatosCategoria(DtInfocategoria);
                while(!out4) {
                    int Opcion4 = menuConfirmarCategoria();
                    switch (Opcion4) {
                    case 1: { // Confirmar
                        interfazVideojuego->confirmarCategoria(); // tipogenero,"genero",descripcion
                        cout << "Categoria Agregada" << endl;
                        out4 = true;
                        break;
                    };
                    case 2: { //Cancelar
                        interfazVideojuego->cancelarCategoria();
                        out4 = true;
                        break;
                    };
                    default: {
                        cout << "Comando No Reconocido" << endl;
                        break;
                    };
                    }; // switch
                }; // while out4
                break;
            };
            case 3: { // Otro

                tipoCategoria = "Otro";
                cout << "Ingresar nombre: ";
                string nickname;
                cin.ignore();
                getline(cin,nickname);
                cout << "Ingresar descripcion: ";
                string descripcion;
                cin.ignore();
                getline(cin,descripcion);
                DtInfocategoria = new DtInfoCategoria(nickname,descripcion,tipoCategoria);
                interfazVideojuego->ingresarDatosCategoria(DtInfocategoria);
                while(!out3) {
                    int Opcion4 = menuConfirmarCategoria();
                    switch (Opcion4) {
                        case 1: {  //Confirmar
                            interfazVideojuego->confirmarCategoria(); 
                            cout << "Categoria Agregada" << endl;
                            out3 = true;
                            break;
                        };
                        case 2: { //Cancelar
                            interfazVideojuego->cancelarCategoria();
                            out3 = true;
                            out2 = true;
                            break;
                        };
                        default: {
                            cout << "Comando No Reconocido" << endl;
                            break;
                            };
                        };  //switch
                }
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
}

#endif
#ifndef CU_FINALIZARPARTIDA
#define CU_FINALIZARPARTIDA

#include "Fabrica.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// caso de uso Ver Informacion de Videojuego
void cu_FinalizarPartida() {
	Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    IPartida* ip = fabrica->getIPartida();
    set<DtPartida*> partidas = ip->obtenerInfoPartidas();
		set<int> idPermitidos;

    if (!partidas.empty()){
			cout << "A continuacion se listan las partidas que aun no han finalizado." << endl;
			set<DtPartida*>::iterator it;
			for (it = partidas.begin(); it != partidas.end(); it++) {
				DtPartida* aux = *it;
				cout << aux << endl;
				idPermitidos.insert(aux->getIdentificador());
				delete *it;
			};
      int id;
      cout << "Seleccione la partida que desea finalizar ingresando su id." << endl;
      cin >> id;
			while (idPermitidos.count(id) != 1) {
	        cout << "Error: identificador seleccionado no pertenece a la lista" << endl;
	        cout << "Favor ingresar nuevamente el identificador de la partida" << endl;
	        cin >> id;
	    };
      ip->finalizarPartida(id);
      cout << "La partida seleccionada ha sido finalizada." << endl;
    }
    else{
      cout << "No hay partidas para finalizar" << endl;
    }
};

#endif

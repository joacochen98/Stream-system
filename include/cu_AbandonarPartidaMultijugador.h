#ifndef _ABANDONARPARTIDAMULTI_H
#define _ABANDONARPARTIDAMULTI_H

#include "Fabrica.h"

#include <iostream>

using namespace std;

void cu_AbandonarPartidaMultijugador() {
    Fabrica* fabrica = Fabrica::getInstancia();
    IPartida* ip = fabrica->getIPartida();

    map<int, DtAbandonarPartidaMultijugador*> partidasMultijugador = ip->obtenerInfoPartidasMultijugador();
    if (partidasMultijugador.size() != 0){
        for (map<int, DtAbandonarPartidaMultijugador*>::iterator it = partidasMultijugador.begin(); it != partidasMultijugador.end(); it++)
        {
            DtAbandonarPartidaMultijugador* dt = it->second;
            cout << "ID: " << it->first << endl;
            cout << "Fecha comienzo: " << dt->getFechaComienzo()->getDia() << "/" << dt->getFechaComienzo()->getMes() << "/" << dt->getFechaComienzo()->getAnio() << endl;
            cout << "Hora comienzo: " << dt->getFechaComienzo()->getHora() << "hs" << endl;
            cout << "Videojuego: " << dt->getNombreVideojuego() << endl;
            cout << "Transmitida en vivo: ";
            if (dt->getEnVivo())
            {
                cout << "Si" << endl;
            } else {
                cout << "No" << endl;
            };
            cout << "Jugador que la inicio: " << dt->getNicknameJugadorInicio() << endl;
            cout << "Jugadores que se unieron:" << endl;
            set<string> nicknamesJugadoresUnidos = dt->getNicknameJugadoresUnidos();

            for (set<string>::iterator it2 = nicknamesJugadoresUnidos.begin(); it2 != nicknamesJugadoresUnidos.end(); it2++)
            {
                string nickname = *it2;
                cout << " - " << nickname << endl;
            };
            delete it->second;
        };

        bool abandonoExito = false;
        while (!abandonoExito)
        {
            abandonoExito = true;
            int id_in;
            cout << "Ingrese el ID de la partida que desea abandonar:" << endl;
            cout << "> ";
            cin >> id_in;

            try
            {
                ip->abandonarPartidaMultijugador(id_in);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                abandonoExito = false;
            };
        }
    }
    else{
        cout << "No hay partidas multijugador para abandonar" << endl;
    }
};

#endif // !_ABANDONARPARTIDAMULTI_H

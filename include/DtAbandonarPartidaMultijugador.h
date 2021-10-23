#ifndef DTABANDONARPARTIDAMULTIJUGADOR_HH
#define DTABANDONARPARTIDAMULTIJUGADOR_HH

#include "DtPartidaMultijugador.h"
#include <iostream>
using namespace std;

class DtAbandonarPartidaMultijugador: public DtPartidaMultijugador
{
    private:
        string nicknameJugadorinicio;

    public:
        DtAbandonarPartidaMultijugador(DtFechaHora* fechaComienzo, float duracion, bool transmitido,int identificador, int cantidadjugadores,set<string> nombresjugadores,string jugadorinicio, string nombreVj);
        ~DtAbandonarPartidaMultijugador(){};
        string getNicknameJugadorInicio();
};
#endif
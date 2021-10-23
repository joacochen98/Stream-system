#include "../include/DtAbandonarPartidaMultijugador.h"
#include <string>
using namespace std;

DtAbandonarPartidaMultijugador::DtAbandonarPartidaMultijugador(DtFechaHora* fechaComienzo, float duracion,bool transmitido,int identificador, int cantJugadores, set<string> nombresjugadores,string jugadorinicio, string nombreVj) : DtPartidaMultijugador(identificador,fechaComienzo,duracion,transmitido,cantJugadores, nombresjugadores, nombreVj){
	this->nicknameJugadorinicio = jugadorinicio;
};

string DtAbandonarPartidaMultijugador::getNicknameJugadorInicio() {
	return this->nicknameJugadorinicio;
};
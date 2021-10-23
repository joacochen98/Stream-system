#include "../include/DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(int identificador,DtFechaHora* fechacomienzo, float duracion, bool transmitido,int cantJugadores,set<string> nombresjugadores, string nombreVj):DtPartida(identificador, fechacomienzo, duracion, nombreVj) {
    this->transmitidaEnVivo = transmitido;
    this->nicknameJugadoresUnidos = nombresjugadores;
    this->cantJugadores = cantJugadores;
};

DtPartidaMultijugador::~DtPartidaMultijugador() {
	nicknameJugadoresUnidos.clear();
};

bool DtPartidaMultijugador::getEnVivo() {
    return this->transmitidaEnVivo;
};

set<string> DtPartidaMultijugador::getNicknameJugadoresUnidos() {
	return this->nicknameJugadoresUnidos;
};

ostream& operator<< (ostream& out, DtPartidaMultijugador& pm) {

   int id = pm.getIdentificador();
   string nombre = pm.getNombreVideojuego();
   DtFechaHora* fecha = pm.getFechaComienzo();
   set<string> setJ = pm.getNicknameJugadoresUnidos();

   out << endl;
   out << "Tipo partida: Multijugador" << endl;
   out << "El id de la partida es: " << id << endl;
	 out << "Partida perteneciente al juego: " << nombre << endl;
 	 out << "La fecha de comienzo de la partida es: " << *fecha;

   if (pm.getEnVivo())
   	out << "Transmitido en vivo: " << "Si" << "\n";
   else
    out << "Transmitido en vivo: " << "No" << "\n";
   out << "Jugadores unidos a la partida: ";
   set<string>::iterator it;
   for (it = setJ.begin(); it != setJ.end(); it++) {
     out << "-> " << (*it) << endl;
   };
   out << endl;
return out;
};
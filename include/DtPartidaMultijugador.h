#ifndef DTPARTIDAMULTIJUGADOR_HH
#define DTPARTIDAMULTIJUGADOR_HH

#include "DtFechaHora.h"
#include "DtPartida.h"

#include <set>

using namespace std;

// class PartidaMultijugador;
class DtPartidaMultijugador : public DtPartida {
private:
  bool transmitidaEnVivo;
  set<string> nicknameJugadoresUnidos;
  int cantJugadores;

public:
  DtPartidaMultijugador(int identificador, DtFechaHora *fechaComienzo, float duracion,bool transmitido,int cantJugadores,set<string> nombresjugadores, string nombreVj);
  virtual ~DtPartidaMultijugador();
  bool getEnVivo();
  set<string> getNicknameJugadoresUnidos();

};
ostream& operator<< (ostream& out, DtPartidaMultijugador& pm);

#endif
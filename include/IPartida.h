#ifndef _IPartida
#define _IPartida

#include "../include/DtInfoBasicaPartidaIndividual.h"
#include "../include/DtJugador.h"
#include "../include/DtPartida.h"
#include "../include/Partida.h"
#include "../include/DtAbandonarPartidaMultijugador.h"
#include <set>
#include <map>

using std::string;
using namespace std;

class IPartida {
	public:
		IPartida() {};
		virtual void setIdGenerado(int IdGenerado) = 0;
		virtual int getIdGenerado() = 0;
		virtual set<string> listarNombresVideojuegos() = 0;
		virtual void seleccionarVideojuegoSuscripcion(string nombreVideojuego) = 0;
		virtual void continuarPartida(bool cont) = 0;
		virtual set<DtInfoBasicaPartidaIndividual*> historialPartidasFinalizadas(string nombreVideojuegoSeleccionado) = 0;
		virtual void ingresarPartida(int indentificador) = 0;
		virtual void esPartidaEnVivo(bool enVivo) = 0;
		virtual set<DtJugador*> listarNicknamesJugadores() = 0;
		virtual void agregarNicknamePartida(string nickname) = 0;
		virtual set<DtPartida*> obtenerInfoPartidas() = 0;
		virtual void finalizarPartida(int indentificador) = 0;
		virtual void confirmarAltaPartida(bool tipoPartida) = 0;
		virtual void cancelar() = 0;
		virtual map<int, DtAbandonarPartidaMultijugador*> obtenerInfoPartidasMultijugador() = 0;
		virtual void abandonarPartidaMultijugador(int idPartida) = 0;
		virtual map<int, Partida*> getColeccionPartidas() = 0;
		virtual ~IPartida() {};
		virtual void agregarPartidaInterfaz(Partida* p) = 0;
};
#endif
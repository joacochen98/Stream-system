#ifndef _ControladorPartida
#define _ControladorPartida

#include "DtInfoBasicaPartidaIndividual.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "DtJugador.h"
#include "DtPartida.h"
#include "Jugador.h"
#include "Partida.h"
#include "IPartida.h"
#include "Videojuego.h"

using namespace std;

class ControladorPartida: public IPartida {

	private:
		ControladorPartida();
		static ControladorPartida* instancia; // Singleton
		set<string> Nicknames;
		map<int, Partida*> coleccionPartidas;
		int IdGenerado;
		string nombreVideojuego;
		int indentificador;
		bool continuaPartida;
		bool enVivo;

	public:
		static ControladorPartida* getInstancia();

		void setIdGenerado(int IdGenerado);
		int getIdGenerado();
		set<string> listarNombresVideojuegos();
		void seleccionarVideojuegoSuscripcion(string nombreVideojuego);
		void continuarPartida(bool cont);
		set<DtInfoBasicaPartidaIndividual*> historialPartidasFinalizadas(string nombreVideojuegoSeleccionado);
		void ingresarPartida(int indentificador);
		void esPartidaEnVivo(bool enVivo);
		set<DtJugador*> listarNicknamesJugadores();
		void agregarNicknamePartida(string nickname);
		set<DtPartida*> obtenerInfoPartidas();
		void finalizarPartida(int indentificador);
		void confirmarAltaPartida(bool tipoPartida);
		void cancelar();
		map<int, DtAbandonarPartidaMultijugador *> obtenerInfoPartidasMultijugador();
		void abandonarPartidaMultijugador(int idPartida);
		map<int, Partida*> getColeccionPartidas();
		~ControladorPartida();
		void agregarPartidaInterfaz(Partida* p);
};
#endif
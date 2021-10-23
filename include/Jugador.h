#ifndef _JUGADOR_H
#define _JUGADOR_H

#include "../include/Usuario.h"
#include "../include/DtInfoSusc.h"
#include "../include/DtInfoBasicaPartidaIndividual.h"

#include <string>
#include <set>
#include <map>

class DtPartida;
class Partida;
class HistorialSuscripciones;

using namespace std;

class Jugador: public Usuario
{
private:
	string nickname;
	string descripcion;
	map<int, Partida*> partidasIniciadas;
	map<string, HistorialSuscripciones*> historiales_de_suscripciones;

public:
	Jugador();
	Jugador(string email, string contrasenia, string nickname, string descripcion);
	~Jugador();

	//GETTERS
	string getNickname();
	string getDescripcion();
	map<string, HistorialSuscripciones*> getHistoriales_de_suscripciones();
	map<int, Partida*> getPartidasIniciadas();

	//OPERACIONES
	set<DtInfoSusc*> listarVidConSuscActivas();
	void quitarHistorialSuscripciones(string nombreHistorial);
	void agregarHistorialSuscripciones(string nombre, HistorialSuscripciones* hsNuevo);
	set<DtInfoBasicaPartidaIndividual*> infoPartidasFinalizadas(string nombreVideojuegoSeleccionado);
	set<DtPartida*> obtenerInfoPartidas();
	set<string> nombresVideojuegos();
	void agregarNuevaPartida(Partida* nuevaPartida);
	void quitarPartidaIniciada(int idPartida);
	friend ostream& operator<< (ostream& out, Jugador& j);

};

#include "../include/DtPartida.h"
#include "../include/HistorialSuscripciones.h"

#endif
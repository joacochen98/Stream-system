#ifndef PARTIDA_INDIVIDUAL_H
#define PARTIDA_INDIVIDUAL_H

#include "../include/DtFechaHora.h"
#include "../include/Partida.h"
#include "../include/DtPartidaIndividual.h"

class PartidaIndividual : public Partida
{
  private:
    bool continuaAnterior;
    int idPartidaAnterior;
    Videojuego* videojuegoPerteneciente;

  public:
    PartidaIndividual();
    PartidaIndividual(int idPartida, DtFechaHora* fechaComienzo, Videojuego* videojuego, bool finalizada, string nicknameJugadorInicio, bool continuaAnterior);

    void setContinuaAnterior(bool continuaAnterior);
    void setIdPartidaAnterior(int idPartidaAnterior);
    bool getContinuaAnterior();
    int getIdPartidaAnterior();

    void setVideojuegoPerteneciente(Videojuego* videojuego);

    ~PartidaIndividual();

    DtInfoBasicaPartidaIndividual* obtenerInfoPartidaIndividual();
    void setDatos(Videojuego* videojuego, int idPartidaAnterior);
    DtPartida* getDatosPartida();
    void borrarPartida(Jugador* jugador);
    void finalizarPartida();
    float darTotalHorasParticipantes();

    friend ostream& operator<< (ostream& out, PartidaIndividual& pi);

};

#endif
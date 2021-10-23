#ifndef PARTIDA_H
#define PARTIDA_H

#include "../include/DtFechaHora.h"
#include "../include/DtInfoBasicaPartidaIndividual.h"
#include "../include/DtPartida.h"


class Videojuego;
class Jugador;

class Partida
{
  private:
    int idPartida;
    bool finalizada;
    DtFechaHora* fechaComienzo;
    DtFechaHora* fechaFinalizacion;
    float duracion;
    Videojuego* videojuego;
    string nicknameJugadorInicio;

  public:
    Partida();
    Partida(int idPartida, DtFechaHora* fechaComienzo, Videojuego* videojuego, bool finalizada, string nicknameJugadorInicio);
    void setFinalizada(bool finalizada);
    void setFechaFinalizacion(DtFechaHora* fechaFinalizacion);
    void setDuracion(int duracion);

    int getIdPartida();
    bool getFinalizada();
    DtFechaHora* getFechaComienzo();
    DtFechaHora* getFechaFinalizacion();
    float getDuracion();
    Videojuego* getVideojuego();
    string getNicknameJugadorInicio();
    virtual ~Partida();
    virtual DtPartida* getDatosPartida() = 0;
    virtual DtInfoBasicaPartidaIndividual* obtenerInfoPartidaIndividual() = 0;
    virtual void finalizarPartida() = 0;
    virtual void borrarPartida(Jugador* jugadorPartida) = 0;
    virtual float darTotalHorasParticipantes() = 0;

};

ostream& operator<< (ostream& out, Partida* &p);

#include "../include/Videojuego.h"
#include "../include/Jugador.h"
#endif
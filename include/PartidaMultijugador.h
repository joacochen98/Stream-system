#ifndef PARTIDA_MULTIJUGADOR_H
#define PARTIDA_MULTIJUGADOR_H

#include "../include/DtFechaHora.h"
#include "../include/Usuario.h"
#include "../include/Partida.h"
#include "../include/JugadorUnido.h"

class PartidaMultijugador : public Partida
{
  private:
    bool enVivo;
    set<JugadorUnido*> jugadoresUnidos;
    Videojuego* videojuegoPerteneciente;

  public:
    PartidaMultijugador(int idPartida, DtFechaHora* fechaComienzo, Videojuego* videojuego, bool finalizada, string nicknameJugadorInicio, bool enVivo);
    
    void setEnVivo(bool envivo);
    void setJugadoresUnidos(set<JugadorUnido*> jU);
    void agregarJugadorUnido(JugadorUnido* ju);
    void setVideojuegoPerteneciente(Videojuego* videojuego);
    bool getEnVivo();
    set<JugadorUnido*> getJugadoresUnidos();

    ~PartidaMultijugador();

    DtInfoBasicaPartidaIndividual* obtenerInfoPartidaIndividual();
    void setDatos(string nombreVideojuego);
    DtPartida* getDatosPartida();
    void borrarPartida(Jugador* jugadorPartida);
    void finalizarPartida();
    float darTotalHorasParticipantes();

    bool jugadorUnido(string nicknameJugador);
    void sacarJugadorDePartida(string nicknameJugador);
    bool jugadorAbandono(string nickname);

    void abandonarPartida(string nicknameJugador);
    friend ostream& operator<< (ostream& out, PartidaMultijugador& pm);
};

#endif
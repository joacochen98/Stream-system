#ifndef JUGADOR_UNIDO_H
#define JUGADOR_UNIDO_H

#include "../include/Fabrica.h"
#include "../include/DtFechaHora.h"
#include "../include/Jugador.h"

class JugadorUnido
{
  private:
    bool abandono;
    DtFechaHora* fechaAbandono;
    float duracion;

    Jugador* jugador;

  public:
    //CONSTRUCTOR
    JugadorUnido();
    JugadorUnido(Jugador* jugador);

    //SETTERS - GETTERS
    void setAbandono(bool abandono);
    void setFechaAbandono(DtFechaHora* fechaAbandono);
    void setDuracion(float duracion);
    void setJugador(Jugador* jugador);

    bool getAbandono();
    DtFechaHora* getFechaAbandono();
    float getDuracion(DtFechaHora* fechaComienzo, bool partidaFueFinalizada);
    Jugador* getJugador();

    //DESTRUCTOR
    ~JugadorUnido();

    //OPERACIONES
    Jugador* buscarJugadorUnido(string nickname);
    string getNickname();
    void abandonar(DtFechaHora* fechaComienzo);

    friend ostream& operator<< (ostream& out, JugadorUnido& ju);

};

#endif

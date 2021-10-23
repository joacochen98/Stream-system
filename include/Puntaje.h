#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <iostream>
using namespace std;

class Jugador;

class Puntaje
{
  private:
    int puntaje;
    Jugador* jugador;

  public:
    Puntaje(int puntaje, Jugador* jugador);
    int getPuntaje();
    ~Puntaje();
    friend ostream& operator<< (ostream& out, Puntaje& p);
};

#include "Jugador.h"

#endif
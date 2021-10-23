#include "../include/Puntaje.h"

Puntaje::Puntaje(int puntaje, Jugador* jugador){
    this->puntaje = puntaje;
    this->jugador = jugador;
};

int Puntaje::getPuntaje(){
    return this->puntaje;
};

Puntaje::~Puntaje(){
};

ostream& operator<< (ostream& out, Puntaje& p){
  string nombre = p.jugador->getNickname();
  int punt = p.puntaje;
  out << endl;
  out << nombre << " le asigno " << punt << " puntos" << endl;
  return out;
};

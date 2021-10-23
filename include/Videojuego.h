#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "../include/DtCosto.h"
#include "../include/Genero.h"
#include "../include/Plataforma.h"
#include "../include/Categoria.h"
#include "../include/DtJugador.h"
#include "../include/TipoPago.h"
#include "../include/TipoSuscripcion.h"

#include <set>
#include <map>
#include <iostream>
using namespace std;

class Partida;
class Puntaje;
class HistorialSuscripciones;

class Videojuego
{
  private:
    string nombre;
    string descripcion;
    DtCosto* costo;
    float puntajePromedio;
    float totalHorasJugadas;
    int cantidadPartidasActivas;

    set<Puntaje*> puntajes;
    map<string, HistorialSuscripciones*> historialSuscripciones;
    map<int, Partida*> partida;

    set<Genero*> generos;
    set<Plataforma*> plataformas;
    set<Categoria*> categorias;

  public:
    //CONSTRUCTOR
    Videojuego(string nombre, string descripcion, DtCosto* costo);

    //SETTERS - GETTERS
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setCosto(DtCosto* costo);
    void setPuntajePromedio(float puntajePromedio);
    void setTotalHorasJugadas(float totalHorasJugadas);
    void setCantidadPartidasActivas(int cantidadPartidasActivas);

    void setGenPlatCat(set<Genero*> g, set<Plataforma*> p, set<Categoria*> c);

    string getNombre();
    string getDescripcion();
    DtCosto* getCosto();
    float getPuntajePromedio();
    float getTotalHorasJugadas();
    int getCantidadPartidasActivas();
    set<Categoria *> getCategorias();
    set<Genero*> getGeneros();
    set<Plataforma *> getPlataformas();
    set<Puntaje*> getPuntajes();
    map<string, HistorialSuscripciones*> getHistorialSuscripciones();
    map<int, Partida*> getPartidas();

    //DESTRUCTOR
    ~Videojuego();

    //OPERACIONES
    bool usuarioTieneSuscActiva();
    void cancelarSuscripcion();
    void confirmarSuscripcion(TipoSuscripcion tipoSusc, TipoPago pago);
    set<DtJugador*> obtenerNicknamesJugadores();
    void sumarCantPartidas();
    void restarCantPartidas();
    bool tienePartidasAct();
    void eliminar();
    float getCostoDeTipoSusc(TipoSuscripcion tipoSusc);
    void agregarPuntaje(Puntaje* newPuntaje);
    friend ostream& operator<< (ostream& out, Videojuego &v);
    void agregarHistorialSuscripciones(HistorialSuscripciones* hs);
    void EliminarHistorialSuscripciones();
    void EliminarPuntajes();
    void EliminarPartidas();
    void agregarPartida(Partida* p);
};

#include "../include/HistorialSuscripciones.h"
#include "../include/Puntaje.h"
#include "../include/Partida.h"

#endif
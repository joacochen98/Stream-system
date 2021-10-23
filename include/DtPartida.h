#ifndef DTPARTIDA_HH
#define DTPARTIDA_HH
#include "DtFechaHora.h"
#include <iostream>

using namespace std;

class DtPartida
{
    private:
        int idPartida;
        bool finalizada;
        DtFechaHora* fechaComienzo;
        DtFechaHora* fechaFinalizacion;
        float duracion;
        string nombreVj;

    public:
        DtPartida();
        DtPartida(int identificador, DtFechaHora* fechaComienzo, float duracion, string nombreVj);
        virtual ~DtPartida();
        DtFechaHora* getFechaComienzo();
        DtFechaHora* getFechaFinalizacion();
        float getDuracion();
        int getIdentificador();
        bool getFinalizada();
        string getNombreVideojuego();


};
ostream& operator<< (ostream& out, DtPartida* &p);

#endif
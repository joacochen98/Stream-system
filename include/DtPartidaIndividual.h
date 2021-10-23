#ifndef DTPARTIDAINDIVIDUAL_HH
#define DTPARTIDAINDIVIDUAL_HH

#include "DtPartida.h"
#include "DtFechaHora.h"
using namespace std;

class DtPartidaIndividual: public DtPartida
{
    private:
        bool continuaPartidaAnterior;
    public:
        DtPartidaIndividual();
        DtPartidaIndividual(int idPartida, DtFechaHora* fechacomienzo, float duracion, bool continua, string nombreVj);
        ~DtPartidaIndividual();
        bool getContinuaPartida();
};
ostream& operator<< (ostream& out, DtPartidaIndividual& pi);
#endif

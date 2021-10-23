#ifndef DTGENERO_HH
#define DTGENERO_HH

#include "DtCategoria.h"
#include "DtFechaHora.h"
#include "TipoGenero.h"

using namespace std;
#include <set>

class DtGenero: public DtCategoria
{
    private:
        TipoGenero genero;
    public:
        DtGenero(string nombre, string desc, TipoGenero genero);
        ~DtGenero();
        TipoGenero getGenero();
        friend ostream& operator<< (ostream& out, set<DtGenero*>& setG);

};
#endif
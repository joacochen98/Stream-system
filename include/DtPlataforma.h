#ifndef DTPLATAFORMA_HH
#define DTPLATAFORMA_HH

#include "../include/DtCategoria.h"
#include "../include/Plataforma.h"
#include "../include/DtFechaHora.h"
#include "../include/TipoPlataforma.h"

using namespace std;
#include <set>

class DtPlataforma: public DtCategoria
{
    private:
        TipoPlataforma plataforma;
    public:
        DtPlataforma(string nombre, string desc, TipoPlataforma plataforma);
        DtPlataforma(Plataforma *plataforma);
        ~DtPlataforma();
        TipoPlataforma getPlataforma();
        friend ostream& operator<< (ostream& out, set<DtPlataforma*>& setP);
};
#endif

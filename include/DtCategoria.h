#ifndef DTCATEGORIA_HH
#define DTCATEGORIA_HH

#include "Categoria.h"

#include <iostream>
#include <set>
using namespace std;

class DtCategoria {
    private:
        string nombre;
        string descripcion;
    public:
        DtCategoria();
        DtCategoria(string nombre, string descripcion);
        DtCategoria(Categoria *c);
        virtual ~DtCategoria();
        string getNombre();
        string getDescripcion();
        friend ostream& operator<< (ostream& out, set<DtCategoria*>& setC);

};
#endif
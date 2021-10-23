#ifndef DTINFOVIDEOJUEGO_HH
#define DTINFOVIDEOJUEGO_HH

#include "DtInfoBasicaVideojuego.h"
#include <iostream>
using namespace std;


class DtInfoVideojuego: public DtInfoBasicaVideojuego
{
    private:
        string descripcion;
    public:
        DtInfoVideojuego();
        DtInfoVideojuego(string nombre,string descripcion);
        virtual ~DtInfoVideojuego();
        string getDescripcion();
};
#endif

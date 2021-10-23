#ifndef DTINFOBASICAVIDEOJUEGO_HH
#define DTINFOBASICAVIDEOJUEGO_HH

#include <iostream>
using namespace std;

class DtInfoBasicaVideojuego
{
    private:
        string nombre;
    public:
        DtInfoBasicaVideojuego();
        DtInfoBasicaVideojuego(string nombre);
        virtual ~DtInfoBasicaVideojuego();
        string getNombre();
};
#endif

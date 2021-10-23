#ifndef _DTVIDEOJUEGO_H
#define _DTVIDEOJUEGO_H

#include <string>
#include "DtInfoVideojuego.h"
#include "DtCosto.h"

using std::string;

class DtVideojuego: public DtInfoVideojuego
{
	private:
		string nombre;
		string descripcion;
    DtCosto* costo;
    float puntajePromedio;
    int cantidadPartidasActivas;

  	float totalHorasJugadas;

    public:
		//CONSTRUCTOR
      DtVideojuego(string nombre, string descripcion, DtCosto* costo);

      // GETTERS
      string getNombre();
      string getDescripcion();
      DtCosto* getCostos();
      float getPuntajePromedio();
      float getTotalHorasJugadas();
      int getCantidadPartidasActivas();
      // DESTRUCTOR
      ~DtVideojuego();
};
#endif

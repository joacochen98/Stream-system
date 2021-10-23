#ifndef _CANTIDAD_TOTAL_JUGADORES_H
#define _CANTIDAD_TOTAL_JUGADORES_H

#include "../include/Estadistica.h"

class CantidadTotalJugadores : public Estadistica
{
private:
	Videojuego* videojuegoSeleccionado;

public:
	CantidadTotalJugadores(string nombre, string descripcion);
	~CantidadTotalJugadores();

	//OPERACIONES
	float calcularValor(Videojuego* vj);
	void seleccionarVideojuego(Videojuego* videojuego);

	friend ostream& operator<< (ostream& out, CantidadTotalJugadores& ctj);
};

#endif

#ifndef _ESTADISTICA_H
#define _ESTADISTICA_H

#include "Estadistica.h"
#include "Videojuego.h"

class TotalHorasJugadas : public Estadistica
{
private:
	Videojuego* videojuegoSeleccionado;
public:
	TotalHorasJugadas(string nombre, string descripcion);
	~TotalHorasJugadas();

	//OPERACIONES
	float calcularValor(Videojuego* vj);
	void seleccionarVideojuego(Videojuego* videojuego);

	friend ostream& operator<< (ostream& out, TotalHorasJugadas& thj);
};

#endif
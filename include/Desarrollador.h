#ifndef _DESARROLLADOR_H
#define _DESARROLLADOR_H

#include "../include/Usuario.h"
#include "../include/Estadistica.h"
#include "../include/Videojuego.h"
#include "../include/DtValorEstadistica.h"

#include <string>
#include <map>
#include <set>

using namespace std;

class Desarrollador: public Usuario
{
private:
	string empresa;

	//PSEUDOATRIBUTOS (LINKS)
	map<string, Estadistica*> estadisticas_de_interes;
	map<string, Videojuego*> videojuegosPublicados;

public:
	Desarrollador(string email, string contrasenia, string empresa);
	~Desarrollador();

	string getEmpresa();
	//OPERACIONES
	set<string> listarNombresVideojuegos();
	set<DtValorEstadistica*> mostrarEstadisticas(string nombreVid);
	friend ostream& operator<< (ostream& out, Desarrollador& d);
	void agregarVideojuegoPublicado(Videojuego* vj);
	void eliminarVideojuegopublicado(string nombre);
	map<string, Videojuego*> getVideojuegosPublicados();
	void agregarEstadistica(Estadistica* estadistica);
};

#endif

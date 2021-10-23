#include "../include/PartidaMultijugador.h"
#include "../include/DtPartidaMultijugador.h"
#include "../include/FechaHoraSistema.h"

PartidaMultijugador::PartidaMultijugador(
	int idPartida,
	DtFechaHora* fechaComienzo,
	Videojuego* videojuego,
	bool finalizada,
	string nicknameJugadorInicio,
	bool enVivo) :
	Partida(idPartida, fechaComienzo, videojuego, finalizada, nicknameJugadorInicio){
			this->enVivo = enVivo;
};

//SETTERS - GETTERS
void PartidaMultijugador::setEnVivo(bool enVivo) {

};

void PartidaMultijugador::setJugadoresUnidos(set<JugadorUnido*> jU) {
	this->jugadoresUnidos = jU;
}

void PartidaMultijugador::agregarJugadorUnido(JugadorUnido* ju) {
	this->jugadoresUnidos.insert(ju);
}

void PartidaMultijugador::setVideojuegoPerteneciente(Videojuego* videojuego) {
	this->videojuegoPerteneciente = videojuego;
	videojuego->getPartidas().insert({this->getIdPartida(), this});
};

bool PartidaMultijugador::getEnVivo() {
	return this->enVivo;
};

set<JugadorUnido*> PartidaMultijugador::getJugadoresUnidos(){
	return this->jugadoresUnidos;
};

//DESTRUCTOR
PartidaMultijugador::~PartidaMultijugador() {
	set<JugadorUnido*>::iterator it;
	for (it = jugadoresUnidos.begin(); it != jugadoresUnidos.end(); it++){
		delete *it;
	}
};

//OPERACIONES
DtInfoBasicaPartidaIndividual* PartidaMultijugador::obtenerInfoPartidaIndividual() {
	return NULL;
};

void PartidaMultijugador::setDatos(string nombreVideojuego) {
};

DtPartida* PartidaMultijugador::getDatosPartida() {

	int id = this->getIdPartida();
	DtFechaHora* fechaOriginal = this->getFechaComienzo();
	int dia, mes, anio, hora, minutos;
	dia = fechaOriginal->getDia();
	mes = fechaOriginal->getMes();
	anio = fechaOriginal->getAnio();
	hora = fechaOriginal->getHora();
	minutos = fechaOriginal->getMinuto();
	DtFechaHora* fechaComienzo = new DtFechaHora(dia, mes, anio, hora, minutos);
	string nombreVj = this->getVideojuego()->getNombre();

	bool esVivo = this->getEnVivo();
	int cant = 0;
	set<string> jugadoresUnidos;
	set<JugadorUnido*>::iterator it;
	for (it = this->jugadoresUnidos.begin(); it != this->jugadoresUnidos.end(); it++)
	{
		string nombre = ((*it)->getJugador())->getNickname();
		jugadoresUnidos.insert(nombre);
		cant++;
	}

	DtPartida *res = new DtPartidaMultijugador(id,fechaComienzo, 0, esVivo,cant,jugadoresUnidos, nombreVj);
	return res;
};

void PartidaMultijugador::borrarPartida(Jugador* jugadorPartida) {
	jugadorPartida->quitarPartidaIniciada(this->getIdPartida());
};

void PartidaMultijugador::finalizarPartida() {
	this->setFinalizada(true);
	FechaHoraSistema* fhs = FechaHoraSistema::getInstancia();
	DtFechaHora* fechaFinalizacion = fhs->getFechaHoraSistema();
	this->setFechaFinalizacion(fechaFinalizacion);
	DtFechaHora* fechaComienzo = this->getFechaComienzo();
	this->setDuracion((*fechaFinalizacion) - (*fechaComienzo));

	cout << "La partida duro " << (*fechaFinalizacion) - (*fechaComienzo) << " minutos\n";
	Videojuego* vj = getVideojuego();
	vj->restarCantPartidas();
	set<JugadorUnido*>::iterator it;
	for (it = this->jugadoresUnidos.begin(); it != this->jugadoresUnidos.end(); it++) {
		bool abandono = (*it)->getAbandono();
		if (!abandono) {
			(*it)->setDuracion((*fechaFinalizacion) - (*fechaComienzo));
		};
	};
};

bool PartidaMultijugador::jugadorUnido(string nicknameJugador) {
	bool unido = false;
	set<JugadorUnido*>::iterator it = this->jugadoresUnidos.begin();
	while (!unido && it != this->jugadoresUnidos.end())
	{
		JugadorUnido* ju = *it;
		if (ju->getNickname().compare(nicknameJugador) == 0) {
			unido = true;
		} else it++;		
	};

	return unido;
};

void PartidaMultijugador::abandonarPartida(string nicknameJugador) {
	bool unido = false;
	set<JugadorUnido *>::iterator it = this->jugadoresUnidos.begin();
	while (!unido && it != this->jugadoresUnidos.end())
	{
		JugadorUnido *ju = *it;
		if (ju->getNickname().compare(nicknameJugador) == 0) {
			unido = true;
			ju->abandonar(this->getFechaComienzo());
		}
		else it++;	
	};
};

void PartidaMultijugador::sacarJugadorDePartida(string nicknameJugador) {
	bool unido = false;
	set<JugadorUnido*>::iterator it = this->jugadoresUnidos.begin();
	while (!unido && it != this->jugadoresUnidos.end()) {
		JugadorUnido* ju = *it;
		if (ju->getNickname().compare(nicknameJugador) == 0) {
			unido = true;
			ju->setAbandono(true);
		} else it++;		
	};
};

bool PartidaMultijugador::jugadorAbandono(string nickname){
	bool unido = false;
	bool res = false;
	set<JugadorUnido*>::iterator it = this->jugadoresUnidos.begin();
	while (!unido && it != this->jugadoresUnidos.end())
	{
		JugadorUnido* ju = *it;
		if (ju->getNickname().compare(nickname) == 0) {
			unido = true;
			res = ju->getAbandono();
		} else it++;		
	};
	return res;
};

ostream& operator<< (ostream& out, PartidaMultijugador& pm){
	int id = pm.getIdPartida();
	string nombre = pm.getVideojuego()->getNombre();
	bool finaliz = pm.getFinalizada();
	bool enViv = pm.getEnVivo();
	DtFechaHora* fechaFinal = pm.getFechaFinalizacion();

	out << endl;
	out << "Partida multijugador creada:" << endl;
	out << "Id: " << id <<  endl;
	out << "Videojuego asociado: " << nombre << endl;
	out << "Fue finalizada: ";	
	if (finaliz) {
		out << "si" << endl;
		int dia, mes, anio, hora, minutos;
		dia = fechaFinal->getDia(); 
		mes = fechaFinal->getMes(); 
		anio = fechaFinal->getAnio(); 
		hora = fechaFinal->getHora(); 
		minutos = fechaFinal->getMinuto();
		out << "Fecha finalizacion: " << dia << "/" << mes << "/" << anio << ", " << hora << ":" << minutos << endl;
	}
	else
		out << "no" << endl;
	out << "Es transmitida en vivo: ";
	if (enViv) 
		out << "si" << endl;
	else
		out << "no" << endl;

    return out;
}
float PartidaMultijugador::darTotalHorasParticipantes() {
	float val = this->getDuracion();
	set<JugadorUnido*>::iterator it;
	for (it = this->jugadoresUnidos.begin(); it != this->jugadoresUnidos.end(); it++) {
		JugadorUnido* ju = *it;
		float horasJugador = ju->getDuracion(this->getFechaComienzo(), this->getFinalizada());
		val += horasJugador;
	};
	return val;
};

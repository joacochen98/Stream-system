#include "../include/PartidaIndividual.h"
#include "../include/FechaHoraSistema.h"
//CONSTRUCTOR
PartidaIndividual::PartidaIndividual(){
};

PartidaIndividual::PartidaIndividual(
	int idPartida,
	DtFechaHora* fechaComienzo,
	Videojuego* videojuego,
	bool finalizada,
	string nicknameJugadorInicio,
	bool continuaAnterior) :
	Partida(idPartida, fechaComienzo, videojuego, finalizada, nicknameJugadorInicio){
		this->continuaAnterior = continuaAnterior;
};

//SETTERS - GETTERS
void PartidaIndividual::setContinuaAnterior(bool continuaAnterior) {
	this->continuaAnterior = continuaAnterior;
};

void PartidaIndividual::setIdPartidaAnterior(int idPartidaAnterior) {
	this->idPartidaAnterior = idPartidaAnterior;
};

bool PartidaIndividual::getContinuaAnterior() {
	return this->continuaAnterior;
};

int PartidaIndividual::getIdPartidaAnterior() {
	return this->idPartidaAnterior;
};

void PartidaIndividual::setVideojuegoPerteneciente(Videojuego* videojuego) {
	this->videojuegoPerteneciente = videojuego;
};

//DESTRUCTOR
PartidaIndividual::~PartidaIndividual() {
	
};

//OPERACIONES
DtInfoBasicaPartidaIndividual* PartidaIndividual::obtenerInfoPartidaIndividual() {
	DtFechaHora* fechaOriginal = this->getFechaComienzo();
	int dia, mes, anio, hora, minutos;
	dia = fechaOriginal->getDia();
	mes = fechaOriginal->getMes();
	anio = fechaOriginal->getAnio();
	hora = fechaOriginal->getHora();
	minutos = fechaOriginal->getMinuto();
	DtFechaHora* fechaComienzo = new DtFechaHora(dia, mes, anio, hora, minutos);
	int identificador = this->getIdPartida();
	float duracion = this->getDuracion();
	DtInfoBasicaPartidaIndividual* res = new DtInfoBasicaPartidaIndividual(identificador, fechaComienzo, duracion);
	return res;
};

void PartidaIndividual::setDatos(Videojuego* videojuego, int idPartidaAnterior) {

};

DtPartida* PartidaIndividual::getDatosPartida() {
	DtPartida *res;
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

	bool continua = this->continuaAnterior;
	res = new DtPartidaIndividual(id,fechaComienzo, 0, continua, nombreVj);
	return res;
};

void PartidaIndividual::borrarPartida(Jugador* jugador) {
	jugador->quitarPartidaIniciada(this->getIdPartida());
};

void PartidaIndividual::finalizarPartida() {
	this->setFinalizada(true);
	FechaHoraSistema* fhs = FechaHoraSistema::getInstancia();
	DtFechaHora* fechaFinalizacion = fhs->getFechaHoraSistema();
	DtFechaHora* fechaComienzo = this->getFechaComienzo();
	this->setFechaFinalizacion(fechaFinalizacion);
	int dur = (*fechaFinalizacion) - (*fechaComienzo);
	this->setDuracion(dur);

	Videojuego* vj = getVideojuego();
	vj->restarCantPartidas();
};

ostream& operator<< (ostream& out, PartidaIndividual& pi){
	int id = pi.getIdPartida();
	string nombre = pi.getVideojuego()->getNombre();
	bool finaliz = pi.getFinalizada();
	bool cont = pi.getContinuaAnterior();
	int idAnterior = pi.getIdPartidaAnterior();

	out << endl;
	out << "Partida individual creada:" << endl;
	out << "Id: " << id <<  endl;
	out << "Videojuego asociado: " << nombre << endl;
	out << "Fue finalizada: ";
	if (finaliz) {
		out << "si" << endl;
		DtFechaHora* fechaFinal = pi.getFechaFinalizacion();
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
	out << "Continua otra partida: ";
	if (cont)
		out << "si" << endl;
	else
		out << "no" << endl;

    return out;
}
float PartidaIndividual::darTotalHorasParticipantes(){
	return this->getDuracion();
};

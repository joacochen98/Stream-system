#include "../include/JugadorUnido.h"
#include "../include/FechaHoraSistema.h"
using std::string;

//CONSTRUCTOR
JugadorUnido::JugadorUnido(){
};

JugadorUnido::JugadorUnido(Jugador* jugador){
 this->jugador = jugador;
 this->abandono = false;
 this->fechaAbandono = NULL;
 this->duracion = 0;
};

//SETTERS - GETTERS
void JugadorUnido::setAbandono(bool abandono){
  this->abandono = abandono;
};

void JugadorUnido::setFechaAbandono(DtFechaHora* fechaAbandono){
  this->fechaAbandono = fechaAbandono;
};

void JugadorUnido::setDuracion(float duracion){
  this->duracion = duracion;
};

void JugadorUnido::setJugador(Jugador* jugador){
  this->jugador = jugador;
};


bool JugadorUnido::getAbandono(){
  return this->abandono;
};

DtFechaHora* JugadorUnido::getFechaAbandono(){
  return this->fechaAbandono;
};

float JugadorUnido::getDuracion(DtFechaHora* fechaComienzo, bool partidaFueFinalizada){
  float res;
	if (abandono || partidaFueFinalizada){
		res = this->duracion;
  }
	else{
		FechaHoraSistema* fhs = FechaHoraSistema::getInstancia();
		DtFechaHora* fechaSistema = fhs->getFechaHoraSistema();
    int horas = fechaSistema->getHora() - fechaComienzo->getHora();
    int minutos = fechaSistema->getMinuto() - fechaComienzo->getMinuto();
		res = horas * 60 + minutos;
		delete fechaSistema;
	};
	return res;
};

Jugador* JugadorUnido::getJugador(){
  return this->jugador;
};

//DESTRUCTOR
JugadorUnido::~JugadorUnido(){
  if (this->abandono)
    delete this->fechaAbandono;
};

//OPERACIONES
Jugador* JugadorUnido::buscarJugadorUnido(string nickname) {
  Fabrica* fabrica = Fabrica::getInstancia();
  IUsuario* interfazUsuario = fabrica->getIUsuario();
	Jugador *res = interfazUsuario->buscarJugador(nickname);
	return res;
};

string JugadorUnido::getNickname(){
	string res = this->jugador->getNickname();
	return res;

};

void JugadorUnido::abandonar(DtFechaHora *fechaComienzo){
  this->setAbandono(true);
  FechaHoraSistema* fechaSistema = FechaHoraSistema::getInstancia();
  DtFechaHora* dtFechaSistema = fechaSistema->getFechaHoraSistema();
  this->setFechaAbandono(dtFechaSistema);
  this->setDuracion((*dtFechaSistema) - (*fechaComienzo));
};

ostream& operator<< (ostream& out, JugadorUnido& ju){
  string nombre = ju.getJugador()->getNickname();
  bool aband = ju.abandono; 
  DtFechaHora* fechaAban = ju.fechaAbandono;
  out << "Jugador unido: " << nombre << endl;
  out << "Abandono: ";
  if (aband) {
    out << "si" << endl;
    int dia, mes, anio, hora, minutos;
    dia = fechaAban->getDia(); 
    mes = fechaAban->getMes(); 
    anio = fechaAban->getAnio(); 
    hora = fechaAban->getHora(); 
    minutos = fechaAban->getMinuto();
		out << "Fecha abandono: " << dia << "/" << mes << "/" << anio << ", " << hora << ":" << minutos << endl;
  }
  else{
    out << "no" << endl;
  }

  return out;
};